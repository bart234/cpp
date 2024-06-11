#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
	cout<<sqrt(43.0)<<endl;
	double result{0};
	result =pow(43.2,3);
	cout<<result<<endl;
	
	cout<<"floor: " <<floor(result)<<endl;
	cout<<"ceil: " <<ceil(result)<<endl;
	
	//randoms
	int random_num{};
	size_t number_of_random_nums{10};
	int min{1}; int max{6};
	
	//seeding random num gnerator
	srand(time(nullptr));
	cout<<"rand max: " <<RAND_MAX<<endl;
	
for(size_t i{1};i<number_of_random_nums;++i)
	{cout<<rand()%max <<endl;}
	
	return 0;
}