#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
using namespace std;

namespace first_approach
{
    ////-------Ears shape

    ////-------Sounds --------
    class Sound
    {
        public:
        virtual void make_a_noise()=0;
    };

    class BarkWofWof: public Sound
    {
        public:
        virtual void make_a_noise()override{std::cout<<"Sound: Wof Wof"<<std::endl;};        
    };

    ////-------Main object ---
    class Dog
    {
        std::string name;
        protected:
            Sound *dog_sound{nullptr};

        public:
            Dog(std::string i_name):name{i_name}{};
            virtual ~Dog(){};

            virtual void getName(){std::cout<<"My name is: "<<name<<std::endl;};
            virtual void getSound(){dog_sound->make_a_noise();};
    };

    class Wolf: public Dog
    {
        public:
        Wolf(std::string i_name):Dog{i_name}
        {
            dog_sound = new BarkWofWof();
        };
        
        virtual ~Wolf(){};

    };

    void test_first_appr()
    {
        cout<<"-------------test_first_appr--------------"<<endl;
        Dog *d1 = new Wolf("Alex");
        d1->getName();
        d1->getSound();
    }
}

namespace first_approach_additional_elements
{
    ////-------Ears shape

    ////-------Sounds --------
    class Sound
    {
        public:
        virtual void make_a_noise()=0;
    };

    class BarkWofWof: public Sound
    {
        public:
        virtual void make_a_noise()override{std::cout<<"Sound: Wof Wof"<<std::endl;};        
    };

    class BarkHauHauHau:public Sound
    {
        public:
        virtual void make_a_noise()override{std::cout<<"Sound: Hau Hau Hau"<<std::endl;};
    };

    ////-------Main object ---
    class Dog
    {
        std::string name;
        protected:
            Sound *dog_sound{nullptr};

        public:
            Dog(std::string i_name):name{i_name}{};
            virtual ~Dog(){};

            virtual void getName(){std::cout<<"My name is: "<<name<<std::endl;};
            virtual void getSound(){dog_sound->make_a_noise();};
    };

    class Wolf: public Dog
    {
        public:
        Wolf(std::string i_name):Dog{i_name}
        {
            dog_sound = new BarkWofWof();
        };
        
        virtual ~Wolf(){};

    };

    class Husky: public Dog
    {
        public:
        Husky(std::string i_name):Dog(i_name)
        {
            dog_sound = new BarkHauHauHau();
        };
        virtual ~Husky(){};
    };

    void test_first_appr()
    {
        
        Dog *d1 = new Wolf("Alex");
        d1->getName();
        d1->getSound();
        std::cout<<std::endl;

        Dog *h1= new Husky("Bora");
        h1->getName();
        h1->getSound();
        std::cout<<std::endl;
    }
}

namespace first_approach_with_additional_elements
{
    //equire <sstream>
    ////-------Ears shape

    ////-------Sounds --------
    class Sound
    {
        public:
        virtual void make_a_noise()=0;
    };

    class BarkWofWof: public Sound
    {
        public:
        virtual void make_a_noise()override{std::cout<<"Sound: Wof Wof"<<std::endl;};        
    };

    class BarkHauHauHau:public Sound
    {
        public:
        virtual void make_a_noise()override{std::cout<<"Sound: Hau Hau Hau"<<std::endl;};
    };

    ////-------Main object ---
    class Dog
    {
        std::string name;
        protected:
            Sound *dog_sound{nullptr};
            int age;

        public:
            Dog(std::string &i_name):name{i_name}{};
            virtual ~Dog(){};

            virtual void getName()const {std::cout<<"My name is: "<<name<<std::endl;};
            virtual void getSound()const {dog_sound->make_a_noise();};
            virtual void getAdditionalDetails()const{std::cout<<"There is no additional information"<<std::endl;};
    };

    class Wolf: public Dog
    {
        public:
        Wolf(std::string i_name):Dog{i_name}
        {
            dog_sound = new BarkWofWof();
        };
        
        virtual ~Wolf(){};
    };

    class Husky: public Dog
    {
        public:
        Husky(std::string i_name):Dog(i_name)
        {
            dog_sound = new BarkHauHauHau();
        };
        virtual ~Husky(){};
    };

    class Daschshund: public Dog
    {
        int length;
        public:
        Daschshund(std::string i_name,int i_length=0):Dog{i_name},length{i_length}
        {
            dog_sound = new BarkHauHauHau();
        }
        virtual ~Daschshund(){};

        virtual void getAdditionalDetails()const override
        {
            std::string out_str;       
            std::ostringstream oss{};
            if(this->length==0)
            {oss <<"My length is: "<< " not set "<<std::endl;}
            else
            {oss <<"My length is: "<<this->length <<" cm"<<std::endl;}
            cout<<oss.str()<<endl;
        };  
    };

    void test()
    {        
        Dog *d1 = new Wolf("Alex");
        d1->getName();
        d1->getSound();
        std::cout<<std::endl;

        Dog *h1= new Husky("Bora");
        h1->getName();
        h1->getSound();
        h1->getAdditionalDetails();
        std::cout<<std::endl;

        Dog *dsh1 = new Daschshund("Kora",56);
        dsh1->getName();
        dsh1->getSound();
        dsh1->getAdditionalDetails();
    }
}

namespace first_approach_physical_elements
{
    //equire <sstream>
    ////-------phisical elements
        class Physical_elements
        {
            //wrong
            private:
            int heigth;
            int length;
            int age;
            std::string &color;

            public:
            virtual int getHeigth()const                  {return this->heigth;};
            virtual int getLength()const                  {return this->heigth;};
            virtual const std::string &printColor() const   {return this->color;};
            //virtual int printAge() const                    {return this->age;};
            virtual void showDetails()=0;
            
            Physical_elements(int i_height, int i_length,std::string i_color):
                                heigth{i_height},length{i_length},color{i_color}
                                {};
            //Physical_elements(int i_h, int i_l, int i_a, std::string i_c):
            //                heigth{i_h},length{i_l},age{i_a},color{i_c}
            //                {};
            virtual ~Physical_elements(){};
        };
        /*
        class Physical_details: public Physical_elements
        {
            public:
            Physical_details(int i_heigth=-1,int i_length=-1,int i_age=-1, std::string i_color="none"):
                            Physical_elements{i_heigth,i_length,i_age,i_color}{};   
            Physical_details(int i_heigth=-1,int i_length=-1,int i_age=-1, std::string i_color="none")
                            {
                                heigth=i_heigth;
                                length=i_length;
                                age=i_age;
                                color=i_color;
                            }
                            
            virtual void shoDetails(){};
        };
        */

        
        class Physical_details_known: public Physical_elements
        {
            public:
            Physical_details_known(int i_height, int i_length,std::string i_color):
                    Physical_elements{i_height,i_length,i_color}{};
            virtual ~Physical_details_known(){};
            virtual void showDetails(){};
        };
    
        void test_new_element()
        {
            //Physical_details_unknown *pd = new Physical_details_unknown();        
            //Physical_elements *a  = new Physical_details_unknown(23,11,"Black");
        }
    
    ////-------Sounds --------
    
        class Sound
        {
            public:
            virtual void make_a_noise()=0;
        };

        class BarkWofWof: public Sound
        {
            public:
            virtual void make_a_noise()override{std::cout<<"Sound: Wof Wof"<<std::endl;};        
        };

        class BarkHauHauHau:public Sound
        {
            public:
            virtual void make_a_noise()override{std::cout<<"Sound: Hau Hau Hau"<<std::endl;};
        };
    
    ////-------Main object ---
    class Dog
    {
        std::string name;
        protected:
            Sound *dog_sound{nullptr};
            Physical_elements *physical_elements{nullptr};
            int age;
        
        private:
            //bool check_if_sound_availible(){return dog_sound!=nullptr;}

        public:
            Dog(std::string &i_name):name{i_name}{};
            virtual ~Dog()
                {
                    delete dog_sound;
                    delete physical_elements;
                };

            virtual void getName()const {std::cout<<"My name is: "<<name<<std::endl;};
            virtual void getSound()const 
                {
                    if(dog_sound)
                        {dog_sound->make_a_noise();}
                    else
                        {std::cout<<"Sound component error: sound no set"<<std::endl;}
                };
            virtual void getPhysicalDetails_weigth_length()
                {
                    if(physical_elements)
                        {std::cout<<"My heigth is "<< physical_elements->getHeigth()<<"  and "<<
                                    "my length is "<<physical_elements->getLength()<<std::endl;}
                    else
                        {std::cout<<"Physical details component error: physical details no set"<<std::endl;}
                };

            virtual void getAdditionalDetails()const{std::cout<<"There is no additional information"<<std::endl;};
    };

    class Wolf: public Dog
    {
        public:
        /*Wolf(std::string i_name):Dog{i_name}
        {
            dog_sound = new BarkWofWof();
            
        };*/
        
        //why it doesnt work - 
        // solution: constr: Wolf(std::string i_name):Dog{i_name} and below are this same

        Wolf(std::string i_name, 
            Sound *i_sound=nullptr, 
            Physical_elements *i_physical_elements = nullptr
            ):
                Dog{i_name}
                {
                    dog_sound = i_sound;
                    physical_elements = i_physical_elements;
                }
        
        
        virtual ~Wolf(){};
        
    };

    class Husky: public Dog
    {
        public:
        Husky(std::string i_name):Dog(i_name)
        {
            dog_sound = new BarkHauHauHau();
        };
        virtual ~Husky(){};
    };

    class Daschshund: public Dog
    {
        int length;
        public:
        Daschshund(std::string i_name,int i_length=0):Dog{i_name},length{i_length}
        {
            dog_sound = new BarkHauHauHau();
        }
        virtual ~Daschshund(){};

        virtual void getAdditionalDetails()const override
        {
            std::string out_str;       
            std::ostringstream oss{};
            if(this->length==0)
            {oss <<"My length is: "<< " not set "<<std::endl;}
            else
            {oss <<"My length is: "<<this->length <<" cm"<<std::endl;}
            cout<<oss.str()<<endl;
        };  
    };
  

    void test()
    {        
        
        Dog *d1 = new Wolf("Alex");
        d1->getName();
        d1->getSound();
        std::cout<<std::endl;

        Dog *d2 = new Wolf{"Romek",new BarkHauHauHau()};
        d2->getName();
        d2->getSound();
        d2->getPhysicalDetails_weigth_length();
        std::cout<<std::endl;

        Dog *d3 = new Wolf{"Abi",new BarkWofWof(),new Physical_details_known(10,12,"Red")};
        d3->getName();
        d3->getSound();
        d3->getAdditionalDetails();
        d3->getPhysicalDetails_weigth_length();
        
        
        std::cout<<std::endl;
        
        Dog *h1= new Husky("Bora");
        h1->getName();
        h1->getSound();
        h1->getAdditionalDetails();
        std::cout<<std::endl;

        Dog *dsh1 = new Daschshund("Kora",56);
        dsh1->getName();
        dsh1->getSound();
        dsh1->getAdditionalDetails();
        
    }
}

int main()
{
    //base elements to check how its work
    //first_approach::test_first_appr();

    //not too much new, new sound, new dog
    //first_approach_additional_elements::test_first_appr();

    //here i added new dog with additional parameter at constructor
    //length in daschshund will be printed or will be "not set"
    // length is implementad as "getAdditionalInfo" in base Dog class
    //with default version in Base- in that solution  dogs like Wolf and Husky
    //not require to change it code (additional info is not a virtual f) 
    //but it might be use if necessery in that classes
    //first_approach_with_additional_elements::test();

    /*
    -Physical elements added
    - physical elements have constructors with arguments
    - psyh_e added to Dog
    - Wolf was modified, constructore was remade to cover
        optionallity of adding components 
    -dog class: if sound will be used, but not declared - info will be printed
    */
    //first_approach_physical_elements::test_new_element();
    first_approach_physical_elements::test();
    

    cout<<"-------------File end--------------"<<endl;
    return 0;
}