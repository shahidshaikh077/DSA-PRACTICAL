#include <iostream>
#include <cstring>
using namespace std;

struct Employee
{
    int id;
    char name[100];
    float salary;
    Employee* next;
};

Employee* head = NULL;

// Function to enter employee details
void enterEmployeeDetails()
{
    Employee* newNode = new Employee;

    cout << "\nEnter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    cout << "Enter Employee Salary: ";
    cin >> newNode->salary;

    newNode->next = head;
    head = newNode;

    cout << "\nEmployee Details Entered Successfully\n";
}

// Function to delete employee details
void deleteEmployeeDetails(int id)
{
    Employee* temp = head;
    Employee* prev = NULL;

    // If list is empty
    if (head == NULL)
    {
        cout << "\nEmployee Records Not Found\n";
        return;
    }

    // If first node contains the ID
    if (temp != NULL && temp->id == id)
    {
        head = temp->next;
        delete temp;

        cout << "\nEmployee Details Deleted Successfully\n";
        return;
    }

    // Search for the employee
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Employee not found
    if (temp == NULL)
    {
        cout << "\nEmployee Not Found\n";
        return;
    }

    // Delete the node
    prev->next = temp->next;
    delete temp;

    cout << "\nEmployee Details Deleted Successfully\n";
}

// Function to search employee details
void searchEmployeeDetails(int id)
{
    Employee* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nEmployee Details Found:\n";
            cout << "Employee ID: " << temp->id << endl;
            cout << "Employee Name: " << temp->name << endl;
            cout << "Employee Salary: " << temp->salary << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nEmployee Not Found\n";
}

// Function to display all employee details
void displayEmployeeDetails()
{
    Employee* temp = head;

    if (temp == NULL)
    {
        cout << "\nEmployee Details Not Found\n";
        return;
    }

    cout << "\nEmployee Records Found:\n";

    while (temp != NULL)
    {
        cout << "\nEmployee ID: " << temp->id;
        cout << "\nEmployee Name: " << temp->name;
        cout << "\nEmployee Salary: " << temp->salary << endl;

        temp = temp->next;
    }
}

// Main function
int main()
{
    int choice, id;

    do
    {
        cout << "\n==== Employee Details Management ====\n";
        cout << "1. Enter Employee Details\n";
        cout << "2. Delete Employee Details\n";
        cout << "3. Search Employee Details\n";
        cout << "4. Display Employee Details\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                enterEmployeeDetails();
                break;

            case 2:
                cout << "\nEnter Employee ID to Delete: ";
                cin >> id;
                deleteEmployeeDetails(id);
                break;

            case 3:
                cout << "\nEnter Employee ID to Search: ";
                cin >> id;
                searchEmployeeDetails(id);
                break;

            case 4:
                displayEmployeeDetails();
                break;

            case 5:
                cout << "\nExiting....\n";
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}

