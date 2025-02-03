#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "account_func.h"
#include "constants.h"

using namespace std;

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
        string acc_nmbr = getCellDataByFirstColumn("Investors.csv", lgname, 4);
        investor A(lgname);
        account Acc1;
        Acc1.set_owner(&A);
        A.set_account(&Acc1);
        A.get_account()->set_account_number(acc_nmbr);
        display_investor(A);
    }
    else
    {
        cout << "Login failed" << endl;
    }
    return my_log;
}

// Function to search for a row by its first-column value and get data from a specific cell
string getCellDataByFirstColumn(const std::string& filename, const std::string& searchValue, int colIndex) 
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }

    string line;

    // Iterate through each line in the file
    while (std::getline(file, line)) 
    {
        stringstream lineStream(line);
        string cell;
        vector<std::string> row;

        // Split the line into cells
        while (std::getline(lineStream, cell, ',')) 
        {
            row.push_back(cell);
        }

        // Check if the first column matches the search value
        if (!row.empty() && row[0] == searchValue) {
            // Ensure the column index is within range
            if (colIndex >= 0 && colIndex < static_cast<int>(row.size())) 
            {
                return row[colIndex];
            } else 
            {
                std::cerr << "Error: Column index out of range!" << std::endl;
                return "";
            }
        }
    }

    std::cerr << "Error: Row with value '" << searchValue << "' in the first column not found!" << std::endl;
    return "";
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
    file << name << "," << phone_number  << "," << email << "," << password << "," << account_number,"\n";

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