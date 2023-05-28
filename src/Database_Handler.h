//
// Created by venom on 5/28/23.
//

#ifndef LINUX_WORKBENCH_DATABASE_HANDLER_H
#define LINUX_WORKBENCH_DATABASE_HANDLER_H

#ifndef LINUX_WORKBENCH_DATABASE_HANDLER_H_INCLUDES
#define LINUX_WORKBENCH_DATABASE_HANDLER_H_INCLUDES
    #include <mysql_driver.h>
    #include <mysql_connection.h>
    #include <cppconn/statement.h>
    #include <cppconn/resultset.h>
    #include <cppconn/exception.h>
    #include <stdexcept>
    #include <iomanip>
#endif //LINUX_WORKBENCH_DATABASE_HANDLER_H_INCLUDES

namespace Database {
    class Connection {
    private:
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::ResultSet* result;

    public:
        Connection(const std::string& host, const std::string& username, const std::string& password);

        ~Connection();

        void executeQuery(const std::string& query);

        void printQueryResults();

        void close();
    };
} // namespace Database
#endif //LINUX_WORKBENCH_DATABASE_HANDLER_H
