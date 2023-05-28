//
// Created by venom on 5/28/23.
//

#include "Database_Handler.h"

Database::Connection::Connection(const std::string& host, const std::string& username, const std::string& password) {
    try {
        this->driver = sql::mysql::get_mysql_driver_instance();
        this->con = this->driver->connect(host, username, password);
        this->result = nullptr;
    } catch (sql::SQLException& e) {
        throw std::runtime_error("Failed to connect to the database: " + std::string(e.what()));
    }
}
Database::Connection::~Connection() {
    if (this->con != nullptr) {
        this->con->close();
        delete this->con;
    }
}

void Database::Connection::executeQuery(const std::string& query) {
    try {
        sql::Statement* stmt = this->con->createStatement();
        this->result=stmt->executeQuery(query);
    } catch (sql::SQLException& e) {
        throw std::runtime_error("Failed to execute query: " + std::string(e.what()));
    }
}

void Database::Connection::printQueryResults() {
    int numColumns = (int)this->result->getMetaData()->getColumnCount();

    // Print column names
    for (int i = 1; i <= numColumns; ++i) {
        std::cout << std::setw(15) << this->result->getMetaData()->getColumnName(i) << " ";
    }
    std::cout << std::endl;

    // Print separator line
    for (int i = 1; i <= numColumns; ++i) {
        std::cout << std::setw(15) << std::setfill('-') << "" << " ";
    }
    std::cout << std::endl;

    // Print row data
    while (this->result->next()) {

        for (int i = 1; i <= numColumns; ++i) {
            sql::SQLString columnValue = this->result->getString(i);
            std::cout << std::setw(15) << std::setfill(' ');

            // Check the column's data type and retrieve the value accordingly
            switch (this->result->getMetaData()->getColumnType(i)) {
                case sql::DataType::VARCHAR:
                case sql::DataType::CHAR:
                    std::cout << columnValue;
                    break;
                case sql::DataType::INTEGER:
                    std::cout << this->result->getInt(i);
                    break;
                case sql::DataType::DECIMAL:
                case sql::DataType::DOUBLE:
                    std::cout << this->result->getDouble(i);
                    break;
                    // Add cases for other data types as needed
                default:
                    std::cout << columnValue;
                    break;
            }

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Database::Connection::close() {
    (this->result != nullptr ) ? delete this->result : void () ;
}
