#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include "mysql_connection.h"
#include <iomanip>
using namespace std;

void searchByParam(string searchParam) {

    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    string searchStr;

    static string server = "tcp://127.0.0.1";
    static string username = "azureuser";
    static string password = "Password1!";

    cout << "Enter the " << searchParam << endl;
    getline(cin, searchStr);
    string searchStrTemplate = "SELECT * FROM customer WHERE " + searchParam + " = '" + searchStr + "'";

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
    res = stmt->executeQuery(searchStrTemplate);

    cout << "Search Results:" << endl;


    cout << left << setw(8) << setfill(' ') << "Cust ID";
    cout << left << setw(15) << setfill(' ') << "First Name";
    cout << left << setw(15) << setfill(' ') << "Last Name";
    cout << left << setw(10) << setfill(' ') << "Street Num";
    cout << left << setw(20) << setfill(' ') << "Street Name";
    cout << left << setw(15) << setfill(' ') << "City";
    cout << left << setw(5) << setfill(' ') << "Zip";
    cout << left << setw(40) << setfill(' ') << "Email";
    cout << left << setw(15) << setfill(' ') << "Card Num";
    cout << endl;

    while (res->next()) {
        cout << left << setw(8) << setfill(' ') << res->getInt(1);     //ID
        cout << left << setw(15) << setfill(' ') << res->getString(2); //FN
        cout << left << setw(15) << setfill(' ') << res->getString(3); //LN
        cout << left << setw(10) << setfill(' ') << res->getInt(4);     //SN
        cout << left << setw(20) << setfill(' ') << res->getString(5); //SN
        cout << left << setw(15) << setfill(' ') << res->getInt(6);    //C
        cout << left << setw(5) << setfill(' ') << res->getString(7);  //Z
        cout << left << setw(40) << setfill(' ') << res->getString(8); //E
        cout << left << setw(15) << setfill(' ') << res->getInt(9);    //CN
        cout << endl;
    }

    cout << endl;
    system("Pause");
    delete con, stmt;
    
}