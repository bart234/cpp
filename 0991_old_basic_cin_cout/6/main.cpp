#include <iostream>

int main()
{
    int myArr [9]{0};
    myArr[0] = 100;
    myArr[9]=1000;
    std::cout<<"first element:" <<myArr[0]<< "  last element: "<<myArr[9]<<std::endl;
    return 0;
}