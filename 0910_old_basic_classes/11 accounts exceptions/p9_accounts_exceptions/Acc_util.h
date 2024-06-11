#include "Checking_Account.h"
#include "Savings_Account.h"
#include <vector>
#include <memory>

class Acc_util
{
public:
    std::vector<std::shared_ptr<Account>> viki;
    void print_info();

};

void Acc_util::print_info()
{
    for(auto const el:viki)
    {
        cout<<*el<<endl;
    }
}