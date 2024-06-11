#include "Savings_Account.h"

class Trust_Account:public Savings_Account
{

    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &acc);
protected:
    int in_counter_of_withdraw_per_yyyy;

private:
    static constexpr int default_max_withdraw_per_y =3;
    static constexpr double default_max_precentage_withdraw =0.2;
    static constexpr double default_deposit_ammout_to_get_bonus =5000.0;
    static constexpr double default_ammount_bonus_for_big_deposit=50.0;
    //copy from 
    static constexpr double default_balance_ammount_for_TrustA =0.0;
    static constexpr double default_intrest_rate_for_TrustA =0.0;
    static constexpr const char *default_acc_name ="Trust acc unnamed";

    void increment_withdraw_counter(){this->in_counter_of_withdraw_per_yyyy++;}

public:
    Trust_Account(double balance, double int_rate,std::string acc_name);     
    Trust_Account(double balance, double int_rate);
    Trust_Account();
    bool deposit(double ammount); //overriten
    bool withdraw(double ammount);  //overriten
    //get_balance - inherited

};

Trust_Account::Trust_Account(
            double balance=default_balance_ammount_for_TrustA, 
            double int_rate=default_intrest_rate_for_TrustA,
            std::string acc_name=default_acc_name):
    Savings_Account(balance,int_rate,acc_name),in_counter_of_withdraw_per_yyyy{0}
    {};

Trust_Account::Trust_Account(double balance, double int_rate):
            Trust_Account{balance,int_rate,default_acc_name}
            {};

Trust_Account::Trust_Account():
            Trust_Account(default_balance_ammount_for_TrustA,
                        default_intrest_rate_for_TrustA,
                        default_acc_name)
            {};


bool Trust_Account::deposit(double ammount)
{
    if(ammount> default_deposit_ammout_to_get_bonus)
    {
        ammount += default_ammount_bonus_for_big_deposit;
        
        if(Savings_Account::deposit(ammount))
        {
            std::cout<<"Bonus of "<<default_ammount_bonus_for_big_deposit<<"$ reached!"<<std::endl;
            return true;
        }
        else{
            return false;
        }
    }
    else
    {
        return Savings_Account::deposit(ammount);
    }

}

bool Trust_Account::withdraw(double ammount)
{
    if(this->in_counter_of_withdraw_per_yyyy<= default_max_withdraw_per_y)
    {
        if(ammount<(this->in_balance*(default_max_precentage_withdraw)))
        {
            this->increment_withdraw_counter();
            return Savings_Account::withdraw(ammount);
        }
        else
        {
            std::cout<<"Withdraw ammount is bigger then: "<< this->in_balance*default_max_precentage_withdraw
                     << ". Your kind of account not allow on withdraw!"<<std::endl;
            return false;
        }
    }
    else
    {   
        std::cout<<"Maximum withdraw pear year reached.Operation Cancelled!"<<std::endl;
        return false;
    }
    
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &acc)
{
    os<<"Account name:(T) '"<<acc.in_acc_name   <<"', balance: "<<acc.in_balance<<" Interest rate: "<< acc.in_int_rate;
    return os;
}

