#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/time.h>
#include <atomic>

static std::atomic_bool continue_execution{true};
using namespace std;

int main()
{
    struct sigaction signal_action_container{};
    //it is called only when time expire
    signal_action_container.sa_handler = [](int sig_number){
                                                                cout<<"Timer expired. Stopping task."<<endl;
                                                                continue_execution=false;
                                                            };

    sigemptyset(&signal_action_container.sa_mask);

    signal_action_container.sa_flags =0;

    sigaction(SIGALRM, &signal_action_container, nullptr);

    //Configure timer to trigger every 1 sec

    struct itimerval timer{
                            .it_interval{.tv_sec{1}, .tv_usec{0}},
                            .it_value{.tv_sec{1}, .tv_usec{0}}
                            };

    //start timer
    setitimer(ITIMER_REAL, &timer, nullptr);

    cout<<"Time started, waiting for expiration"<<endl;

    while(continue_execution)
    {
        sleep(1);
    }

    return 0;
                                            
}


