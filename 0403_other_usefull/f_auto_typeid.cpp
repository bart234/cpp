#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    auto my_int{3};
    auto my_int_list= {1,2,3};

    auto my_lambda = [&](){return my_int;};

    
    auto viki_i = std::vector<int>{1,2,3};



    std::map<std::string, int> my_map;
    my_map.emplace(std::pair("abba",1));
    my_map.emplace(std::pair("beta",2));

    for(std::map<std::string, int>::const_iterator it = my_map.cbegin(); it != my_map.cend(); it++)
    {
        cout<<it->first<<endl;
    }

    for(auto it = my_map.cbegin(); it != my_map.cend();it++)
    {
        cout<<it->first<<endl;
    }


    cout<<typeid(my_int).name()<<endl;
    

    auto m1 = "a";
    auto m2 = 'a';
    //cout<<typeid(my_lambda).name()<<endl;
    cout<<typeid(m1).name()<<endl;      //->PKc
    cout<<typeid(m2).name()<<endl;      //->c

    


}