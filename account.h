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
        string owner;
    public:
        account();
        ~account();
        void set_account_number(string a);
        void set_balance(double b);
        void set_owner(string o);
        string get_account_number();
        double get_balance();
        string get_owner();
        void display();
};