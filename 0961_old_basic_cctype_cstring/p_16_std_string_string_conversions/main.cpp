#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    std::string a{"12"};
    std::string b {"45"};

    cout<<a+b<<endl;
    auto c{a+b};
    cout<<"Substr"<<endl;
    cout<<c.substr(2,2)<<endl;

    cout<<"\nFind -and find "<<endl;
    cout<<c.find('4',1)<<endl;
    cout<<"Find -and not find "<<endl;
    cout<<c.find('8',1)<<endl;
    cout<<"Find -and not find- compare with string::npos "<<endl;
    cout<<(c.find('8',1)==std::string::npos?"npos in action":"i found")<<endl;

    //string conversion - StringTONumber
    int some_int {stoi({" 324"})};
    cout<<"\nsimple str to num, printed below"<<endl;
    cout<<some_int<<endl;


    std::string str_with_num_to_convert {" 324Abba"};
    std::size_t container_to_some_noncovnertable_elemtns {};    

    int some_int_2 {std::stoi(str_with_num_to_convert,&container_to_some_noncovnertable_elemtns)};

    cout<<"\nsimple str to num, printed below, with prt to uncoverted elemtns"<<endl;
    cout<<"Basic string: " ;
    cout<<"--spacer--"<<str_with_num_to_convert<<"--spacer--"<<endl;
    cout<<"Extracted number: " ;
    cout<<some_int_2<<endl;
    cout<<"Index of first unconv element: " ;
    cout<<container_to_some_noncovnertable_elemtns<<endl;
    cout<<"Element itself: ";
    cout<<str_with_num_to_convert[container_to_some_noncovnertable_elemtns]<<endl;

    return 0;
}
