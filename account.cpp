#include "account.h"
#include "investor.h"
#include <iostream>

using namespace std;

account::account()
{
    account_number = "0000";
    balance = 0;
    owner = investor().get_name();
}

void account::set_account_number(string account_number)
{
    this->account_number = account_number;
}
void account::set_balance(double balance)
{
    this->balance = balance;
}
void account::set_owner(string owner)
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
string account::get_owner()
{
    return owner;
}
void account::display()
{
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}
account::~account(){}
