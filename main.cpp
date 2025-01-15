#include <iostream>
#include "investor.h"

using namespace std;

int main() 
{
    cout << "Welcome to the DZ Stock Exchange" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select 1 to login" << endl;
    cout << "Select 2 to register" << endl;

    investor A;
    cout << "Name: " << A.get_name() << endl;
    return 0;
}