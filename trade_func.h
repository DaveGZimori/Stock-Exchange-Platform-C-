#pragma once // include guard
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "investor.h"
#include "account.h"

using namespace std;
std::string trim(const std::string &str) ;

void buy_shares(investor A);
void sell_shares();
void view_transaction_history();
void view_stock_prices(const string &filename, const vector<size_t> &columnWidths);
void view_stock_market_news();
bool search_stock(const string &filename, const string &stock_symbol);