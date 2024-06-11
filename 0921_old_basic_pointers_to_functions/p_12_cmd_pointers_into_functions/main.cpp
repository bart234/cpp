#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void pointer_add(int *in_ptr_int);
void swap_them_value(int* p_int1, int* p_int2);
void swap_them_adress(int* p_int1, int* p_int2);
int *function_return_bigger(int *p_int1, int *p_int2);
std::vector<int> *create_vector_of_ints (int size, int defaul_value);

int main ()
{
	/*
	int a {10};
	int *ptr_int{nullptr};
	
	pointer_add(&a);
	cout<<a<<endl;
	
	ptr_int=&a;
	pointer_add(ptr_int);
	cout<<ptr_int<<" "<<*ptr_int<<endl;
	ptr_int=nullptr;
	delete ptr_int;
	

	int *ptr_b {new int};
	*ptr_b=6;
	pointer_add(ptr_b);
	cout<<ptr_b<<" "<<*ptr_b<<endl;
	ptr_b=nullptr;
	delete ptr_b;
	*/
	
	/*
	cout<<"value swaping under pointers"<<endl;
		int a{10};int b{20};
	cout<<a<< " " << b<<"addresses "<< &a<< " " <<&b<< endl;
	swap_them_value(&a,&b);
	cout<<a<< " " << b<<"addresses "<< &a<< " " <<&b<<  endl;
	

	//swap_them_adress(&a,&b);
	//cout<<a<< " " << b<<"addresses "<< &a<< " " <<&b<<  endl;
	*/
	
	/*
	int a{10};
	int b{20};
	int *ptr_int{nullptr};
	ptr_int = function_return_bigger(&a,&b);
	cout<<"return: " <<*ptr_int<<" adress: "<< ptr_int<<endl;
	*/
	
	//standard allocation -  access by ptr and by variable
	std::vector<int> a{};
	std::vector<int> * temp_viki{&a};
	(*temp_viki).push_back(2);
	(*temp_viki).push_back(5);		
	for(auto a:(*temp_viki)){cout<<a<<endl;}
	
	//dynamic allocation - access only by ptr
	std::vector<int> * temp_viki2{new std::vector<int>};
	(*temp_viki2).push_back(2);
	(*temp_viki2).push_back(5);
	for(auto a:(*temp_viki2)){cout<<a<<endl;}
	
	//dynamic allocation - but infunction
	std::vector<int> * temp_viki3{nullptr};
	temp_viki3 = create_vector_of_ints(3,22);
	for(auto a:(*temp_viki3)){cout<<a<<endl;}
	return 0;
	
	//do not create variable in fuction and return it as pointer
	//because local function will terminate and values will be release
	/* in *dont_do_this() {
		int size{};		<- that variable is local,  will be deleted after funcion end
		..
	return size &;}
	int *or_this(){
		int size{3};		<- like above but pointer to that memory place will get soem garbage not 3
		int *int_ptr{&size};
		..
		return int_ptr;}
		*/
}


std::vector<int> *create_vector_of_ints (int size, int defaul_value=0)
{
	std::vector<int> * temp_viki2{new std::vector<int>};
	for(int a = 0; a<size;++a)
	{(*temp_viki2).push_back(defaul_value);}
	return temp_viki2;
	
}

int *function_return_bigger(int *p_int1, int *p_int2)
{
	if(*p_int1>=*p_int2)
	{return p_int1;}
	else
	{return p_int2;}
}


void swap_them_adress(int* p_int1, int* p_int2)
{
	int *temp_1 = p_int1;
	p_int1 = p_int2;
	p_int2 = temp_1;	
	
}


void swap_them_value(int* p_int1, int* p_int2)
{
	int temp_1 = *p_int1;
	*p_int1 = *p_int2;
	*p_int2 = temp_1;	
	
}


void pointer_add(int *in_ptr_int)
{
	*in_ptr_int = *in_ptr_int +1;
}

