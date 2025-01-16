#include <iostream>
#include "investor.h"
#include "account.h"

using namespace std;


void display_investor(investor A);
void display_account(account Acc1);

int main() 
{
    cout << "Welcome to the Uzumba Stock Exchange" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select 1 to login" << endl;
    cout << "Select 2 to register" << endl;

    investor A("King");
    account Acc1;
    A.set_account(&Acc1);
    Acc1.set_owner(&A);
    Acc1.set_account_number("0001");
    Acc1.set_balance(250);
    Acc1.get_owner()->set_password("072243");
    Acc1.get_owner()->set_email("bg@gmail.com");
    Acc1.get_owner()->set_phone_number("0778645238");
    display_investor(A);
    cout << "----------------------------------" << endl;
    display_account(Acc1);
    return 0;
}

void display_investor(investor A)
{
    cout << "Name: " << A.get_name() << endl;
    cout << "Password: " << A.get_password() << endl;
    cout << "Email: " << A.get_email() << endl;
    cout << "Phone number: " << A.get_phone_number() << endl;
    cout << "Account number: " << A.get_account()->get_account_number() << endl;
    cout << "Balance: " << A.get_account()->get_balance() << endl;
}

void display_account(account Acc1)
{
    cout << "Account number: " << Acc1.get_account_number() << endl;
    cout << "Balance: " << Acc1.get_balance() << endl;
    cout << "Owner: " << Acc1.get_owner()->get_name() << endl;
    cout << "Password: " << Acc1.get_owner()->get_password() << endl;
    cout << "Email: " << Acc1.get_owner()->get_email() << endl;
    cout << "Phone number: " << Acc1.get_owner()->get_phone_number() << endl;
}