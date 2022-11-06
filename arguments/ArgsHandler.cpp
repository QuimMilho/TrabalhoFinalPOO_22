#include "../utils/utils.h"
#include "ArgsHandler.h"
#include "../exceptions/InvalidArguments.h"
#include "../exceptions/NotANumber.h"
#include "../exceptions/OutOfBounds.h"
#include "../simulation/Simulation.h"

#include <iostream>
#include <string>
#include <sstream>

namespace tppoo {

    int ArgsHandler::processArgs(int argc, char* argv[]) {
        if (argc == 1) {
            printInfo();
            return 1;
        } else {
            postProcessArgs(argc, argv);
            return 0;
        }
    }

    void ArgsHandler::printInfo() {
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

    void ArgsHandler::postProcessArgs(int argc, char * argv[]) {
        std::string str;
        std::stringstream ss(str);
        for (int i = 1; i < argc; i++) {
            ss << argv[i] << " ";
        }
        for (int i = 0; i < argc - 1; i++) {
            std::string temp;
            ss >> temp;
            if (temp == "-N") {
                ss >> temp;
                i++;
                int nl = toNumber(temp);
                if (nl < 16 || nl > 500) throw OutOfBounds();
                if (Simulation::getNL() != 0) throw InvalidArguments();
                Simulation::setNL(nl);

                ss >> temp;
                i++;
                int nc = toNumber(temp);
                if (nc < 16 || nc > 500) throw OutOfBounds();
                if (Simulation::getNC() != 0) throw InvalidArguments();
                Simulation::setNC(nc);

            } else if (temp == "-NL") {
                ss >> temp;
                i++;
                int nl = toNumber(temp);
                if (nl < 16 || nl > 500) throw OutOfBounds();
                if (Simulation::getNL() != 0) throw InvalidArguments();
                Simulation::setNL(nl);
            } else if (temp == "-NC") {
                ss >> temp;
                i++;
                int nc = toNumber(temp);
                if (nc < 16 || nc > 500) throw OutOfBounds();
                if (Simulation::getNC() != 0) throw InvalidArguments();
                Simulation::setNC(nc);
            } else {
                std::cout << " " << temp;
                throw InvalidArguments();
            }
        }
        if (Simulation::getNC() == 0 || Simulation::getNL() == 0) throw InvalidArguments();
    }

}