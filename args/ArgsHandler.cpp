#include "ArgsHandler.h"
#include "../exceptions/InvalidArguments.h"
#include <iostream>
#include <string>
#include <sstream>

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
                }
        }
        return 0;
    }

    void printOptions() {
        std::cout << "Arguments" << std::endl;
        std::cout << "-N <numero de linhas> <numero de colunas> :" << std::endl;
        std::cout << "" << "Numero de linhas e colunas da simulacao" << std::endl;
        std::cout << "-NL <number> :" << std::endl;
        std::cout << "" << "Numero de linhas da simulacao." << std::endl;
        std::cout << "" << "Requer -NC para funcionar" << std::endl;
        std::cout << "-NC <number> :" << std::endl;
        std::cout << "" << "Numero de colunas da simulacao." << std::endl;
        std::cout << "" << "Requer -NL para funcionar" << std::endl;
    }

    int* processArgs(int argc, std::string* strs) {
        int i = 0;
        while (i < argc) {
            if (strs[i] == "-N") {

            } else if (strs[i] == "-NL") {

            } else if (strs[i] == "-NC") {

            } else {
                throw InvalidArguments();
            }
            i++;
        }

    }

}