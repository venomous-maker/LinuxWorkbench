#include <iostream>
#include "Database_Handler.h"
#include "Std_Cust_Lib.h"

int main() {
    try {
        // Establish the connection
        Database::Connection connection("tcp://127.0.0.1:3306", "root", "root");
        std::string query;
        query = std_cust::input("Enter query: ");
        // Execute a query
        connection.executeQuery(query);//SELECT * FROM stima.planned_interruptions

        connection.printQueryResults();

        connection.close();

    } catch (std::exception& e) {
        // Handle any exceptions
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}