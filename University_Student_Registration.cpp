#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    string course;
    Student* next;
    Student* hashNext;
};

Student* head = NULL;
const int SIZE = 10;
Student* hashTable[SIZE] = {NULL};

int hashFunction(int rollNo)
{
    return rollNo % SIZE;
}


void addStudent()
{
    Student* p = new Student;

    cout << "Enter Roll Number: ";
    cin >> p->rollNo;

    int index = hashFunction(p->rollNo);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == p->rollNo)
        {
            cout << "Roll Number already exists!\n";
            delete p;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, p->name);

    cout << "Enter Course Name: ";
    getline(cin, p->course);

    p->next = head;
    head = p;

    p->hashNext = hashTable[index];
    hashTable[index] = p;

    cout << "Student Registered Successfully!\n";
}


void displayStudent()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "No Student Records Found!\n";
        return;
    }

    cout << "\n--- All Student Records ---\n";

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Student Name: " << temp->name << endl;
        cout << "Course Name: " << temp->course << endl;

        temp = temp->next;
    }
}


Student* searchStudent(int rollNo)
{
    int index = hashFunction(rollNo);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
            return temp;

        temp = temp->hashNext;
    }

    return NULL;
}


void updateStudent()
{
    int rollNo;

    cout << "Enter Roll Number to Update: ";
    cin >> rollNo;

    Student* p = searchStudent(rollNo);

    if (p == NULL)
    {
        cout << "Student Not Found!\n";
        return;
    }

    cout << "Enter New Student Name: ";
    cin >> ws;
    getline(cin, p->name);

    cout << "Enter New Course Name: ";
    getline(cin, p->course);

    cout << "Student Updated Successfully!\n";
}


void enrollStudent()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    Student* p = searchStudent(rollNo);

    if (p == NULL)
    {
        cout << "Student Not Found!\n";
        return;
    }

    cout << "Enter Course Name: ";
    cin >> ws;
    getline(cin, p->course);

    cout << "Student Enrolled Successfully!\n";
}

// Withdraw Student
void withdrawStudent()
{
    int rollNo;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    Student* p = searchStudent(rollNo);

    if (p == NULL)
    {
        cout << "Student Not Found!\n";
        return;
    }

    p->course = "No Course";

    cout << "Student Withdrawn Successfully!\n";
}

// Delete Student
void deleteStudent()
{
    int rollNo;

    cout << "Enter Roll Number to Delete: ";
    cin >> rollNo;

    Student* p = searchStudent(rollNo);

    if (p == NULL)
    {
        cout << "Student Not Found!\n";
        return;
    }

    int index = hashFunction(rollNo);

    // Delete from Linked List
    if (head == p)
    {
        head = head->next;
    }
    else
    {
        Student* temp = head;

        while (temp->next != p)
        {
            temp = temp->next;
        }

        temp->next =     ete from Hash Table
    if (hashTable[index] == p)
    {
        hashTable[index] = p->hashNext;
    }
    else
    {
        Student* temp = hashTable[index];

        while (temp->hashNext != p)
        {
            temp = temp->hashNext;
        }

        temp->hashNext = p->hashNext;
    }

    delete p;

    cout << "Student Deleted Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n==== UNIVERSITY STUDENT REGISTRATION SYSTEM ====\n";
        cout << "1. ADD STUDENT\n";
        cout << "2. UPDATE STUDENT\n";
        cout << "3. SEARCH STUDENT\n";
        cout << "4. DISPLAY ALL STUDENTS\n";
        cout << "5. ENROLL STUDENT\n";
        cout << "6. WITHDRAW STUDENT\n";
        cout << "7. DELETE STUDENT\n";
        cout << "8. EXIT\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                updateStudent();
                break;

            case 3:
            {
                int rollNo;

                cout << "Enter Roll Number: ";
                cin >> rollNo;

                Student* p = searchStudent(rollNo);

                if (p != NULL)
                {
                    cout << "STUDENT FOUND!\n";
                    cout << "Name: " << p->name << endl;
                    cout << "Course: " << p->course << endl;
                }
                else
                {
                    cout << "Student Not Found!\n";
                }
                break;
            }

            case 4:
                displayStudent();
                break;

            case 5:
                enrollStudent();
                break;

            case 6:
                withdrawStudent();
                break;

            case 7:
                deleteStudent();
                break;

            case 8:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    
    Student* temp = head;

    while (temp != NULL)
    {
        Student* del = temp;
        temp = temp->next;
        delete del;
    }

    return 0;
}
