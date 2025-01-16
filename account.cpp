#include "account.h"
#include "investor.h"
#include <iostream>

using namespace std;

account::account()
{
    account_number = "0000";
    balance = 0;
    investor* owner = nullptr;
}

void account::set_account_number(string account_number)
{
    this->account_number = account_number;
}
void account::set_balance(double balance)
{
    this->balance = balance;
}
void account::set_owner(investor* owner)
{
    this->owner = owner;
}
string account::get_account_number()
{
    return account_number;
}
double account::get_balance()
{
    return balance;
}
investor* account::get_owner() const
{
    return owner;
}

account::~account(){}
