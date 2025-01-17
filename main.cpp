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
bool login();
void createAccount();
void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number);

void display_investor(investor A);
void display_account(account Acc1);

bool searchInCSV(const std::string &filename, const std::string &name, const std::string &password);

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
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    if(login())
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
    return 0;
}


bool login()
{
    bool log = false;
    cout << "Enter your name: ";
    cin >> lgname;
    cout << "Enter your password: ";
    cin >> lgpassword;
    log = searchInCSV("Investors.csv", lgname, lgpassword);
    if (log)
    {
        cout << "Login successful" << endl;
    }
    else
    {
        cout << "Login failed" << endl;
    }
    return log;
}

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
    display_investor(A);
    cout << "Account created successfully" << endl;
    cout << "----------------------------------" << endl;
    cout << "login" <<endl;
    A.get_account()->set_account_number("5674");
    registerInvestor(name, phone_number, email, password, A.get_account()->get_account_number());
    login();
}

void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number)
{
    // Open the CSV file for appending
    std::ofstream file("Investors.csv", std::ios_base::app);

    if (!file.is_open()) 
    {
        std::cerr << "Error opening file" << std::endl;
    }

    // Append the new investor data
    file << name << "," << password << "," << email << "," << phone_number << "," << account_number, "\n";

    // Close the file
    file.close();
}

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

void display_investor(investor A)
{
    cout << "Name: " << A.get_name() << endl;
    //cout << "Password: " << A.get_password() << endl;
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
