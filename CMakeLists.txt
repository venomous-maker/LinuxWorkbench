cmake_minimum_required(VERSION 3.25)
project(LinuxWorkBench)

set(CMAKE_CXX_STANDARD 17)

# Find the MySQL Connector/C++ library
find_library(MYSQL_CONNECTOR_CPP_LIB mysqlcppconn)

# Add compilation flags
add_compile_options(-Wall -Wextra -Werror)

# Or, add definitions
add_definitions(-DDEBUG_MODE)

add_executable(LinuxWorkBench src/main.cpp src/Database_Handler.h src/Database_Handler.cpp src/Std_Cust_Lib.cpp src/Std_Cust_Lib.h)

# Link against the MySQL Connector/C++ library
target_link_libraries(LinuxWorkBench ${MYSQL_CONNECTOR_CPP_LIB})
