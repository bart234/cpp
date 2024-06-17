#include <iostream>
#include <vector>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>  
#include <ctime>
#include <array>
#include <mutex>        
#include <atomic>
#include <string>
//shmm
#include <cstring>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string_view>
#include <sys/stat.h>


using namespace std::literals::chrono_literals;     //require ...mutex lib
using namespace std;
