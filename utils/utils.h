#ifndef TRABALHOFINALPOO_22_UTILS_H
#define TRABALHOFINALPOO_22_UTILS_H

#include <string>
#include <random>

#define EXPLANATION_SPACES "               "

namespace tppoo {

    bool isNumber(std::string& str);
    int toNumber(std::string& str);
    int countArgs(std::string& str);
    void delay(int n);
    long long getCurrentTime();

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
