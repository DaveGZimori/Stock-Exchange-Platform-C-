#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "trade_func.h"
#include "account.h"
#include "investor.h"
#include "account_func.h"
#include <algorithm> // For std::find_if
#include <iomanip> // For std::setw
#include <cstdlib>

using namespace std;

void buy_shares(investor A)
{
    cout << "Enter the stock symbol: ";
    string stock_symbol;
    cin >> stock_symbol;
    cout << "Enter the number of shares to buy: ";
    int num_shares;
    cin >> num_shares;
    cout << "Enter the price per share: ";
    double price_per_share;
    cin >> price_per_share;
    cout << "Total cost: " << num_shares * price_per_share << endl;
    cout << "Proceed to buy shares? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        bool required_stock = search_stock("ZSEDIRECT.csv", stock_symbol);
        if (required_stock==true)
        {
            double current_bal = A.get_account()->get_balance();
            double total_cost = num_shares * price_per_share;
            cout << "Current balance: " << current_bal << endl;
            if (current_bal >= total_cost)
            {
                // Update the transaction history
                // Update the investor's account balance
                // Update the investor's share portfolio
                // Display the updated account details
                cout << "Shares bought successfully" << endl;
            }
            else
            {
                cout << "Insufficient funds" << endl;
            }
        }
        else
        {
            cout << "Stock not found" << endl;
        }
    }
    else
    {
        cout << "Transaction failed" << endl;
    }
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
    std::string pdfPath = "Guide_2021.pdf";

    #ifdef _WIN32
        // Windows: Open PDF with default viewer
        std::string command = "start " + pdfPath;
    #elif __APPLE__
        // macOS: Open PDF with default viewer
        std::string command = "open " + pdfPath;
    #else
        // Linux/Unix: Open PDF with default viewer
        std::string command = "xdg-open " + pdfPath;
    #endif

    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "PDF opened successfully." << std::endl;
    } else {
        std::cerr << "Failed to open PDF." << std::endl;
    }
}

bool search_stock(const string &filename, const string &stock_symbol)
{
    bool search_status = false;
    std::ifstream file(filename); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return search_status; // Return false if the file cannot be opened
    }

    std::string line; // To store each line of the CSV
    int lineNumber = 0; // Line tracker (optional, useful for debugging)
    int stock_symbol_column = 2; // Column index for the stock symbol
    // Read the file line by line
    while (std::getline(file, line)) 
    {
        lineNumber++;
        
        // Use a stringstream to parse the line
        std::stringstream ss(line);
        std::string cell;
        int currentColumn = 0;

        // Iterate through columns in the current line
        while (std::getline(ss, cell, ',')) 
        {
            // Check if the current column matches the desired column
            if (currentColumn == stock_symbol_column) 
            {
                if (cell == stock_symbol) 
                {
                    std::cout << "You're purchasing " << stock_symbol << std::endl;
                    search_status = true; // Value found
                    break; // Exit the loop if found
                }
            }
            currentColumn++;
        }
    }
    if (!search_status) 
    {
        // If the value was not found in the specified column
        std::cout << "Stock '" << stock_symbol << "' not found. " << std::endl;
    }
    return search_status;
}
