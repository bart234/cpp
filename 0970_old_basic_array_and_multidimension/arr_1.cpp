#include <iostream>

int main()
{
	int arr_1[5] {1,2,3,4,5};
	
	std::cout<<arr_1[0]<<"  " <<arr_1[4]<<std::endl;
	std::cout<<"Access to el 6 - out of bounds - garbage:" << arr_1[6]<<"  " <<std::endl;
	arr_1[0]=23;
	arr_1[6]=12;
	std::cout<<"Access to el 6 - out of bounds-we overriding memory:" << arr_1[6]<<"  " <<std::endl;
	return 0;
}