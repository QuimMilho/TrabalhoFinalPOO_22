#ifndef TRABALHOFINALPOO_22_HANDLER_H
#define TRABALHOFINALPOO_22_HANDLER_H

#include "../commands/CommandHandler.h"
#include "../simulation/Simulation.h"
#include "../utils/utils.h"

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
