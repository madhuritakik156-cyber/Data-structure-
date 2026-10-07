#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> history;
    int t;

    cout<<"Enter 5 reacently served token numbers:\n";
    for (int i = 0; i < 5; i++)
        {
            cin>>t;
            history.push(t);
        }

    cout<<"\nRecent service history (most recent first):\n";
    while (!history.empty())
        {
            cout<<"Token "<<history.top()<<"\n";
            history.pop();
        }
    return 0;
}
