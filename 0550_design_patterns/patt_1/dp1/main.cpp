#include <iostream>
#include <vector>

using namespace std;

namespace Old_Way
{
    class Person
    {
        protected:
        std::string name;
        std::string second_name;
        std::string position_prefix;

        public:
        //used when we create some variable for that
        Person(const std::string &i_name, const std::string &i_second_name):
                        name{i_name},second_name{i_second_name}
                        {};        
                    
        virtual ~Person() = default;

        virtual void print_person(){cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<<endl;}        
        virtual void holyday_privilages()=0;
    };

    class Student: public Person
    {
        private:
        int year_at_school;
        std::string prefix = "STD";

        public:
        Student(const std::string &i_name,const std::string &i_second_name,int i_year_at_school):
                        Person{i_name,i_second_name},
                        year_at_school{i_year_at_school}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Student() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< "Year at school: "<<this->year_at_school<<endl;}       
        virtual void holyday_privilages(){cout<<"You can rest at summer holyday"<<endl;};

    };

    class Teacher: public Person
    {
        private:
        std::string class_assigned;
        std::string prefix = "TCH";

        public:
        Teacher(const std::string &i_name,const std::string &i_second_name,std::string i_class_assigned):
                        Person{i_name,i_second_name},
                        class_assigned{i_class_assigned}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Teacher() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< 
                                "Class assigned: "<<this->class_assigned<<endl;}       
        virtual void holyday_privilages(){cout<<"You can rest at summer holydays and 10 days in school year"<<endl;};
    };

    class Profesor: public Person
    {
        private:
        std::string class_assigned;
        std::string prefix = "PRF";

        public:
        Profesor(const std::string &i_name,const std::string &i_second_name,std::string i_class_assigned):
                        Person{i_name,i_second_name},
                        class_assigned{i_class_assigned}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Profesor() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< 
                                "Class assigned: "<<this->class_assigned<<endl;}       
        virtual void holyday_privilages(){cout<<"You can rest at summer holydays and 15 days in school year"<<endl;};
    };
    
    class Jantor: public Person
    {
        private:
        int focus_on_n_floor_to_clean;
        std::string prefix = "JTR";

        public:
        Jantor(const std::string &i_name,const std::string &i_second_name,int i_number_of_floor_to_focus_to_clean):
                        Person{i_name,i_second_name},
                        focus_on_n_floor_to_clean{i_number_of_floor_to_focus_to_clean}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Jantor() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< 
                                "Focused on floor: "<<this->focus_on_n_floor_to_clean<<endl;}       
        virtual void holyday_privilages(){cout<<"You have 26 days in year, but someone have to cover your duties"<<endl;};
    };    
    class Technician: public Person
    {
        private:
        double salary_per_h;;
        std::string prefix = "THN";

        public:
        Technician(const std::string &i_name,const std::string &i_second_name,double i_salary_per_h):
                        Person{i_name,i_second_name},
                        salary_per_h{i_salary_per_h}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Technician() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< 
                                "Intervention salary: "<<this->salary_per_h<<endl;}       
        virtual void holyday_privilages(){cout<<"We dont care"<<endl;};
    };
    
    class Guard: public Person
    {
        private:
        bool allow_to_posses_gun;
        std::string prefix = "GRD";

        public:
        Guard(const std::string &i_name,const std::string &i_second_name,bool i_allow_to_posses_gun=false):
                        Person{i_name,i_second_name},
                        allow_to_posses_gun{i_allow_to_posses_gun}
                        {
                            this->position_prefix = prefix;
                        };

        virtual ~Guard() = default;
        virtual void print_person()override {cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<< 
                                "Have a gun: "<<((this->allow_to_posses_gun==true)?"Yes":"No")<<endl;}       
        virtual void holyday_privilages(){cout<<"You have 26 days in year, but someone have to cover your duties"<<endl;};
    };

    /*
    "position_prefix" is not a nonstatic data member or base class of class "Old_Way::Student"
    https://www.reddit.com/r/cpp_questions/comments/isawz9/is_not_a_nonstatic_data_member_or_base_class_of/
    The short answer is, because they are members of the base class rather than the derived class, 
    you can't set them in the initializer list of the derived class. 
    
    */

    void main_OldWay_testing()
    {
        Student s1 {"Pawel","Olbin",3};
        Teacher t1{"Olga","Jozwik","23b"};
        Profesor p1{"Marian","Blaszczyk","3a"};
        Jantor j1{"Jakub","Olczyk",4};
        Guard g1{"Roman","Kubia",false};


        std::vector<Person*> v1;
        v1.push_back(&s1);
        v1.push_back(&t1);
        v1.push_back(&p1);
        v1.push_back(&j1);
        v1.push_back(&g1);

        for(const auto &el:v1)
        {
            el->print_person();
        }
              

    };

}

namespace New_way
{
    /*each job should have components  like 
                hr_info (job shortcut, full/half/intern, holyday info), 
                general_info (name, second name, age),                 
                teaching (subject list), technician)
    // because Edwart is our Jantor, but is also student
    // because Garry will be our Jantor and part time Guard
    // because we have teacher who is student in one class, teaching, and is beeing intern at one profesor( we need class like that)
    */
    class Job
    {
        private:
        std::string prefix;

        public:
        Job(std::string i_prefix):prefix{i_prefix}{};
        virtual ~Job()=default;

        virtual void getInfo()=0;
        virtual std::string getPrefix(){return this->prefix;};

    };

    class Student: public Job
    {
        private:
        int year_at_school;
        public:
        Student(int i_year_at_school):Job{"STD"},year_at_school{i_year_at_school}{};
        virtual ~Student()=default;

        virtual void getInfo(){std::cout<<"Job code: "<<this->getPrefix()<< "Year on school: "<< this->year_at_school<<endl;};
    };

    class Teacher: public Job
    {

    };

    class Profesor: public Job
    {

    };

    class HR_info
    {

    };



    class Person
    {
        protected:
        std::string name;
        std::string second_name;
        std::string position_prefix;
        Job *main_job;
        //HR_info *hr_info;
        //Job second_job;
        //Job third_job;


        public:
        //used when we create some variable for that
        Person(const std::string &i_name, const std::string &i_second_name,Job *i_main_job=nullptr):
                        name{i_name},second_name{i_second_name},main_job{i_main_job}{};        
                    
        virtual ~Person() = default;

        virtual void print_person(){cout<<"Person: "<<this->position_prefix<< " "<< this->name<< " " <<this->second_name<<endl;}        
        virtual void holyday_privilages();
    };

    void main_OldWay_testing()
        {
            Student s1{3};
            Person p1 {"Pawel","Olbin",&s1};


            //Teacher t1{"Olga","Jozwik","23b"};
            //Profesor p1{"Marian","Blaszczyk","3a"};
            //Jantor j1{"Jakub","Olczyk",4};
            //Guard g1{"Roman","Kubia",false};


            //std::vector<Person*> v1;
            //v1.push_back(&s1);
            //v1.push_back(&t1);
            //v1.push_back(&p1);
            //v1.push_back(&j1);
            //v1.push_back(&g1);

            /*for(const auto &el:v1)
            {
                el->print_person();
            }*/
                

        };

}

int main()
{
    Old_Way::main_OldWay_testing();
    New_way::main_NewWay_testing();

}