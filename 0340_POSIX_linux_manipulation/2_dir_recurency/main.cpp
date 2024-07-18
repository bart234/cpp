#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <source_location>

using namespace std;

//test dir can be created on 0340:1_files_dirs_op_crud
namespace dir_recurency
{
    void dir_recurency_and_link_check()
    {
        const std::filesystem::path path_to_iterate ="test_dir";
        //for(auto const& temp: std::filesystem::directory_iterator{path_to_iterate})
        //    cout<<temp.path()<<endl;
        
        cout<<"Recursive iterator below\n";
        for(auto const& temp: std::filesystem::recursive_directory_iterator{path_to_iterate})
            {
                cout<<temp.path()<< " is sml: "<<(std::filesystem::is_symlink(temp.path())?1:0)<<endl;
            }
    }

    void remove_source_of_links_and_check_space()
    {
        if(std::filesystem::exists("test"))
        {
            std::filesystem::space_info space_obj = std::filesystem::space(std::filesystem::current_path());
            cout<<"Capacity: "<<space_obj.capacity<<endl;
            cout<<"Free: "<<space_obj.free<<endl;
            cout<<"Available: "<<space_obj.available<<endl;
            cout<<"-----------------------------"<<endl;

            std::filesystem::remove("test");

            space_obj = std::filesystem::space(std::filesystem::current_path());
            cout<<"Capacity: "<<space_obj.capacity<<endl;
            cout<<"Free: "<<space_obj.free<<endl;
            cout<<"Available: "<<space_obj.available<<endl;
            cout<<"-----------------------------"<<endl;
        }
        else
            std::cout<<"Test doesnt exist"<<std::endl;
    }
}

int main ()
{
    dir_recurency::dir_recurency_and_link_check();

    //you need path with some content here
    dir_recurency::remove_source_of_links_and_check_space();
    
    return 0;
}