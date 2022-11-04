#include "utils.h"

namespace tppoo {

    bool isNumber(std::string& str) {
        int i;
        for (i = 0; i < str.length(); i++) {
            if (!std::isdigit(str.c_str()[i])) return false;
        }
        return true;
    }

    int toNumber(std::string& str) {
        int a = 0, i;
        for (i = 0; i < str.length(); i++) {
            a = a * 10 + (str.at(i) - '0');
        }
        return a;
    }

}