#include <iostream>
#include "trade_func.h"
#include <algorithm> // For std::find_if
#include <iomanip> // For std::setw

using namespace std;

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
