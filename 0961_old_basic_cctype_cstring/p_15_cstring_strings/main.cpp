#include <iostream>
#include <cstring>

int main()
{
    // <CSTYLE>
    char c_string_1[] {"My cstyle string - old one "};
    std::cout<<c_string_1<<std::endl;
    std::cout<<"Str len used on c_string: " <<strlen(c_string_1)<<std::endl;
    std::cout<<"SIZE  OF used on c_string: (with NUL at end) " <<sizeof(c_string_1)<<std::endl;
    c_string_1[0]='G';  
    std::cout<<"Show me that modified str: " <<c_string_1<<std::endl;
    std::cout<<"-------------"<<std::endl;
    
    const char *c_string_2_const_char_ptr[] {"This is const char pointer - that mean pointer to const char"};
    std::cout<<"Str len used on DEREFERENCED ptr: " <<strlen(*c_string_2_const_char_ptr)<<std::endl;
    std::cout<<"SIZE  OF used on ptr -THATS MEAN IT IS SIZE OD PTR  " <<sizeof(c_string_2_const_char_ptr)<<std::endl;
    //We can modify it in that way , even it is a array
    //*c_string_2_const_char_ptr[0]="B";  // because we add cosnt - we have error read-only

    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"---------Literals - mean string without variable-----------------"<<std::endl;
    
    //RAW STRINGS
    //const char *str_2 {"This is basic " string "with dbl qoes which will not compile"}
    // that below will work with .. dash - 
    const char *str_2 {R"-(This is basic " strig with 
    dbl qoes which will not
     compile)-"};

    std::cout<<str_2<<std::endl;

    return 0;

}