bool is_login=false;
bool is_admin=false;

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>

std::string username;

using namespace std;

#include "login.h"
#include "admin.h"

int main()
{
    asklogin();
    if(is_login==true)
    {
        if(is_login==true)
        {
            admin();
        }
        else
        {
            // customer();
        }
    }
    return 0;
}