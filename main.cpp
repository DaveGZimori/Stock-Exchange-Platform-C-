#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip> // For std::setw
#include <algorithm> // For std::find_if
#include "investor.h"
#include "account.h"
#include "account_func.h"
#include "trade_func.h"
#include "constants.h"

using namespace std;

int main() 
{
    cout << "Welcome to the Uzumba Stock Exchange" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select 1 to login" << endl;
    cout << "Select 2 to register" << endl;
    
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        login();
    }
    else if (choice ==2)
    {
        createAccount();
        login();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    logStatus = my_log;

    if(logStatus==true)
    {
        //display_investor(investor(lgname));

        cout << "----------------------------------" << endl;
        cout << "Main menu" << endl;
        cout << "Select 1 to view account details" << endl;
        cout << "Select 2 to buy shares" << endl;
        cout << "Select 3 to sell shares" << endl;
        cout << "Select 4 to view transaction history" << endl;
        cout << "Select 5 to view stock prices" << endl;
        cout << "Select 6 to view stock market news" << endl;
        cout << "Select 7 to logout" << endl;

        int selection;
        cin >> selection;
        if (selection == 1)
        {
            display_account(*investor(lgname).get_account()); // display account details
        }
        else if (selection == 2)
        {
            buy_shares(current_investor);
        }
        else if (selection == 3)
        {
            sell_shares();
        }
        else if (selection == 4)
        {
            view_transaction_history();
        }
        else if (selection == 5)
        {
            view_stock_prices("ZSEDIRECT.csv", {6, 6, 6, 4, 4, 4, 4});
        }
        else if (selection == 6)
        {
            view_stock_market_news();
        }
        else
        {
            cout << "Invalid selection" << endl;
        }
    }
    return 0;
}
