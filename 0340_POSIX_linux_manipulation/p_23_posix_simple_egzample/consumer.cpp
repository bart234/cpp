
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    //in bytes - size of thet shm mem object
    const int SIZE = 4096;
    //name of that shm mem object
    const char* name = "POSIX_1";
    //we create descriptor - result after create shm mem obj
    int shm_file_descr;

    //ptr to shm mem obj
    void* ptr;

    //connect to created shm obj
    shm_file_descr = shm_open(name,O_RDONLY,0666);
    
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_file_descr, 0);
    printf("%s","Result");
    printf("%s",(char*)ptr);

    shm_unlink(name);
    return 0;
}
