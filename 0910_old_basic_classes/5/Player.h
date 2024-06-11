#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <iostream>

//nie uzywamy namespace w klasach daltego dodajemy  std::
    class Player{
        public:
            //attributes
        //    private:
            public:
            std::string name{};
            int xp{3};
            bool is_alive{};
            int hp{100};
            
            //methods
            public:
            void say_something(std::string text_to_say){
                std::cout<< name<< " say "<<text_to_say<<std::endl;
                };
            void is_dead();
            
            // prototype outside function
            void get_damage(int damage);
    };
    
#endif // _PLAYER_H_
