#include <iostream>
#include <string>
using namespace std;

int main()
{
    int id1, id2 , id3;
    string title1, title2,  title3;

    cout << "Enter id 1: ";
    cin >>id1;
    cin.ignore();

    cout << "Enter title 1 of Book: ";
    getline(cin, title1);

    cout << "Enter id 2";
    cin >> id2;
    cin.ignore();

    cout << "Enter title 2 of Book: ";
    getline(cin, title2);

    cout << "Enter id 3: ";
    cin >>id3;
    cin.ignore();

    cout <<"Enter title 3 of Book: ";
    getline(cin, title3);

    return 0;
}
    
