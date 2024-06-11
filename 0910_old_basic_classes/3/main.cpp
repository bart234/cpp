#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class base declaration Player.h
// methods in Player.cpp
//in main project file always - #include "file.h" -, never .cpp
class Player{
public:
    //attributes
//    private:
    public:
    string name{};
    int xp{3};
    bool is_alive{};
    int hp{100};
    
    //methods
    public:
    void say_something(string text_to_say){
        cout<< name<< " say "<<text_to_say<<endl;
        };
    bool is_dead(bool);
    
    // prototype outside function
    void get_damage(int damage);
};

void Player::get_damage(int damage){
    //int damage {10};
    hp-=damage;
    cout<<"You got hit for "<<damage<< " damage."<<endl;
        if (hp<0){
            cout<<"You are dead."<<endl;
        }else{
            cout<<hp<<" life left"<<endl;
        }
};


int main () {

   
    
    Player frank;
    Player bartek;
    
    vector<Player> player_vec {frank}; //vektor Playerow z frankiem
    player_vec.push_back(bartek);
    frank.name = "frank";
    frank.xp = 30;
    frank.get_damage(120);
    frank.say_something("yolo");
    
    Player *enemy_ptr = new Player;
    (*enemy_ptr).name = "enemy";
    enemy_ptr->xp = 100;
    enemy_ptr->say_something(" aaagghhhhhaaa");
    enemy_ptr->get_damage(10);
        
    return 0;
}