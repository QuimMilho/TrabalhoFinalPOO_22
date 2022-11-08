#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_SIMULATIONNOTFOUND_HPP
#define TRABALHOFINALPOO_22_SIMULATIONNOTFOUND_HPP

namespace tppoo {

    class SimulationNotFound : std::exception {
    public:
        std::string what() {
            return "Simulacao nao encontrada!";
        }
    };

}

#endif
