#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
/*
string a1;
a1 = "abba";

cout<<a1.length()<<endl;
for(int b:a1){cout<<b<<endl;}
*/
/*
string unformatted_full_name {"StephenHawking"};
string imie{};
string nazwisko{};
int i{0};
vector<int> places{};

i=0;
for(auto a:unformatted_full_name)
{	
	if(isupper(a)){places.push_back(i);}
	i++;	
}
imie = unformatted_full_name.substr(places[0],places[1]);
nazwisko = unformatted_full_name.substr(places[1]);
cout<<imie<<" "<<nazwisko<<endl;
*/

    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
	vector <string> viki{};
	viki.push_back(journal_entry_1);
	viki.push_back(journal_entry_2);
	
	for(auto &a: viki)
	{
		std::size_t result =a.find(' ');

		if(result!=std::string::npos)
		{cout<<"we have space here: "<<a.substr(result+1)<<endl;}
		else
		{cout<<"without space: "<<a<<endl;}
	}
	
	std::sort(viki.begin(),viki.end());
	
		for(auto a: viki)
	{cout<<a<<endl;}
	

return 0;	
}
