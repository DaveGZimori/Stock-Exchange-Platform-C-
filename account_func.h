#pragma once // include guard
#include <iostream>
#include <string>
#include <fstream>
#include "investor.h"
#include "account.h"

using namespace std;


bool login();
void createAccount();
void registerInvestor(const string &name, const string &phone_number, const string &email, const string &password, const string &account_number);

void display_investor(investor A);
void display_account(account Acc1);

bool searchInCSV(const std::string &filename, const std::string &name, const std::string &password);

string getCellDataByFirstColumn(const std::string& filename, const std::string& searchValue, int colIndex) ;