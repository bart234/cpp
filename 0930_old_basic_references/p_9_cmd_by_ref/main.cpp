#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> new_viki{1,2,3,45,6};

void modif_me(vector<int> &viki);
void print_viki(const vector<int> &viki);

int main()
{
	
	modif_me(new_viki);
	print_viki(new_viki);
	return 0;
}

void print_viki(const vector<int> &viki)
{
	//viki.at(2)=123;
	for(auto const &a:viki) //<----------------------------- to have read only, add const,otherwise you can change it
	{
		//viki.at(2)=123;
		//a+= 2;
		cout<<a<<endl;
	}
}

void modif_me(vector<int> &viki)
{
	viki[2]=99;
}