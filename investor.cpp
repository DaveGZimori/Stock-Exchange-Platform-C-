#include <iostream>
#include <string>
#include "investor.h"

using namespace std;

investor::investor(const string& name) : name{name}
{
    password = "0000";
    email = "jd@gmail.com";
    phone_number = "12345678";
    account* acc = nullptr;
};
void investor::set_name(string name)
{
    this->name = name;
}
void investor::set_password(string password)
{
    this->password = password;
}
void investor::set_email(string email)
{
    this->email = email;
}

void investor::set_phone_number(string phone_number)
{
    this->phone_number = phone_number;
}
void investor::set_account(account* acc)
{
    this->acc = acc;
}

string investor::get_name()
{
    return name;
}
string investor::get_password()
{
    return password;
}
string investor::get_email()
{
    return email;
}

string investor::get_phone_number()
{
    return phone_number;
}

account* investor::get_account() const
{
    return acc;
}

investor::~investor(){}
