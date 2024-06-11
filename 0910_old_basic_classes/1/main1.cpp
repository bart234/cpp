#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player{
public:
    //attributes
    string name{};
    int xp{3};
    bool is_alive{};
    int hp{100};
    
    //methods
    void say_something(string text_to_say){
        cout<< name<< " say "<<text_to_say<<endl;
        };
    bool is_dead(bool);
};

class Account{
public:
    //attributes
    string name;
    double balance;
    
    //methods
    bool deposit(double bal){balance += bal;} ;
    bool withdraw(double bal){balance -= bal;} ;
    void status(){cout<<"Your balance is: "<<balance<<endl;};
};
int main () {

    Account frank_acc;
    Account brtk_acc;
    frank_acc.name = "Frank acc";
    frank_acc.balance = 100;
    
    Account *ptr_acc{nullptr};
    ptr_acc = new Account;
    ptr_acc->deposit(100);
    ptr_acc->withdraw(44);
    ptr_acc->status();
    delete ptr_acc;
    
    
//    Player frank;
//    Player bartek;
//    
//    vector<Player> player_vec {frank}; //vektor Playerow z frankiem
//    player_vec.push_back(bartek);
//    frank.name = "frank";
//    frank.xp = 30;
//    frank.say_something("yolo");
//    
//    Player *enemy_ptr = new Player;
//    (*enemy_ptr).name = "enemy";
//    enemy_ptr->xp = 100;
//    enemy_ptr->say_something(" aaagghhhhhaaa");
//    
        
    return 0;
}