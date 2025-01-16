#pragma once
#include <iostream>
#include <string>
#include "investor.h"

using namespace std;

class account
{
    private:
        string account_number;
        double balance;
        investor* owner;
    public:
        account();
        ~account();
        void set_account_number(string a);
        void set_balance(double b);
        void set_owner(investor* owner);
        string get_account_number();
        double get_balance();
        investor* get_owner() const;
};