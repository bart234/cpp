#include <iostream>
 

using namespace std;

bool is_number_prime(int num);

int find_first_prime_from(int bigger_then_that_num);

 

int find_first_prime_from(int bigger_then_that_num){

    bool not_found_prime{true};

    int counter{bigger_then_that_num+1};

   

    while (not_found_prime)

    {

        if (is_number_prime(counter))

        {

            not_found_prime = false;

        }else

        {

            counter++;

        }

    }

    return counter;

}

 

bool is_number_prime(int num){

    bool is_prime{true};

    int div_numbers{0};

    for(int i =1; i<=num;++i){

        if (num%i == 0){

            div_numbers +=1;

        }

        if (div_numbers>2){

            is_prime = false;

            break;

        }

    }

    if (is_prime){

        return true;

    }else{

        return false;

    }

}

 

int main (){

    //find prime number

    int number_of_required_num =22;

    int number_list[number_of_required_num]{};

    int num_el{number_of_required_num};

    int counter {0};

    int last_value{0};

   

    

    // cout<<find_first_prime_from(0)<<endl;

   

    while (counter < num_el){

        number_list[counter] = find_first_prime_from(last_value);

        last_value = number_list[counter];

        counter++;

    }

   

    cout<<"my num list"<<endl;

    for(auto el: number_list){

        cout<<el<<endl;

    }

   

    

    // for (int i = 0;i<num_el;++i){

    //     is_number_prime(i);

    // }

   

    // long data [5] {};

    // int w = sizeof(data[0]);

    // int al = sizeof(data);

    // // cout<<sizeof(data)<<endl;

    // // cout<<sizeof(data[0])<<endl;

    // cout<<al/w<<endl;

    // for (int i = 0; i< (sizeof(data)/sizeof(data[0]));++i)

    // {

    //     cout<<i<<endl;

    //     *(data +i) = 2*(i+1);

    // }

    // for(auto el:data){

    //     cout<<el<<endl;

    // }

    // return 0;

}