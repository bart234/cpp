#include "sources.h"

namespace p_order
{   
    class Command
    {
        public:
        virtual void Execute()const=0;
        virtual ~Command(){};
    };

    class SimpleCommand: public Command
    {
        private:
        std::string my_val;

        public:
        explicit SimpleCommand(std::string in_val):my_val{in_val}{};
        void Execute() const override {std::cout<<"this is Simple Command execution with value: "<<this->my_val<<std::endl;}        
    };

    namespace Light_case
    {
        class OutsideClass_Light
        {
            public:
            void On(){cout<<"Outside class: Connect with terminal 34Df5 and set Light On"<<endl;}
            void Off(){cout<<"Outside class: Treminate connection with terminal 34Df5 and set Light Off"<<endl;}
        };

        class LivingRoom_Light_on: public Command
        {
            Light_case::OutsideClass_Light * my_light_obj;

            public:
            explicit LivingRoom_Light_on(Light_case::OutsideClass_Light * in_my_light_obj):my_light_obj{in_my_light_obj}{};
            void Execute() const override{my_light_obj->On();}            
        };

        class LivingRoom_Light_off: public Command
        {
            private:
            Light_case::OutsideClass_Light * my_light_obj;

            public:
            explicit LivingRoom_Light_off(Light_case::OutsideClass_Light * in_my_light_obj):my_light_obj{in_my_light_obj}{};
            void Execute() const override{my_light_obj->Off();}            
            
        };
 
    }

    class Wykonywacz
    {
        private:
        Command * cmd_start;
        Command * cmd_end;

        public:
        //setters
        void SetStartOn(Command * in_cmd){this->cmd_start=in_cmd;}
        void SetFinishOff(Command * in_cmd){this->cmd_end=in_cmd;}
        //action
        void DoSomethingSimple()
        {
            cout<<"Wykonywacz: im doing something.."<<endl;
            cout<<"Wykonywacz: execution started..."<<endl;
            cmd_start->Execute();
            cout<<"Wykonywacz: end execution, ending process started.."<<endl;
            cmd_end->Execute();
            cout<<"Wykonywacz: end of finish execution"<<endl;
        }

        void LightCase_setObjects(Command * in_on_start, Command * in_off_end)
        {
            cmd_start=in_on_start;
            cmd_end=in_off_end;   
        }
        void LightCase_Light_on(){cmd_start->Execute();}
        void LightCase_Light_off(){cmd_end->Execute();}

        ~Wykonywacz()
        {
            delete cmd_start;
            delete cmd_end;
            cmd_start=nullptr;
            cmd_end=nullptr;
        }

    };

    void eg_simple()
    {
        Wykonywacz w{};
        w.SetStartOn(new SimpleCommand("Start me"));
        w.SetFinishOff(new SimpleCommand("Finish me"));
        w.DoSomethingSimple();
    }

    void eg_lightCase()
    {
        Wykonywacz w{};
        Light_case::OutsideClass_Light* my_light{new Light_case::OutsideClass_Light()};
        w.LightCase_setObjects(new Light_case::LivingRoom_Light_on(my_light),new Light_case::LivingRoom_Light_off(my_light));
        w.LightCase_Light_on();
        w.LightCase_Light_off();

    }


    void run_me()
    {
        //eg_simple();
        eg_lightCase();
    }

}