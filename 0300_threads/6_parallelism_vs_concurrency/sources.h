#include <iostream>
#include <pthread.h>
#include <mutex>
#include <sys/wait.h>
#include <vector>
#include <stdlib.h>

#define THREAD_NUM 2
int arr[15] = {1,21,22,1,12,45,2,434,2,4};