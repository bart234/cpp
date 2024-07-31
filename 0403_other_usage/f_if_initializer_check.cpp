
#include <iostream>
#include <cstdlib>
using namespace std;

// if( initializer, check){
//    quite often - we have error here if there was a problem with initialization}
//else{ ... }

/*
//carefull on things like that, without 1th bracket you will get wierd behavior, and fd will not load
if
(
    (socket_file_descriptor = socket(AF_INET,SOCK_DGRAM,0))<0   
)
*/

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
