#include <iostream>
#include <string>
#include "investor.h"

using namespace std;

investor::investor()
{
    name = "John Doe";
    password = "0000";
    email = "jd@gmail.com";
    account_number = "1234";
    phone_number = "12345678";
    balance = 0;
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
void investor::set_account_number(string account_number)
{
    this->account_number = account_number;
}
void investor::set_phone_number(string phone_number)
{
    this->phone_number = phone_number;
}
void investor::set_balance(double balance)
{
    this->balance = balance;
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
string investor::get_account_number()
{
    return account_number;
}
string investor::get_phone_number()
{
    return phone_number;
}
double investor::get_balance()
{
    return balance;
}
void investor::display()
{
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "Balance: " << balance << endl;
}
investor::~investor()
{
    cout << "Object destroyed" << endl;
}
