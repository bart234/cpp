#ifndef SOURCES_H
#define SOURCES_H
#include "sources.h"
#endif

namespace parallel_struct_passed_copy_corrected_from_yt_try4
{
    void *worker(void *arg)
    {
        int index = *(int*)arg;
        int sum =0;
        sleep(1);
        for(int j=0;j<5;j++){
            sum+=arr[index+j];
        }
        printf("Local sum at worker: %d \n",sum);
        *(int*)arg=sum;
        return arg;
    }

    int main()  
    {
        
        pthread_t th_list[THREAD_NUM];
        int i;
        for(i=0; i<THREAD_NUM;i++){
            int *a = new int;
            *a=i*5;
            if(pthread_create(&th_list[i],NULL,&worker,a)){perror("Failed to create thread");}
        }
        int globalSum=0;
        
        for(i=0; i<THREAD_NUM;i++){
            
            int*r;
            if(pthread_join(th_list[i],(void**) &r) !=0){perror("Failed to join thread");}
            globalSum +=*r;
            free(r);
        }
        printf("Global sum %d", globalSum);
        //delete a;
    }
}