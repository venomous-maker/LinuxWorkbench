//
// Created by venom on 5/28/23.
//

#include "Std_Cust_Lib.h"

std::string std_cust::input(const std::string& prompt) {
    std::string inputString;
    std::cout << prompt;
    std::getline(std::cin, inputString);
    return inputString;
}
