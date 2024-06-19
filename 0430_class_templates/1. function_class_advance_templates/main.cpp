#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


namespace FuncitonTemplates_in_use
{
            template <typename T>
            int sum_me(T el_1, T el_2){return (el_1+el_2);}

            template <typename T, typename Y>
            Y sum_me2(T el_1, Y el_2){return (el_1+el_2);}

            template<typename T>
            int func_bigger(T el_1,T el_2){return (el_1>el_2)?el_1:el_2;}

    void simple_usage_of_funciton_tempaltes()
    {
        cout<<FuncitonTemplates_in_use::sum_me(4,6)<<endl;
        cout<<FuncitonTemplates_in_use::sum_me<int>(4,6)<<endl;
        cout<<FuncitonTemplates_in_use::sum_me2(4.4,6.0)<<endl;
        cout<<FuncitonTemplates_in_use::func_bigger(11,10)<<endl;
        cout<<FuncitonTemplates_in_use::func_bigger(11+4,10*2)<<endl;
    }

    /*--------------------------------------------------------------------*/
    /*--------------------------------------------------------------------*/
    /*--------------------------------------------------------------------*/
    /*--------------------------------------------------------------------*/

            struct Person
            {
                std::string name;
                int age;
                bool operator<(const Person &rhs)const
                {
                    return this->age<rhs.age;
                }
            };

            std::ostream &operator<<(std::ostream &os,const Person &p)
            {
                os<<p.name;
                return os;
            }

            //template used on custom class and function, it require to override operator because function compare it
            template<typename MyType>
            MyType select_min(MyType el_1, MyType el_2)
                {
                    return (el_1<el_2)?el_1:el_2;
                }

    void user_defined_class_on_template_and_compare_it()
    {
        Person dave{"Dave",45};
        Person hans{"Hans",43};
        
        Person result = select_min<Person>(dave,hans); //we cant compile it until we override "<""
        cout<<result.name<< " is younger, have "<<result.age<<" years"<<endl;
    }
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------

            template<typename MyType_1, typename MyType_2>
            void print_me(MyType_1 a, MyType_2 b)
            {
                std::cout<<"My two elements: " <<a<< " "<<b<<std::endl;
            }

    void system_defined_types_compared_on_template_function()
    {
        print_me(2,4);
        print_me("Bartek",4);
        print_me('A',"Bartek");
        Person pan{"Pan",23};
        print_me("Abba",pan);   //in that case Person is not overriden - compiler dont know what to print, because we didnt overload << operator
    }
}


namespace TemplateClass_in_use
{
            template<typename T>
            class Item
            {
                private:
                std::string name;
                T value;
                public:
                    Item(std::string i_name, T i_value):name{i_name},value{i_value}{};
                    std::string get_name(){return this->name;}
                    T get_value(){return this->value;}
                
            };

    void Game_Item_Creation_Template_Class()
    {
        Item<int> sword{"Sword",22};
        cout<<sword.get_name()<< " "<< sword.get_value()<<endl;

        Item<Item<int>> nested_1{"abba",{"beta",8}};

        cout<<"lvl1: "<<nested_1.get_name()<< " "<< "nested_1.get_value()"<<endl; //valu in that case is Item so if we dont have << for Item it will crash
        cout<<"lvl1-value: lvl2-name: "<<nested_1.get_value().get_name()<< " "<< endl; 
        cout<<"lvl1-value: lvl2-value: "<<nested_1.get_value().get_value()<< " "<< endl; 
    }

    /*-------------------------------------------------------------*/
    /*-------------------------------------------------------------*/
    /*-------------------------------------------------------------*/
    /*-------------------------------------------------------------*/

            template<typename A, typename B>
            struct MyPair
            {
                A item_1;
                B item_2;
            };

    void STL_Struct_for_two_temlpate_objects()
    {
        MyPair<std::string,double> a1{"Abba",12};
        MyPair<std::string,double> a2{"Beta",14};
        MyPair<std::string,Item<int>> b_1{"My item",{"Sword",22}};
        MyPair<std::string,Item<int>> b_2{"My item",{"Bow",34}};

        vector<MyPair<std::string,Item<int>>> viki_items;
        viki_items.push_back(b_1);
        viki_items.push_back(b_2);

        cout<<"first is item_1 - std::string, item_2 is Item"<<endl;
        for(auto &i:viki_items)          //with const it will not work
        {   
            cout<<i.item_1<<" "<<i.item_2.get_name()<<" "<<i.item_2.get_value()<<endl;
        }
    }
}

namespace TemplateClass_in_use_MyArr
{
    //Non type template parameters    
    //use: MyArr<5> arr;
    
    template<int N_1>  //LOOK HERE there is a int , not typename - we already declare type, we just expect value, not type
    class MyArr
    {
        private:    
            int size{N_1};
            int values[N_1];
        
        friend std::ostream &operator<<(std::ostream &os, const MyArr<N_1> &arr)
        {
                os<<"[";
                for (const auto &el: arr.values) //<- erro
                    {os<<el<<" ";}
                os<<"]"<<std::endl;
                return os;
        }
        
        public:
            MyArr() =default;   //default array have fix size, so size of them must be known before run-time, so we have to put it in compile-time
            MyArr(int init_val)
            {
                for(auto &items:values)
                {
                    items=init_val;
                }
            }
            void fill(int val)
                {for(auto &el:values){el=val;}}
            
            int get_size()const{return size;}

            //overloading subscript operator to get easy access to item from index
            int &operator[](int index){return values[index];}

    };

    void array_template_with_number_in_tempalte()
    {
        MyArr<5> arr_1;
        cout<<arr_1<<endl;
    }    
}


namespace AdvanceTemplateClass_trains
{   
    template<typename TrainTemplate> 
    class Train
    {
        protected:
            int year{};
            std::string name{};
        public:
            Train(std::string n):name{n}{};
        
        void getInfo(){static_cast<TrainTemplate*>(this)->print_me();};
        void print_me(){std::cout<<"This is my base Train class-override me"<<std::endl;};

        void setYear(int y){static_cast<TrainTemplate*>(this)->set_year(y);};
        void set_year(int y){this->year;std::cout<<"Year set in Train class cls-override me"<<std::endl;};
    };

    class Pesa: public Train<Pesa>
    {
        public:
            Pesa(std::string n):Train<Pesa>(n){};
            void print_me(){std::cout<<"THis is PEASA child class named: "<<this->name<<std::endl;};
            void set_year(int y){this->year=y; std::cout<<"Year set: "<<y<<" in PESA cls"<<std::endl;}
    };

    class Newag: public Train<Newag>
    {
        public:
        Newag(std::string n):Train<Newag>(n){};

    };

    void run_me_pesa_newag_cls_template()
    {
        Train<Pesa> new_train("PESA 34GA");
        new_train.getInfo();
        new_train.set_year(2022);       //i see here setYear adn set_year

        Train<Newag> newag_1("Newag B22");
        newag_1.print_me();
    };


}

int main()
{   

    //FuncitonTemplates_in_use::simple_usage_of_funciton_tempaltes();
    //FuncitonTemplates_in_use::user_defined_class_on_template_and_compare_it();      //and overriding < operator in Person class
    //FuncitonTemplates_in_use::system_defined_types_compared_on_template_function(); //and overriding << operator in Person class

    //TemplateClass_in_use::Game_Item_Creation_Template_Class();
    //TemplateClass_in_use::STL_Struct_for_two_temlpate_objects();

    TemplateClass_in_use_MyArr::array_template_with_number_in_tempalte(); //arr of unexpected bh, print to fix

    //AdvanceTemplateClass_trains::run_me_pesa_newag_cls_template();
    return 0;

}