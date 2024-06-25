#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
private:
    int a;
public:
    Test():a{0}{cout<<"Test constructor: "<< a<<endl;};
    Test(int in_a):a{in_a}{cout<<"Test constructor: "<< a<<endl;};
    ~Test(){cout<<"Test destructor: "<< a<<endl;}
    int get_data ()const{return this->a;};

};


/*
Main ideea
console app will ask about numer of integers, 
ale after that in loop will ask for each o them
it will save it in Test class.
Test slass elements wil be saved at vector - viector will be 
handle as unique ptr, elements in vector will be shared ptrs
General funtions to greate:
-create vector - emoty
-print menu +ask about number of variables + get var +save them in vector
-display elements
*/


std::unique_ptr<std::vector<std::shared_ptr<Test>>> make_vector()
{
    //return std::unique_ptr<std::vector<std::shared_ptr<Test>>>(); --it doesnt work
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
    //return std::move(vec_1);
}

void print_menu(std::unique_ptr<std::vector<std::shared_ptr<Test>>> &ref_to_vector)
{
    int number_of_expected_v;
    
    cout<<"Number of expected variables:"<<endl;
    cin>>number_of_expected_v;
    for(int i =1;i<=number_of_expected_v;++i)
    {
        cout<<"Give me ["<< i << "] int:"<<endl;
        int temp;
        cin>>temp;
        //std::shared_ptr<Test> a = std::make_shared<Test>(temp);        
        //ref_to_vector->push_back(a);      
        ref_to_vector->push_back(std::make_shared<Test>(temp));
    }
    cout<<"Vector created!"<<endl;
}


int main () 
{
std::unique_ptr<std::vector<std::shared_ptr<Test>>>  v;
v= make_vector();
print_menu(v);

cout<<"t1"<<endl;
return 0;
}