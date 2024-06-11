#include <iostream>

int main()
{
    int myArr [3]{0};
    
    std::cout<<"fill my arr:"<<std::endl;
    std::cin>>myArr[0]>>myArr[1]>>myArr[2];
    myArr[0]=23;
    std::cout<<myArr[0]<<"  "<<myArr[1]<<" "<<myArr[2]<<std::endl;
    int newArr []{1,4,34,23,1,0,2};
    std::cout<<newArr<<std::endl;
    std::cin>>myArr[0]>>myArr[1]>>myArr[4];
    std::cout<<myArr[0]<<"-"<<myArr[1]<<"-"<<myArr[5];
    return 0;
}