#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
//https://www.geeksforgeeks.org/posix-shared-memory-api/
int main()
{
    //in bytes - size of thet shm mem object
    const int SIZE = 4096;
    //name of that shm mem object
    const char* name = "/POSIX_1";

    //stuff saved in shm memory
    const char* msg_1 = "Hello";
    const char* msg_2 = "Posix!";

    //we create descriptor - result after create shm mem obj
    int shm_file_descr;

    //ptr to shm mem obj
    void* ptr;

    shm_file_descr = shm_open(name,O_CREAT | O_RDWR,0666);

    //config- getting that shm size
    ftruncate(shm_file_descr, SIZE);

    //creating map in shm obj 
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_file_descr, 0);

    //saving our stuff to shm obj(in this case , stuff from this function)
    //printf(ptr, "%s", msg_1);
    
    ptr+= sizeof(msg_1);
    sprintf(ptr,"%s",msg_1);
    
    ptr+= sizeof(msg_2);
    sprintf(ptr,"%s",msg_2);
    
    return 0;
}