#pragma once
#include <string>
#include <iostream>

using namespace std;

class account;

class investor
{
    private:
        string name;
        string password;
        string email;
        string phone_number;
        account* acc;
    public:
        investor(const string& name); // constructor with argument passed by reference
        ~investor();
        void set_name(string n);
        void set_password(string p);
        void set_email(string e);
        void set_phone_number(string p);
        void set_account(account* acc);
        string get_name();
        string get_password();
        string get_email();
        string get_phone_number();
        account* get_account() const; 
};