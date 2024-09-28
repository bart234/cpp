    #include "Lvl_0_Menu.h" 
    #include "MP_user_main.h"
    class App
    {
        private:
            std::shared_ptr<User> user =nullptr;   
        public:
            App(){};
            ~App()=default;
            void app_run();
            
    };

    void App::app_run()
    {
         //my main stack
        std::stack<std::shared_ptr<MenuTemplate>> stack_of_menus;

        //we add start main menu
        std::shared_ptr<MenuTemplate> main_menu_lvl0 {new Menu_MainMenu{user}}; 
        stack_of_menus.push(main_menu_lvl0);

        // main_menu by default is going to add to that quene
        int selected_option;
        
        //main_loop
        while (true)
        {   

            stack_of_menus.top()->show_menu();        
            selected_option=stack_of_menus.top()->manageUserInput();            
            stack_of_menus.top()->launch_selected_option(selected_option,stack_of_menus);
            if (selected_option == 0) {break;}                  //Quit
            if (selected_option == 9) {stack_of_menus.pop();}   // Back to previous menu
        }
    } 