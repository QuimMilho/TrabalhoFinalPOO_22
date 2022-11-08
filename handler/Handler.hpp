#ifndef TRABALHOFINALPOO_22_HANDLER_HPP
#define TRABALHOFINALPOO_22_HANDLER_HPP

#include "../commands/CommandHandler.hpp"
#include "../simulation/Simulation.hpp"
#include "../utils/utils.hpp"

namespace tppoo {

    class Handler {
    private:
        static bool running;
        CommandHandler *cmd;
        Simulation *sim;
        std::unordered_map<std::string, Simulation *> *simulations;
        Random *rand;
        std::string active;
    public:
        static Handler* instance;
        Handler();
        ~Handler();
        CommandHandler *getCommandHandler();
        Simulation *getSimulation();
        int random(int n);
        int random(int a, int b);
        void start();
        void setActive(const std::string& name);
        void saveSim(const std::string& name);
        void newSim();
        void newSim(std::string name);
        void deleteSim(std::string name);
        void copySim(Simulation *saved);
        void copySim(Simulation *saved, Simulation *newSim);
        bool simulationExists(const std::string& name);
    };

}

#endif
