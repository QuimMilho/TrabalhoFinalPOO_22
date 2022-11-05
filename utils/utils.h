#ifndef TRABALHOFINALPOO_22_UTILS_H
#define TRABALHOFINALPOO_22_UTILS_H

#include <string>

#define EXPLANATION_SPACES "               "

namespace tppoo {

    bool isNumber(std::string& str);
    int toNumber(std::string& str);
    int countArgs(std::string& str);
    void delay(int n);
    long long getCurrentTime();

}

#endif
