int main();
void customer_login();
void customer_register();
void admin_login();

void asklogin()
{
    cout<<"\nEnter\n1: to login as agent\n2: to login as customer\n3: to register as new customer\n\n";
    int choice=0;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            admin_login();
            is_admin=true;
            is_login=true;
            break;
        }

        case 2:
        {
            customer_login();
            is_login=true;
            break;
        }

        case 3:
        {
            customer_register();
            break;
        }

        default:
        {
            cout<<"Inalid Input\n";
            asklogin();
            break;
        }
    }
}

void admin_login()
{
    ifstream in("data/admin/password");
    string temp_pass;
    in>>temp_pass;
    while(true)
    {
        string password;
        cout<<"Enter password:\n";
        cin>>password;
        
        if(password==temp_pass)
        {
            break;
        }
        else
        {
            cout<<"Wrong password\n";
            continue;
        }
    }
    in.close();    
}

void customer_login()
{
    string username;
    cout<<"Enter username:\n";
    cin>>username;
    string temp;
    ifstream in("data/customer/"+username);
    in>>temp;
    string temp_pass;
    in>>temp_pass;
    if(temp==username)
    {
        while(true)
        {
            string password;
            cout<<"Enter password:\n";
            cin>>password;
            
            if(password==temp_pass)
            {
                cout<<"You are in\n";
                break;
            }
            else
            {
                cout<<"Wrong password\n";
                continue;
            }
        }
        in.close();
    }
    else
    {
        cout<<"User doesn\'t exist\n";
        in.close();
        main();
    }
}

void customer_register()
{
    string username;
    cout<<"Enter username:\n";
    cin>>username;
    ifstream in("data/customer/"+username);
    string temp;
    in>>temp;
    if(username==temp)
    {
        cout<<"Username already taken.\n\n";
        customer_register();
    }
    else
    {
        string password;
        cout<<"Enter password:\n";
        cin>>password;
        ofstream out("data/customer/"+username);
        out<<username<<endl;
        out<<password;
        out.close();
        in.close();
        main();
    }
}