#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	//reference cannot be null- must be initializated
	//cannot be null, and after set cannot be changed
	
	std::vector<std::string> viki_1{"abba","beta","gamma"};
	
	for( auto el:viki_1) // el as copy -  overriding copy does not change source
	{el="tzeta";}
	for(auto el:viki_1)	// el as copy
	{cout<<el<<endl;}
	
	for(auto &el:viki_1)	// el as reference 
	{cout<<el<<endl;}
	for(auto &el:viki_1)	// el as reference -we change source
		{el="tzeta";}
	//for(auto const &el:viki_1)	// we can read it as reference but cannot change
	//{el="tzeta";}
	for(auto &el:viki_1)	// el as reference 
	{cout<<el<<endl;}
	
return 0;
}