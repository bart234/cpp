#include "sources.h"

namespace p_fabrik
{
    /*
    basic setup:
    -some basic class which we will make at background eg "bricks,steel,panel "
    -container- general one: eg"material"
    -class maker - it tak some arg, create container and with logic it put there some material
    -class which will use out maker - that class own material - so it execude class maker+parameter

    1th - there is a container class and dedicated classes 
          container class is for keep that dedicated classes, other classes works on cointeiner class
    2nd- we need class cointeiner class with some dedicated class which will me made behind 
         here we get some parameter and have logic to create dedicated class
         that class need virtual destructor because have to be destroyed and launch material class destructor
    3th- we create maker which will be use outside  
        can be empty , can be static but have to return pointer of container class filled by some content
    4th- we just starting to using that class maker
      
    */


    class MaterialContainer
    {
        protected:        
        std::string name_;

        public:
        MaterialContainer(){};
        virtual ~MaterialContainer(){};
        void printMe(){std::cout<<"This material is: "<<name_<<std::endl;}

        
    };

    class Rocks: public MaterialContainer
    {

        public:
            Rocks():MaterialContainer(){this->name_ ="Rocks";};
            ~Rocks(){}
                   
    };

    class Wood: public MaterialContainer
    {
        public:
            Wood():MaterialContainer(){this->name_ ="Wood";};        
    };
    

    class MaterialMaker
    {
        public:
        MaterialMaker(){};
        ~MaterialMaker(){};
        
        MaterialContainer* prepareMaterial(std::string material_to_create)
        {
            if(material_to_create=="Rocks")
                return new Rocks{};
            else if(material_to_create=="Wood")
                return new Wood();
            return nullptr;
        }
    };
    
    class Building
    {
        MaterialContainer* materialWhatMeProduceHere;
        std::string  buildingName;
        public:
        Building(std::string  in_buildingName):buildingName{in_buildingName}{};
        MaterialContainer* getMaterial(){return materialWhatMeProduceHere;};
        void printBuildingName(){cout<<"This building is: "<<buildingName<<endl;};

        void addOutputMaterial(std::string output_material_name)
        {
            MaterialMaker mm{};
            materialWhatMeProduceHere=mm.prepareMaterial(output_material_name);
        }

        ~Building()
        {
            delete materialWhatMeProduceHere;
            materialWhatMeProduceHere=nullptr;
        }
    };

    class SteelMill: public Building
    {
        public: 
        SteelMill():Building("Stell Mill"){};
        
    };
    
void test_small_1()
{
    MaterialContainer* myMaterial;
    MaterialMaker mm{};
    
    myMaterial=mm.prepareMaterial("Wood");
    myMaterial->printMe();
    //MaterialContainer* mc{new Rocks()};
    

    delete myMaterial;
    myMaterial=nullptr;
}

void run_me()
{
    //test_small_1();
    SteelMill sm{};
    sm.addOutputMaterial("Rocks");
    sm.printBuildingName();
    sm.getMaterial()->printMe();
    cout<<"end"<<endl;
}


}