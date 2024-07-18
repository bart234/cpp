#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <source_location>

using namespace std;

namespace file_operations
{
    void create_files_dicts ()
    {
        if(std::filesystem::exists("test_dir"))
        {
            cout<<"Dir already exist\n";
            cout<<"And we will fill it up\n";
            std::filesystem::create_hard_link("test","test_dir/test_hl");
            std::filesystem::create_symlink("test","test_dir/test_symlink");
        }
        else
        {
            auto result = std::filesystem::create_directory("test_dir");
            if(result)
            {
                cout<<"Dictionary created successfully\n"<<endl;
                auto result2 = std::filesystem::create_directory("test_dir/sub_test_dir");
                if(result2)
                    cout<<"Dictionary created successfully\n"<<endl;
                else
                    cout<<"Dictionary creation failed\n";
            }
            else
                cout<<"Dictionary creation failed\n";
        }
    }
}

int main ()
{
    file_operations::create_files_dicts();
    
    return 0;
}