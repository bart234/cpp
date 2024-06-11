#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    Account brtk_acc;
    brtk_acc.set_name("Bartek");
    brtk_acc.set_balance(1000.00);
    
    if (brtk_acc.deposit(200.0)){
        cout<<"Deposit ok"<<endl;
    }else{
        cout<<"Deposit not allowed"<<endl;
    }
    
    if (brtk_acc.withdraw(500.0)){
        cout<<"withdraw ok"<<endl;
    }else{
        cout<<"Not sufficient funds"<<endl;
    }
    
    if (brtk_acc.withdraw(1500.0)){
        cout<<"withdraw ok"<<endl;
    }else{
        cout<<"Not sufficient funds"<<endl;
    }
    
    return 0;
    }
    
