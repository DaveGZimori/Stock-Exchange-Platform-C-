#include <iostream>
#include "investor.h"
#include "account.h"

using namespace std;

int main() 
{
    cout << "Welcome to the DZ Stock Exchange" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select 1 to login" << endl;
    cout << "Select 2 to register" << endl;

    investor A;
    account Acc1;
    cout << "Name: " << A.get_name() << endl;
    cout << "Password: " << Acc1.get_account_number() << endl;
    cout << "Holder: " << Acc1.get_owner() << endl;
    return 0;
}