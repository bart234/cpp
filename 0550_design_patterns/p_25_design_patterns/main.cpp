#include "p_observer.h"
#include "p_decorator.h"
#include "p_fabrik.h"
#include "p_singleton.h"
#include "p_order.h"
#include "p_template.h"

int main()
{
    //p_observer::run_me();
    //p_decorator::run_me();
    //p_fabrik::run_me();
    //p_singleton::run_me(); //work but invastigate it, it isnt thread safe
    //p_order::run_me();
    p_template::run_me();

    cout<<"compiled"<<endl;

}