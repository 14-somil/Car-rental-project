void customer()
{
    system("cls");
    ifstream in("data/cars");
    int count=0;
    string brand;
    cout<<"Type:\n";
    while(in>>brand)
    {
        string model, data;
        in>>model>>data;
        if(data=="1")
        {
            count++;
            cout<<count<<": for "<<brand<<" "<<model<<endl;
        }
        in>>data;
    }
    if(count==0)
    {
        system("cls");
        cout<<"Sorry, no cars available\n";
        cout<<"Enter anything to continue\n";
        string temp;
        cin>>temp;
        in.close();
        user="";
        main();
    }
    else
    {
        int option;
        cin>>option;
        ifstream copy("data/cars");
        ofstream out("data/temp");
        int counter=0;
        string data;
        while(copy>>data)
        {
            counter++;
            out<<data<<'\t';
            copy>>data;
            out<<data<<'\t';
            if(counter==option)
            {
                out<<"0"<<'\t';
                out<<user;
                copy>>data;
                copy>>data;
            }
            else
            {
                copy>>data;
                out<<data<<'\t';
                copy>>data;
                out<<data;
            }
            out<<endl;
        }
        copy.close();
        out.close();
        in.close();
        remove("data/cars");
        rename("data/temp","data/cars");
        cout<<"The car has been rented to "<<user<<endl;
        user="\0";
        is_login=false;
        cout<<"Type anything to continue\n";
        string temp;
        cin>>temp;
        main();
    }
}