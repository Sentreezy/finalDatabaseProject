#include "newCustomer.h"
#include "searchMenu.h"
#include "customer.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void printMenu() {
    cout << "----------------------------------------------------------" << endl
         << " Welcome to the EZTechMovie Customer Database Application." << endl
         << "----------------------------------------------------------" << endl
         << "Please enter the number that corresponds with your menu choice: " << endl
         << "(1) Enter a new customer." << endl
         << "(2) Search for an existing customer." << endl
         << "(0) Exit." << endl;
}

int main()
{
    char choice = 'q';
    string newline;
    customer c;
    
    while (true) {

        printMenu();
        cin >> choice;
        getline(cin, newline);

        switch (choice) {

        case '1':
            newCustomer();
            break;

        case '2':
            searchMenu();
            break;
            
        case '0':
            return 0;

        default:
            cout << "Input not recognized, please try again." << endl;
            break;
        }
    }
    
    return 0;
}