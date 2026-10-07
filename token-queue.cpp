#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> cancelled;
    int o;

    cout<<"Enter 5 cancelled order numbers:\n";
    for (int i = 0; i < 5; i++)
        {
            cin>>o;
            cancelled.push(o);
        }

    cout<<"\ncanclled orders (most recent first):\n";
    while (!cancelled.empty())
        {
            cout<<"Order "<<cancelled.top()<<"\n";
            cancelled.pop();
        }

    return 0;
}

