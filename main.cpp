bool is_login=false;
bool is_admin=false;

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>

std::string user;

using namespace std;

#include "login.h"
#include "admin.h"
#include "customer.h"

int main()
{
    asklogin();
    if(is_login==true)
    {
        if(is_admin==true)
        {
            admin();
        }
        else
        {
            customer();
        }
    }
    return 0;
}