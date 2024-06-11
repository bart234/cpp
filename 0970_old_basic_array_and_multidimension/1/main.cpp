#include <iostream>

int main()
{
	const int number_row {3};
    const int number_col {4};
//    int dimArr [number_row][number_col];
    /* 0 | 1 | 2 |3 |4
     * 1
     * 2
     */
    int dimArr [number_row][number_col] 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    std::cout<<dimArr[0][0]<<std::endl;
    std::cout<<dimArr[0][1]<<std::endl;
    std::cout<<dimArr[0][2]<<std::endl;
    std::cout<<dimArr[0][3]<<std::endl;
	return 0;
}
