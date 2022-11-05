#include "utils.h"
#include "../exceptions/NotANumber.h"

namespace tppoo {

    bool isNumber(std::string& str) {
        for (char c : str) {
            if (!std::isdigit(c))
                return false;
        }
        return true;
    }

    int toNumber(std::string& str) {
        int a = 0;
        if (!isNumber(str)) throw NotANumber();
        for (char c : str) {
            a = a * 10 + (c - '0');
        }
        return a;
    }

    int countArgs(std::string& str) {
        int a = 0;
        for (int i = 0; i < str.length() - 1; i++) {
            if (str.at(i + 1) != ' ' && str.at(i) == ' ')
                a++;
        }
        return a;
    }

}