#include "sources.h"

namespace p_decorator
{
    /*
    dp designed to gather object together and inject one int another but still with same type
    all objects have same parent so we can treat them in one collection even they are in diffrent kind
    they do not bring new functionality, but by composition we just brought them together
    ofc they have some inherited and overriten functionality in definition but thats all
    what we need:
    - one parent who allow to keep diffrent kind of objects in on collection
    - childs all of kind     
    
    - in c++: one container  = one type , unsless it is pointer  to parent, so we keep there child (parent +additional functionality)
    */
   enum class coffie_size{NORMAL,MEDIUM,XXL};

   class StuffToSell
   {
    protected:
    std::vector<double>price{3,-1};
    std::string description_{"none"};
    int size{-1};

    public:
    std::vector<StuffToSell*> additionalStuff{};
    void printMe()
        { 
            std::string temp ={printDescription()};
            double result_price{getPrice(this->size)};
            if (additionalStuff.size() !=0)
                {
                    temp+=": ";
                    for(auto &el:additionalStuff)
                    {
                        temp += el->printDescription() +',' ; 
                        result_price += el->getPrice(this->size);
                    }
                    
                }
            cout<<temp<<endl;
            cout<<"Cost: "<<std::to_string(result_price)<<endl;
        }
    virtual std::string printDescription() =0;
    virtual double getPrice()=0;
    virtual double getPrice(int size_int)=0;

    public:
    void setPrice(double p){this->price.at(0)=p;};
    void setPrice(std::vector<double> v){this->price=v;};
    void setDescription(std::string d){this->description_=d;};
   };

   class Drink: public StuffToSell
   {        
        protected:
        std::string printDescription(){return description_;}
        double getPrice(){return price.at(0);}
        double getPrice(int size_int){return price.at(size_int);}
        void setSize(coffie_size a)
        {
        switch (a)
            {
                case coffie_size::NORMAL: this->size=0;break;
                case coffie_size::MEDIUM: this->size=1;break;
                case coffie_size::XXL: this->size=2;break;
            }
        }
   };

   class CoffeAmericano: public Drink
   {    
        public:
        CoffeAmericano(coffie_size c_size=coffie_size::MEDIUM)
        {
            this->setSize(c_size);
            this->setPrice({14.4,16.1,17.5});
            this->setDescription("Coffe Americano");
        };
   };
   class CoffeLatte: public Drink
   {
        CoffeLatte(coffie_size c_size=coffie_size::MEDIUM)
        {
            this->setSize(c_size);
            this->setPrice({18.99,21.5,24.0});
            this->setDescription("Coffe Latte");
        };
   };



   class Addons: public StuffToSell
   {
        protected:
        std::string printDescription(){return description_;}
        double getPrice(){return price.at(0);}
        double getPrice(int size_int){return price.at(size_int);}
   };

   class Sugar: public Addons
   {
    public:
        Sugar()
        {
            this->setPrice({0.2,0.2,0.3});
            this->setDescription("sugar");
        };
   };

   class Schocolade: public Addons
   {
    public:
        Schocolade()
        {
            this->setPrice({1.5,1.8,2.2});
            this->setDescription("schocolade");
        };
   };

 

    void run_me()
    {
        CoffeAmericano c1{coffie_size::XXL};
        Schocolade s1{};
        Sugar s2{};
        c1.additionalStuff.push_back(&s1);
        c1.additionalStuff.push_back(&s2);

        c1.printMe();
    }
} 