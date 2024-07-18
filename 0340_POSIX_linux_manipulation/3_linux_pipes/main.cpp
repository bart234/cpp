#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <source_location>

using namespace std;

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

int main ()
{
    linux_pipes::pipe_1();
    
    return 0;
}