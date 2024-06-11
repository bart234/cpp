#ifndef _I_ACCOUNT_H_
#define _I_ACCOUNT_H_

#include <iostream>
#include <string>

using namespace std;


class I_Account
{
    friend std::ostream operator<<(std::ostream &os, const I_Account &obj);
public:
    virtual ~I_Account() = default;
    virtual void print(std::ostream &os) const =0;
};

std::ostream &operator<<(std::ostream &os, I_Account &obj)
{
    obj.print(os);
    return os;
}

#endif