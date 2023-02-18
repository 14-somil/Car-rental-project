void customer()
{
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
        cout<<"\b\b\b\b\b\b";
        cout<<"Sorry, no cars available";
    }
    
}