#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    public:
    //atributes
    string name;
    int health;
    int xp;
    
    // metods
    void talk(string text_to_say){cout<< name<< " says: "<< text_to_say<<endl;};
    bool is_dead();
};

class Account{
private:
    //atrr
    string name;
    double balance {0.0}; 
    
public:   
    //meth
    //declared in line
    void set_balance(double bal){balance = bal;}
    double get_balance() {return balance;}
    
    //method will be declared outside class
    //prototypes
    void set_name(string n);
    string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

//Account outside functions
bool Account::withdraw(double amount){
    if ((balance - amount) >=0){
        balance -= amount;
        return true;}
    else{
        return false;
    }
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

void Account::set_name(string n){
    name = n;
}

string Account::get_name(){
    return name;
}



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
    
