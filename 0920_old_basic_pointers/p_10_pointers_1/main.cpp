#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main ()
{
	

double *ptr_dbl ;
cout<<"GARBAGE: value: " <<ptr_dbl<< " adress: " << &ptr_dbl<<endl; // garbage
ptr_dbl = nullptr;
cout<<"nongarbage: value: " <<ptr_dbl<< " adress: " << &ptr_dbl<<endl; // nongarbage
cout<<endl;

double val_1{234.2};
double *ptr_val;
ptr_val=&val_1;
cout<<"val_1: value: " <<val_1<< " adress: " << &val_1<<endl; // nongarbage
cout<<"ptr_val: value: " <<*ptr_val<< " adress: " << ptr_val<<endl; // nongarbage
cout<<endl;

val_1 =23.1;
cout<<"Change value at val_1"<<endl;
cout<<"val_1: value: " <<val_1<< " adress: " << &val_1<<endl; // nongarbage
cout<<"ptr_val: value: " <<*ptr_val<< " adress: " << ptr_val<<endl; // nongarbage
cout<<endl;

*ptr_val =1.21;
cout<<"Change value at ptr_to_val_1"<<endl;
cout<<"val_1: value: " <<val_1<< " adress: " << &val_1<<endl; // nongarbage
cout<<"ptr_val: value: " <<*ptr_val<< " adress: " << ptr_val<<endl; // nongarbage
cout<<endl;




cout<<"Change ptr adress behind"<<endl;
int a =4;
int *ptr_a{&a};
int b =34;
int *ptr_b{&b};

cout<<"A: "<<a<< " adress:  "<< &a<<endl;
cout<<"B: "<<b<< " adress:  "<< &b<<endl;
/*
int *temp{&a};
cout<<"temp: "<<temp<< " adress:  "<< &temp<<endl;
a=b;
cout<<"temp: "<<temp<< " adress:  "<< &temp<<endl;
*/
cout<<endl;



/*
cout<<"Another pointer to same place?"<<endl;
double *ptr_val_2{};
*ptr_val_2 = ptr_val;
cout<<"val_1: value: " <<val_1<< " adress: " << &val_1<<endl; // nongarbage
cout<<"ptr_val: value: " <<*ptr_val<< " adress: " << ptr_val<<endl; // nongarbage
cout<<"ptr_val_2: value: " <<*ptr_val_2<< " adress: " << ptr_val_2<<endl; // nongarbage
*/

cout<<"Vectors"<<endl;

vector<std::string> abba {"abba","beta","gamma"};

vector<std::string> *ptr_viki{};
ptr_viki = &abba;
cout<<"Acces to vestors values:(*ptr_viki).at(1): "<< (*ptr_viki).at(1)<<endl;
(*ptr_viki).at(0) = "Bartek";
cout<<"change vector vallue '(*ptr_viki).at(0) = '" << (*ptr_viki).at(0)<<endl;
cout<<"Auto loop trough vector, with a as refference to vector elements"<<endl;
for(auto &a: (*ptr_viki)){cout<<a<<endl;} 




//int *int_ptr{};
//double dbl_val{23.2};
//int_ptr = &dbl_val;
//ptr_2 = ptr_val;
//cout<<"ptr_2: value: " <<ptr_2<< " adress: " << &ptr_2<<endl; // nongarbage


return 0;	
}
