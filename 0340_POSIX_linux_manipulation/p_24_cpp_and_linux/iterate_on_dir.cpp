#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <source_location>


using namespace std;

namespace all_ctors
{   
    struct Mean_
    {
        friend std::ostream& operator<<(std::ostream& os, const Mean_& a);

        Mean_() = default;
        Mean_(Mean_&& a) noexcept
            {   
                sum =a.sum;
                count=a.count;
                //a.sum=0;
                //a.count=-1;
                std::cout<<"Move op"<<std::endl;
            }
        Mean_& operator=(Mean_&& a) noexcept
        {
            sum=a.sum;
            count=a.count;
            std::cout<<"Copy op"<<std::endl;
            return *this;
        }

        Mean_(const Mean_ & a) noexcept: sum{a.sum},count{a.count}
        {
            std::cout<<"Constr from assgin"<<std::endl;
        };

        public:
        double result{};
        double sum{};
        int count{};
        

        public:
        double wynik(){return sum/count;}
        void operator()(const double& val)
        {            
            this->sum +=val;
            ++this->count;
            std::cout<<"() op with val: "<< val<<std::endl;
        }
    };
/*
    std::ostream& operator<<(std::ostream& os, const Mean& a)
    {
        double m{std::nan("")};
        if(a.count >0)
        {
            m = a.sum / a.count;
        }
        os << m;
        return os;
    }
*/
    void make_ctor_on_structure()
    {
        Mean_ calc_mean;
        std::vector v1{1.0, 2.5, 4.0, 5.5};
        std::for_each(v1.begin(),v1.end(), std::ref(calc_mean));
        //std::for_each(v1.begin(),v1.end(), calc_mean); --it doesnt work, during copying it lost saved value
        std::cout<<"done"<<std::endl;
        std::cout<<"This mean value is: "<< calc_mean.sum<<'\n';

        
    }
}

namespace linux_pipes
{
    //#include <iostream>
    #include <unistd.h>
    #include <string.h>

    constexpr auto BUFF_LEN=64;
    constexpr auto pipeIn=0;
    constexpr auto pipeOut=1;

    void pipe_1()
    {
        int a_pipe[2]{};
        char buff[BUFF_LEN+1]{};
        if(pipe(a_pipe)== -1)
        {
            perror("Pipe creation failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            if(int pid = fork();pid==-1)
            {
                perror("Process creation failed 2");
                exit(EXIT_FAILURE);
            }
            else if(pid==0)
            {
                //child will be the readed
                sleep(1); //extra time
                close(a_pipe[pipeOut]);
                read(a_pipe[pipeIn],buff,BUFF_LEN);
                cout<<"Child: "<<buff<<endl;
            }
            else
            {
                //parent: will be the writer
                close(a_pipe[pipeIn]);
                const char* msg = {"Sending message to child!"};
                write(a_pipe[pipeOut],msg,strlen(msg)+1);
            }
        }
    }
}

namespace file_operations
{
    void create_files_dicts ()
    {
        //if(std::filesystem::is_directory("test_dir"))
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
                cout<<temp.path()<< " is sml: "<<
                (std::filesystem::is_symlink(temp.path())?1:0)<<endl;
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
    //file_operations::create_files_dicts();
    //dir_recurency::dir_recurency_and_link_check();
    //dir_recurency::remove_source_of_links_and_check_space();
    //linux_pipes::pipe_1();
    all_ctors::make_ctor_on_structure();
    
    return 0;
}