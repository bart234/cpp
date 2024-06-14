#include "sources.h"

namespace p_template
{
    /*
    general idee:
    use to gather similar processes in one class, to avoid code redudancy
    parent class contain general process which is same in each child class (child inherit it)
    however that general process have smaller processes which are diffrent in each child class
    so parent class have function which have to be overriden (=0) with child implementations
    and some which can be overriten (additionalStep_1) - child can override it but dont have to   
    That allow to create general process template (coldDrink cls) and if you need another drink, you just
    have to create newDrink:ColdDrink, override necesseary elements and you have new product
    
    */

    class ColdDrink
    {
        private:
            bool with_dedication;
            std::string dedication_name;
        public:
        void prepareDrink()
        {

            gatherIngridients();
            additionalStep_1();         //used only in some class- overriten wher needed
            prepareIngridients();
            mixIt();
            prepareToDrink();
            cout<<"end"<<endl;
        }

        virtual void gatherIngridients(){cout<<"...gathering resources..."<<endl;};
        virtual void prepareIngridients()=0;
        virtual void additionalStep_1(){};
        virtual void mixIt(){cout<<"...mix it..."<<endl;};
        virtual void prepareToDrink()=0;

        bool dedicationRequired()


    };

    class SmoothDedicationCarrot: public ColdDrink
    {
        public:
        //void gatherIngridients(){};

        void additionalStep_1()
        
        void prepareIngridients(){cout<<"..cut Carrots and Apples..."<<endl;};
        //virtual void cutWegetables();

        //void mixIt(){};
        
        void prepareToDrink(){cout<<"..pourIntoGlass..."<<endl;};
        //void pourIntoGlass();
    };

    class SmootheGreen: public ColdDrink    //raw overwrite =0
    {
        
        public:
        //void gatherIngridients(){};

        
        void prepareIngridients(){cout<<"..cutWegetables..."<<endl;};
        //virtual void cutWegetables();

        //void mixIt(){};
        
        void prepareToDrink(){cout<<"..pourIntoGlass..."<<endl;};
        //void pourIntoGlass();
    };

    class IceShake: public ColdDrink    //overriten =0 + common dummy methhod
    {
        //void gatherIngridients();

        void additionalStep_1()override {cout<<"..additional step: close freezer..."<<endl;};

        void prepareIngridients() {cout<<"..crushIce..."<<endl;};
        //virtual void crushIce();

        //void mixIt();

        void prepareToDrink(){cout<<"..bringSpoon..."<<endl;};
        //void bringSpoon();
    };

    void run_me()
    {
        SmootheGreen sg{};
        sg.prepareDrink();

        IceShake i_s{};
        i_s.prepareDrink();

    }
}