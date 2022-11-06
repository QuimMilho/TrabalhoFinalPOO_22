#include "utils.h"
#include "../exceptions/NotANumber.h"
#include <chrono>

namespace tppoo {

    bool isNumber(std::string& str) {
        int i = 0;
        if (str.at(i) == '-') {
            i++;
            if (str.length() == 1) return false;
        }
        for (; i < str.length(); i++) {
            if (!std::isdigit(str.at(i)))
                return false;
        }
        return true;
    }

    int toNumber(std::string& str) {
        int a = 0, i = 0;
        if (!isNumber(str)) throw NotANumber();
        bool neg = false;
        if (str.at(i) == '-') {
            i++;
            neg = true;
        }
        for (; i < str.length(); i++) {
            a = a * 10 + (str.at(i) - '0');
        }
        if (neg) a = a * -1;
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

    void delay(int n) {
        long long initTime = getCurrentTime();
        long long timeNow, dif;
        do {
            timeNow = getCurrentTime();
            dif = timeNow - initTime;
        } while (dif < n);
    }

    long long getCurrentTime() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    Random::Random() {
        generator = new std::default_random_engine();
    }

    Random::~Random() {
        delete generator;
    }

    int Random::random(int n) {
        std::uniform_int_distribution<int> distribution(0, n - 1);
        return distribution(*generator);
    }

    int Random::random(int a, int b) {
        std::uniform_int_distribution<int> distribution(a, b - 1);
        return distribution(*generator);
    }

}