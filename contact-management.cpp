#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* next;
};

Contact* head = NULL;


void addContact(string name, string phone) {
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->phone = phone;
    newContact->next = head;
    head = newContact;

    cout << "Contact added successfully!\n";
}
void displayContacts() {
    if (head == NULL) {
        cout << "No contacts available.\n";
        return;
    }

    Contact* temp = head;
    while (temp != NULL) {
        cout << "\nName: " << temp->name;
        cout << "\nPhone: " << temp->phone << "\n";
        temp = temp->next;
    }
}
void searchContact(string name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "\nContact Found:";
            cout << "\nName: " << temp->name;
            cout << "\nPhone: " << temp->phone << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Contact not found.\n";
}
void deleteContact(string name) {
    Contact *temp = head, *prev = NULL;

    if (temp != NULL && temp->name == name) {
        head = temp->next;
        delete temp;
        cout << "Contact deleted.\n";
        return;
    }

    while (temp != NULL && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Contact not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Contact deleted.\n";
}
int main() {
    int choice;
    string name, phone;

    while (true) {
        cout << "\n------`` Contact Management System ```------\n";
        cout << "1. Add a new Contact\n2. Display Contacts\n3. Search for Contact\n4. Delete Contact\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name of person: ";
                cin >> name;
                cout << "Enter Phone number: ";
                cin >> phone;
                addContact(name, phone);
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                cout << "Enter the Name to search: ";
                cin >> name;
                searchContact(name);
                break;

            case 4:
                cout << "Enter the Name to delete: ";
                cin >> name;
                deleteContact(name);
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid choice!\n";
        }
    }
}