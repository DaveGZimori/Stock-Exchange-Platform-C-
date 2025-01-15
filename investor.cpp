#include <iostream>
#include <string>

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
        investor(){};
        void set_name(string n)
        {
            name = n;
        }
        void set_password(string p)
        {
            password = p;
        }
        void set_email(string e)
        {
            email = e;
        }
        void set_account_number(string a)
        {
            account_number = a;
        }
        void set_phone_number(string p)
        {
            phone_number = p;
        }
        void set_balance(double b)
        {
            balance = b;
        }
        string get_name()
        {
            return name;
        }
        string get_password()
        {
            return password;
        }
        string get_email()
        {
            return email;
        }
        string get_account_number()
        {
            return account_number;
        }
        string get_phone_number()
        {
            return phone_number;
        }
        double get_balance()
        {
            return balance;
        }
        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Phone Number: " << phone_number << endl;
            cout << "Balance: " << balance << endl;
        }
};