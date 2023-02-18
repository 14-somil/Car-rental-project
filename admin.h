void add_car();
void search_car();
void available();

void admin()
{
    cout<<"\nType:\n1: to add a new car\n2: to search a car\n3: to view available car\n\n";
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

        default:
        {
            cout<<"Invalid input\n";
            admin();
            break;
        }
    }
}

void add_car()
{
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
}

void available()
{
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
    if(count==0)
    {
        cout<<"No car Available\n";
    }
}