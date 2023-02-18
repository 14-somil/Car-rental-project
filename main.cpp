bool is_login=false;
bool is_admin=false;

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

std::string user;

using namespace std;

#include "login.h"
#include "admin.h"
#include "customer.h"

int main()
{
    system("cls");
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