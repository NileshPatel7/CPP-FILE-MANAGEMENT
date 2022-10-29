#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class readfile{
    
     public:
        int id;
        string item_name;
        int price;    
        
        void display()
        {
            cout<<"id         = "<<id<<endl;
            cout<<"item_name  = "<<item_name<<endl;
            cout<<"price      = "<<price<<endl;

        }
};

int main()
{
    readfile i[50];
    ifstream obj;
    obj.open("itemfile1.txt",ios::app);
    for(int j=0;j<50;j++)
    {
            obj>>i[j].id;
            obj.ignore();
            getline(obj,i[j].item_name);
            obj>>i[j].price;
    }
    for(int j=0;j<50;j++)
    {
        for(int t=0;t<50;t++)
        {
            if(j<t)
                continue;
            else if(i[j].price>i[t].price)
                {
                    readfile obj;
                    obj=i[j];
                    i[j]=i[t];
                    i[t]=obj;
                }
        }
    }
    obj.close();
    ofstream obj1;
    obj1.open("itemfile1.txt");
    for(int t=0;t<50;t++)
    {
        obj1<<i[t].id<<endl;
        obj1<<i[t].item_name<<endl;
        obj1<<i[t].price<<endl;
    }
    obj1.close();
    return 0; 
}
