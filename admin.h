void add_car();
void search_car();
void available();
void readd();
int main();

void admin()
{
    system("cls");
    cout<<"\nType:\n1: to add a new car\n2: to search a car\n3: to view available car\n4: to unbook a booked car\n5: to exit\n\n";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            add_car();
            admin();
            break;
        }
        
        case 2:
        {
            search_car();
            admin();
            break;
        }

        case 3:
        {
            available();
            admin();
            break;
        }

        case 4:
        {
            readd();
            admin();
            break;
        }

        case 5:
        {
            main();
            is_admin=false;
            is_login=false;
            break;
        }

        default:
        {
            system("cls");
            cout<<"Invalid input\n";
            admin();
            break;
        }
    }
}

void add_car()
{
    system("cls");
    cout<<"Type brand of car\n";
    string brand;
    cin>>brand;

    cout<<"Type model of car\n";
    string model;
    cin>>model;

    ofstream out("data/cars", ios::app);
    out<<brand<<'\t'<<model<<'\t'<<"1"<<'\t'<<"0"<<endl;
    out.close();
}

void search_car()
{
    system("cls");
    ifstream in("data/cars");
    bool check=false;
    cout<<"Type brand of car\n";
    string brand, model, data;
    cin>>brand;
    cout<<"Type model of car\n";
    cin>>model;
    while(in>>data)
    {
        if(data==brand)
        {
            in>>data;
            if(data==model)
            {
                check=true;
                in>>data;
                if(data=="1")
                {
                    cout<<"Car is available\n";
                    break;
                }
                else
                {
                    cout<<"Car is not available";
                    in>>data;
                    cout<<". Rented by \""<<data<<"\"\n";
                    break;
                }
            }
        }
    }
    if(check==false)
    {
        cout<<"Car doesn\'t exist\n";
    }
    in.close();
    cout<<"Type anything to continue\n";
    string temp;
    cin>>temp;

}

void available()
{
    system("cls");
    ifstream in("data/cars");
    cout<<"Available Cars are:\n\n";
    string brand, model;
    int count=0;
    while(in>>brand)
    {
        in>>model;
        string data;
        in>>data;
        if(data=="1")
        {
            cout<<brand<<' '<<model<<endl;
            count++;
        }
        in>>data;
    } 
    cout<<"Type anything to continue\n";
    string temp;
    cin>>temp;
    if(count==0)
    {
        cout<<"No car Available\n";
        cout<<"Type anything to continue\n";
        string temp;
        cin>>temp;
    }
}

void readd()
{
    system("cls");
    ifstream copy("data/cars");
    ofstream out("data/temp");
    cout<<"Type username of user\n";
    string username;
    cin>>username;
    string brand;
    while(copy>>brand)
    {
        string model,data;
        out<<brand<<'\t';
        copy>>model;
        out<<model<<'\t';
        copy>>data;
        if(data=="0")
        {
            out<<"1"<<'\t';
            out<<"0";
            copy>>data;
        }
        else
        {
            out<<data<<'\t';
            copy>>data;
            out<<data;
        }
        out<<endl;
    }
    copy.close();
    out.close();
    remove("data/cars");
    rename("data/temp","data/cars");
    cout<<"Done\nType anything to continue\n";
    string temp;
    cin>>temp;
}