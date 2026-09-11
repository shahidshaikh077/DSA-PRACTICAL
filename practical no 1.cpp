#include <iostream>
#include <limits>
using namespace std;

struct Student
{
    char studentName[50];
    int studentId;
    char studentAddress[100];
    char studentContactNumber[15];

    void setCollegeDetails()
    {
        cout << "Enter your name: ";
        cin >> ws;
        cin.getline(studentName, 50);

        cout << "Enter your ID: ";
        cin >> studentId;

        cout << "Enter your address: ";
        cin >> ws;
        cin.getline(studentAddress, 100);

        cout << "Enter your contact number: ";
        cin >> studentContactNumber;
    }

    void showCollegeDetails()
    {
        cout << "\n======= STUDENT DETAILS =======" << endl;
        cout << "Name: " << studentName << endl;
        cout << "ID: " << studentId << endl;
        cout << "Address: " << studentAddress << endl;
        cout << "Contact Number: " << studentContactNumber << endl;
    }
};

int main()
{
    const int MAX_STUDENTS = 100;

    Student s[MAX_STUDENTS];
    Student *ptr = s;

    int n;

    cout << "Enter number of student details: ";
    cin >> n;

    if (n > MAX_STUDENTS || n <= 0)
    {
        cout << "Invalid number of students! Must be between 1 and "
             << MAX_STUDENTS << "." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Enter details for Student "
             << i + 1 << " ---\n";

        (ptr + i)->setCollegeDetails();
    }

    for (int i = 0; i < n; i++)
    {
        (ptr + i)->showCollegeDetails();
    }

    return 0;
}

