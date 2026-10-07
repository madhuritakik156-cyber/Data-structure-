#include<iostream>
using namespace std;

void menu()
{
    int choice;

    cout<<"\n\n---restaurent menu---";
    cout<<"\n1.Pizza";
    cout<<"\n2.burger";
    cout<<"\n3.pasta";

    cout<<"\nenter your choice:";
    cin>>choice;

    if (choice==1)
    {
        cout<<"seleceted choice is pizza";
        menu();
    }
    else if (choice==2)
    {
        cout<<"selected choice is burger";
        menu();
    }
    else if (choice==3)
    {
        cout<<"selected choice is pasta";
        menu();
    }
    else if (choice==4)
    {
        cout<<"\nthank you!";
    }
    else
    {
        cout<<"\ninvalid choice";
        menu();
    }
}

int main()
{
    menu();

    return 0;
}

