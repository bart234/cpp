#include <iostream>

class Abba
{
    size_t _a;
    public:
    explicit Abba(size_t a):_a(a){};
    Abba(char const * const ptr){};

};

int main()
{
    //it will explicit cast int int size_t
    //after we add explicit - that conversion is no allowed
    //Abba a =static_cast<size_t>(2);
    //Abba b =3;
    size_t t =3;
    Abba c(t);

}