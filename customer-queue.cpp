#include <iostream>
using namespace std;

int main()
{
    int queue[5];
    int front = 0;
    int rear = 0;

    cout << "enter 5 customers order \n";

    for (int i = 0; i < 5; i++)
    {
        cin >> queue[rear];
        rear++;
    }

    cout << "\nprocessing orders\n";

    while (front < rear)
    {
        cout << "orders processed: " << queue[front] << endl;
        front++;
    }

    return 0;
}

