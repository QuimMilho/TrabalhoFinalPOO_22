#include "ArgsHandler.h"
#include "../exceptions/InvalidArguments.h"
#include "../utils/utils.h"
#include "../exceptions/NotANumber.h"
#include <iostream>
#include <string>

namespace tppoo {

    int preProcessArgs(int argc, char* argv[]) {
        std::string strs[argc];
        int i;
        for (i = 0; i < argc; i++) {
            strs[i] = argv[i];
        }
        switch (argc) {
            case 1:
                printOptions();
                break;
            default:
                try {
                    int* k = processArgs(argc, strs);
                } catch (InvalidArguments& e) {
                    throw e;
                } catch (NotANumber& e) {
                    throw e;
                }
        }
        return 0;
    }

    void printOptions() {
        std::cout << "Arguments" << std::endl;
        std::cout << "-N <numero de linhas> <numero de colunas> :" << std::endl;
        std::cout << EXPLANATION_SPACES << "Numero de linhas e colunas da simulacao" << std::endl;
        std::cout << "-NL <number> :" << std::endl;
        std::cout << EXPLANATION_SPACES << "Numero de linhas da simulacao." << std::endl;
        std::cout << EXPLANATION_SPACES << "Requer -NC para funcionar" << std::endl;
        std::cout << "-NC <number> :" << std::endl;
        std::cout << EXPLANATION_SPACES << "Numero de colunas da simulacao." << std::endl;
        std::cout << EXPLANATION_SPACES << "Requer -NL para funcionar" << std::endl;
    }

    int* processArgs(int argc, std::string* strs) {
        int i = 1;
        int k[2] = {0, 0};
        while (i < argc) {
            if (strs[i] == "-N") {
                i++;
                if (isNumber(strs[i])) {
                    k[0] = toNumber(strs[i]);
                } else {
                    throw NotANumber();
                }
                i++;
                if (isNumber(strs[i])) {
                    k[1] = toNumber(strs[i]);
                } else {
                    throw NotANumber();
                }
            } else if (strs[i] == "-NL") {
                i++;
                if (isNumber(strs[i])) {
                    k[0] = toNumber(strs[i]);
                } else {
                    throw NotANumber();
                }
            } else if (strs[i] == "-NC") {
                i++;
                if (isNumber(strs[i])) {
                    k[1] = toNumber(strs[i]);
                } else {
                    throw NotANumber();
                }
            } else {
                throw InvalidArguments();
            }
            i++;
        }
        std::cout << k[0] << " " << k[1];
        return k;
    }

}