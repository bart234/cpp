bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr))

-2nd parameter ??? recast?

------------------------------------------
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
   srand(time(NULL));
   // C++17 if statement with initializer
   if (int random_num = rand(); random_num % 2 == 0) {
      cout << random_num << " is an even number\n";
   } else {
      cout << random_num << " is an odd number\n";
   }
   return 0;
}

if with initializer
------------------------------------------

array<char,BUF_SIZE> buffer_arr_for_data{}; - what is description ->  buffer_arr_for_data.data()
------------------------------------------

if
(
    (socket_file_descriptor = socket(AF_INET,SOCK_DGRAM,0))<0   //carefull on things like that, withaout 1th bracket you will get wierd behavior
)
------------------------------------------
https://cpp0x.pl/dokumentacja/standard-C/malloc/102

-----------------------------------------
fd - definition, what is excactly that?