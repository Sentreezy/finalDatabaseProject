#include "customer.h"
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>

using namespace std;


void newCustomer() {

    cout << "----------------------------------------------------------" << endl
        << "                  Customer Information                    " << endl
        << "----------------------------------------------------------" << endl;
    customer c;

    cout << "First Name:" << endl;
    getline(cin, c.firstName);


    cout << "Last Name:" << endl;
    getline(cin, c.lastName);

    cout << "Street Number:" << endl;
    getline(cin, c.streetNum);

    bool flag = true;
    while (flag) {
        try {
            int i = stoi(c.streetNum);
            break;
        }
        catch (exception e) {
            cout << "Invalid Street Number, please try again" << endl;
            getline(cin, c.streetNum);
        }
    }

    cout << "Street Name:" << endl;
    getline(cin, c.streetName);

    cout << "City:" << endl;
    getline(cin, c.city);

    cout << "2 Letter State Abbreviation:" << endl;
    getline(cin, c.state);

    cout << "5-digit Zip Code:" << endl;
    getline(cin, c.zipCode);

    cout << "Email:" << endl;
    getline(cin, c.email);

    cout << "Card Number:" << endl;
    getline(cin, c.cardNumber);

    flag = true;

    while (flag) {
        try {
            int i = stoi(c.cardNumber);
            break;
        }
        catch (exception e) {
            cout << "Invalid Card Number, please try again" << endl;
            getline(cin, c.cardNumber);
        }
    }

    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

    static string server = "tcp://127.0.0.1";
    static string username = "azureuser";
    static string password = "Password1!";

   
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << e.what() << endl;
        system("pause");
        exit(1);
    }

    con->setSchema("finalprojectdb");
    stmt = con->createStatement();
    pstmt = con->prepareStatement("INSERT INTO customer(FirstName, LastName, StreetNum, StreetName, City, State, Zip, Email, CardNum) VALUES(?,?,?,?,?,?,?,?,?)");
    pstmt->setString(1, c.firstName);
    pstmt->setString(2, c.lastName);
    pstmt->setString(3, c.streetNum);
    pstmt->setString(4, c.streetName);
    pstmt->setString(5, c.city);
    pstmt->setString(6, c.state);
    pstmt->setString(7, c.zipCode);
    pstmt->setString(8, c.email);
    pstmt->setString(9, c.cardNumber);
    pstmt->execute();
    cout << "Customer entered into database successfully." << endl;
    delete con, stmt, pstmt;
    
}



