#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "investor.h"
#include "account.h"

using namespace std;

string lgname;
string lgpassword;
bool my_log{false};
bool login();
void createAccount();
void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number);

void display_investor(investor A);
void display_account(account Acc1);

bool searchInCSV(const std::string &filename, const std::string &name, const std::string &password);

void buy_shares();
void sell_shares();
void view_transaction_history();
void view_stock_prices();
void view_stock_market_news();

int main() 
{
    cout << "Welcome to the Uzumba Stock Exchange" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select 1 to login" << endl;
    cout << "Select 2 to register" << endl;
    bool logStatus = false;
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

    if(logStatus)
    {
        display_investor(investor(lgname));

        cout << "----------------------------------" << endl;
        cout << "Main menu" << endl;
        cout << "Select 1 to view account details" << endl;
        cout << "Select 2 to buy shares" << endl;
        cout << "Select 3 to sell shares" << endl;
        cout << "Select 4 to view transaction history" << endl;
        cout << "Select 5 to view stock prices" << endl;
        cout << "Select 6 to view stock market news" << endl;
    }

    int selection;
    cin >> selection;
    if (selection == 1)
    {
        display_account(*investor(lgname).get_account()); // display account details
    }
    else if (selection == 2)
    {
        buy_shares();
    }
    else if (selection == 3)
    {
        // sell shares
        sell_shares();
    }
    else if (selection == 4)
    {
        // view transaction history
        view_transaction_history();
    }
    else if (selection == 5)
    {
        // view stock prices
        view_stock_prices();
    }
    else if (selection == 6)
    {
        // view stock market news
        view_stock_market_news();
    }
    return 0;
}

// Function definitions
// create a login function
bool login()
{
    cout << "Enter your name: ";
    cin >> lgname;
    cout << "Enter your password: ";
    cin >> lgpassword;
    my_log = searchInCSV("Investors.csv", lgname, lgpassword);
    if (my_log)
    {
        cout << "Login successful" << endl;
    }
    else
    {
        cout << "Login failed" << endl;
    }
    return my_log;
}
// create a function to create an account
void createAccount()
{
    string name;
    string password;
    string email;
    string phone_number;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your phone number: ";
    cin >> phone_number;
    investor A(name);
    account Acc1;
    Acc1.set_owner(&A);
    A.set_account(&Acc1);
     A.get_account()->set_account_number("5674");
    cout << "Account created successfully" << endl;
    cout << "----------------------------------" << endl;
    cout << "Account details: " << endl;
    display_investor(A);
    cout << "Proceed to login" <<endl;
    cout << "----------------------------------" << endl;
    registerInvestor(name, phone_number, email, password, A.get_account()->get_account_number());
}

// create a function to register an investor
void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number)
{
    // Open the CSV file for appending
    std::ofstream file("Investors.csv", std::ios_base::app);

    if (!file.is_open()) 
    {
        std::cerr << "Error opening file" << std::endl;
    }

    // Append the new investor data
    file << name << "," << phone_number  << "," << email << "," << password << "," << account_number, "\n";

    // Close the file
    file.close();
}

// create a function to search for an investor in the CSV file
bool searchInCSV(const string &filename, const string &name, const string &password) 
{
    std::ifstream file("Investors.csv");
    std::string line;
    bool found = false;
    if (!file.is_open()) 
    {
        cerr << "Unable to open file: " << "Investors.csv" << endl;
        return -1;
    }

    // Read the CSV file line by line
    while (getline(file, line)) 
    {
        stringstream ss(line);
        string value;
        vector<string> row;

        // Split the line into individual values
        while (getline(ss, value, ',')) 
        {
            row.push_back(value);
        }

        // Search for the name in the current row
        for (const auto &val : row) 
        {
            if (val == name) 
            {
                for (const auto &val : row) 
                {
                    if (val == password) 
                    {
                        found = true;
                        break; // Exit the loop if found
                    }
                }
            }
        }

        // Search for the password in the current row
    }
    file.close();
    return found;
}

// create a function to display an investor
void display_investor(investor A)
{
    cout << "Name: " << A.get_name() << endl;
    //cout << "Password: " << A.get_password() << endl;
    cout << "Email: " << A.get_email() << endl;
    cout << "Phone number: " << A.get_phone_number() << endl;
    cout << "Account number: " << A.get_account()->get_account_number() << endl;
    cout << "Balance: " << A.get_account()->get_balance() << endl;
}

// create a function to display an account
void display_account(account Acc1)
{
    cout << "Account number: " << Acc1.get_account_number() << endl;
    cout << "Balance: " << Acc1.get_balance() << endl;
    cout << "Owner: " << Acc1.get_owner()->get_name() << endl;
    cout << "Password: " << Acc1.get_owner()->get_password() << endl;
    cout << "Email: " << Acc1.get_owner()->get_email() << endl;
    cout << "Phone number: " << Acc1.get_owner()->get_phone_number() << endl;
}