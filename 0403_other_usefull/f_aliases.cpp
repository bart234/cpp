#include <iostream>
#include <vector>
#include <map>

using namespace std;

using viki_i = std::vector<int> ;
using viki_str = std::vector<std::string>;
using map_str_i = std::map<std::string, int>;

/*
use aliases  are equivalent of typedef
*/





int main()
{

    auto my_int{3};
    viki_i my_int_list= {1,2,3};
    my_int_list.push_back(4);
    

    auto my_lambda = [&](){return my_int;};


    map_str_i my_map;
    my_map.emplace(std::pair("abba",1));
    my_map.emplace(std::pair("beta",2));

    //for(std::map<std::string, int>::const_iterator it = my_map.cbegin(); it != my_map.cend(); it++)
    for(map_str_i::const_iterator it = my_map.cbegin(); it != my_map.cend(); it++)
    {
        cout<<it->first<<endl;
    }

}