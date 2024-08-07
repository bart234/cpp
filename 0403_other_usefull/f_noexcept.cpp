
#include <iostream>

/*
function marked as noexcept will not throw error if it does
function will terminate program
*/


void print_me() noexcept
{
    std::cout<<"Done"<<std::endl;
}

int main()
{
    print_me();
}