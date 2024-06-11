#include <iostream>

using namespace std;

int main()
{
    int val1{100};
    int val2{200};

    cout<<val1<<endl;
    cout<<val2<<endl;
    
    cout<<"reasign"<< endl;
    val1 =val2 = 22;
    cout<<val1<<endl;
    cout<<val2<<endl;
    
    int result{};
    result = val1/3.0;
    cout<<result<<endl;
    
    double result2{};
    result2 = val1/3.0;
    cout<<result2<<endl;
    
    int counter{1}; 
//    couter++
    cout<<counter++<< " -first use - then inctement counter ++"<<endl;
//    ++counter 
    cout<<++counter<< " -first add 1 , then print --counter"<<endl;
	
    cout<<++counter +10<< "++counter +10 - first (++counter - before use, so before add 10) "<<endl;
    /* counter = couter +1
     * result = counter + 10*/
     
     cout<<counter++ +10<< " counter++ +10 "<<endl;
    /*first use then increment
     * reuslt = counter + 10
     * counter = counter + 1*/
     
     cout<<(true&&true&&false)<<endl;
    return 0;
}
