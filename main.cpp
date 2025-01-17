#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> // For std::find_if
#include "investor.h"
#include "account.h"

using namespace std;

string lgname;
string lgpassword;
bool my_log{false};
bool logStatus = false;
bool login();
void createAccount();
void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number);

void display_investor(investor A);
void display_account(account Acc1);

bool searchInCSV(const std::string &filename, const std::string &name, const std::string &password);

string getCellDataByFirstColumn(const std::string& filename, const std::string& searchValue, int colIndex) ;

std::string trim(const std::string &str) ;

void buy_shares();
void sell_shares();
void view_transaction_history();
void view_stock_prices(const string &filename, const vector<size_t> &columnWidths);
void view_stock_market_news();

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

void buy_shares()
{

}

void sell_shares()
{

}

void view_transaction_history()
{

}

// Function to trim leading and trailing whitespace
std::string trim(const std::string &str) 
{
    const auto begin = str.begin();
    const auto end = str.end();

    auto trimmedBegin = std::find_if_not(begin, end, ::isspace);
    auto trimmedEnd = std::find_if_not(std::reverse_iterator<std::string::const_iterator>(end),
                                        std::reverse_iterator<std::string::const_iterator>(trimmedBegin), 
                                        ::isspace).base();

    return std::string(trimmedBegin, trimmedEnd);
}

// Function to read and display the listed stock prices
void view_stock_prices(const string &filename, const vector<size_t> &columnWidths)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data; // To store the entire CSV data

    // Read the CSV file line by line
    while (std::getline(file, line)) {
        // Trim whitespace from the line
        line = trim(line);
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> row;

        // Split the line into individual values
        while (std::getline(ss, value, ',')) {
            row.push_back(trim(value)); // Trim each value as well
        }

        // Only add rows with actual data
        if (!row.empty()) {
            data.push_back(row); // Store the row in data
        }
    }

    file.close();

    // Display the table without borders
    if (data.empty()) 
    {
        std::cout << "No data available to display." << std::endl;
        return;
    }

    // Print the data
    for (const auto &row : data) 
    {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << std::setw(5) << row[i]; // Display each cell
            if (i < row.size() - 1) 
            {
                std::cout << " | "; // Separator between columns
            }
        }
        std::cout << std::endl; // New line after each row
    }
}

void view_stock_market_news()
{

}
