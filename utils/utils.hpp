#ifndef TRABALHOFINALPOO_22_UTILS_HPP
#define TRABALHOFINALPOO_22_UTILS_HPP

#include <string>
#include <random>

#define EXPLANATION_SPACES "               "

namespace tppoo {

    bool isNumber(std::string& str);
    int toNumber(std::string& str);
    int countArgs(std::string& str);
    void delay(int n);
    long long getCurrentTime();
    bool isBetween(int n, int a, int b);
    bool isBetweenOrEquals(int n, int a, int b);
    bool isBetween(int x, int y, int x1, int y1, int x2, int y2);
    bool isBetweenOrEquals(int x, int y, int x1, int y1, int x2, int y2);

    class Random {
    private:
        std::default_random_engine *generator;
    public:
        Random();
        ~Random();
        int random(int n);
        int random(int a, int b);
    };

}

#endif
