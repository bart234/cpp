#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
	 
    //----WRITE YOUR CODE BELOW THIS LINE----
    char first_name []{"Bjarne"};
    char last_name []{"Stroustrup"};
    char whole_name [20]{};
    int first_name_length{};
    first_name_length = strlen(first_name);
    int last_name_length{};
    last_name_length = strlen(last_name);
    strcpy(whole_name,first_name);
    strcat(whole_name,last_name);
    int whole_name_lenght{};
    whole_name_lenght = strlen(whole_name);
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The length of the first name, " << first_name << ", is " << first_name_length 
    << " letters long and the length of the last name, " << last_name << ", is " << last_name_length 
    << " letters long. This means that the length of the whole name must be " << whole_name_lenght << " letters long.";
	return 0;
    }
