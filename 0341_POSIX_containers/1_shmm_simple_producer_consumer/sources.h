#include <iostream>
#include <thread>
#include <array>
#include <mqueue.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <syncstream>
#include <semaphore.h>
#include <mutex>
#include <atomic>

//shmm
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string_view>
#include <sys/stat.h>



using namespace std::literals::chrono_literals;
using namespace std;
