#include <iostream>
using namespace std;

int main() {
    int tokens[100];     
    int front = 0;   
    int rear = 0;        
    int nextToken = 1; 
    int choice;

    do {
        cout << "\n--- BANK TOKEN SYSTEM ---\n";
        cout << "1. Issue a token\n";
        cout << "2. Display all tokens\n";
        cout << "3. Serve a customer\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (rear == 100) {
                    cout << "Token list full!\n";
                } else {
                    tokens[rear] = nextToken;
                    cout << "Your token number is: " << nextToken << endl;
                    rear++;
                    nextToken++;
                }
                break;

            case 2:
                if (front == rear) {
                    cout << "No tokens available.\n";
                } else {
                    cout << "Waiting tokens: ";
                    for (int i = front; i < rear; i++) {
                        cout << tokens[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3:
                if (front == rear) {
                    cout << "No customer to serve.\n";
                } else {
                    cout << "Serving token number: " << tokens[front] << endl;
                    front++;
                }
                break;

            case 4:
                cout << "Program ended. Thank you!\n";
                break;

            default:
                cout << "Wrong choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
