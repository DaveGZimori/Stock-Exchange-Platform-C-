#pragma once
#include <string>
#include <iostream>

using namespace std;
class investor
{
    private:
        string name;
        string password;
        string email;
        string account_number;
        string phone_number;
        double balance;
    public:
        investor();
        ~investor();
        void set_name(string n);
        void set_password(string p);
        void set_email(string e);
        void set_account_number(string a);
        void set_phone_number(string p);
        void set_balance(double b);
        string get_name();
        string get_password();
        string get_email();
        string get_account_number();
        string get_phone_number();
        double get_balance();
        void display();
};