#include "searchByParam.h"
#include <iostream>
#include <string>

using namespace std;


void searchMenu() {
    cout << "----------------------------------------------------------" << endl
        << "                     Customer Search                      " << endl
        << "----------------------------------------------------------" << endl
        << "Which piece of information would you like to lookup?" << endl
        << "(1) Last Name" << endl
        << "(2) Email" << endl
        << "(0) Return to Main Menu" << endl;

    char choice = 'q';
    string newline;
    bool submenu = true;
    while (submenu) {

        cin >> choice;
        getline(cin, newline);
        switch (choice) {

        case '1':
            searchByParam("LastName");
            submenu = false;
            break;

        case '2':
            searchByParam("Email");
            submenu = false;
            break;

        case '0':
            submenu = false;
            break;

        default:
            cout << "Input not recognized, please try again." << endl;
            break;
        }
    }

}