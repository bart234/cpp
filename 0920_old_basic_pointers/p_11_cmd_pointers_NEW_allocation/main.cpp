#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main ()
{
//dynamically allocated element - without separated initialization

	double *prt_d_1 = new double;
	cout<<"adress(default value in pointer it is adredsss): " <<prt_d_1<<endl;	
	*prt_d_1 =2.3;
	cout<<"value added : " <<*prt_d_1<<endl;
	cout<<"there is no other acces then pointer to that 2.3 vlaue"<<endl;
	cout<<"and we have to delete it after use from memory"<<endl;
	delete  prt_d_1; //delete value at the end of pointer
	prt_d_1 = nullptr;	//delete pointer itself
	
	cout<<"value added in other row: " <<prt_d_1<< " " <<*prt_d_1<<endl;
	
return 0;
}
