#ifndef TRABALHOFINALPOO_22_HANDLER_HPP
#define TRABALHOFINALPOO_22_HANDLER_HPP

#include "../commands/CommandHandler.hpp"
#include "../simulation/Simulation.hpp"
#include "../utils/utils.hpp"

namespace tppoo {

    class Handler {
    private:
        CommandHandler *cmd;
        Simulation *sim;
        Random *rand;
        static bool running;
    public:
        static Handler* instance;
        Handler();
        ~Handler();
        CommandHandler *getCommandHandler();
        Simulation *getSimulation();
        int random(int n);
        int random(int a, int b);
        void start();
    };

}

#endif
