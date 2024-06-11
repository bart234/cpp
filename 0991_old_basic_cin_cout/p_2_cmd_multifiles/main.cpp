#include <iostream>
#include <string>
#include "f.h"

int main() {
	std::cout<<"Hello"<<std::endl;
	std::cout<< "sum me 2 and 3:" << add_1(2.0,3.0)<<std::endl;
	
	/*
	std::string my_new_str;
	std::cout<<"GIve me password"<<std::endl;
	std::cin>>my_new_str;
	if(my_new_str =="BARTEK")
	{
	std::cout<<"Yep it is a password"<<std::endl;
	}else{
		std::cout<<"Errror"<<std::endl;
	}
	std::cout<<"Pwd len is: " <<my_new_str.length()<<std::endl;
	*/
	
	std::string another_string;
	std::cout<<"Write long string to search "<<std::endl;
	std::getline(std::cin,another_string);
	
	std::cout<<"Put stirng to find"<<std::endl;
	std::string str_to_find;
	std::getline(std::cin,str_to_find);
	
	std::cout<<"1. to get place where it is\n 2.To ger string before that \n3.To get string after that"<<std::endl;
	int option_1;
	std::cin>>option_1;
	
	std::string to_keep_output;
	if(option_1==1){
		std::cout<<"THat string is on: " <<another_string.find(str_to_find) << " positon"<<std::endl;
	}
	if(option_1==2)
	{
		std::cout<<"Before that i found: " << another_string.substr(0,another_string.find(str_to_find))<< std::endl;
	}
	if(option_1==3)
	{
		std::cout<<"After that i found: " << another_string.substr(another_string.find(str_to_find)+str_to_find.length(),another_string.length())<< std::endl;
	}
	
	
	
	return 0;
}
