#include <string>
#include <vector>
#include "constants.h"

using namespace std;

string lgname = "";
string lgpassword  = "";
bool my_log = false;
bool logStatus = false;
investor current_investor = investor(lgname);
account* current_account = nullptr;