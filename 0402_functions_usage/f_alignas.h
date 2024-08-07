#include "_source.h"


/*
Alignment is used to make padding in space aroud saved object
-we can control aligment at class level adn on data member 
-what for: if we align variable and we care what data will be in container, because data are read/copy by lines
-          so variables can be copy efficiency, it optimize CPU reads and writes
           it is important to game and trading app
-size: 
    char /byte - 1 bit
    short   - at least 16 bits 
    long    - at least 32 bits
    ll      - at least 64 bits
- but size are mostly compiler specyfic and depend on platform
    char / bool     - 1 byte
    short           - 2 
    int/long/float  - 4 bytes
    double/ ll      - 8 bytes
*/
namespace f_alignas
{
    namespace basic_aligment
    {
        struct alignas(4) foo
        {
            char a;
            char b;
        };

        struct bar
        {
            public:
            alignas(2) char a;
            alignas(8) int b;
        };
        struct bar_raw
        {
            public:
            char a;
            int b;
        };

        struct bar_raw_3
        {
            char a;
            char _pad0[3];
            int b;
        };
        
        struct foo_4
        {               //aligment = 8 - because biggest is double so we prepare space bade on biggest one
                        //size = 24    - we can fit them into 24 ( int 4 + char 1+ float 4 +double 8 + bool 1  = 18 - so we need 4 containers for 8 bytes)
                        //  |aaaab---|cccc----|dddddddd|e--------|
    
            int a;      //d750 750-751-752-753
            char b;     //d754 754-[e]-[e]-[e]
            float c;    //d758 758-759 
            double d;   //d760
            bool e;     //d768
        };

        void run_me_foo_32_bits()
        {
            foo_4 f4;
            printf("%p size: %p - int\n", &f4.a,sizeof(f4.a));
            printf("%p size: %p - char\n", &f4.b,sizeof(f4.b));
            printf("%p size: %p - float\n", &f4.c,sizeof(f4.c));
            printf("%p size: %p - double\n", &f4.d,sizeof(f4.d));
            printf("%p size: %p - bool\n", &f4.e,sizeof(f4.e));
        }

        void run_me()
        {

            bar b_bar;
            b_bar.a ='a';       // 1 byte
            b_bar.b = 42;       // >4 bytes
            printf("%p\n", &b_bar.a);
            printf("%p\n", &b_bar.b);

            bar_raw b_bar_r;
            b_bar_r.a ='a';       // 1 byte
            b_bar_r.b = 42;       // >4 bytes
            printf("%p\n", &b_bar_r.a);
            printf("%p\n", &b_bar_r.b);

            bar_raw_3 b_bar_3;              // |c---|iiii|
            b_bar_3.a ='a';       // 1 byte
            b_bar_3.b = 42;       // >4 bytes
            printf("%p\n", &b_bar_3.a);
            printf("%p\n", &b_bar_3.b);
        }
    }

}