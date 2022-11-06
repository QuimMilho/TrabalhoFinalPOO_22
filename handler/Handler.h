#ifndef TRABALHOFINALPOO_22_HANDLER_H
#define TRABALHOFINALPOO_22_HANDLER_H

#include "../commands/CommandHandler.h"
#include "../simulation/Simulation.h"

namespace tppoo {

    class Handler {
    private:
        CommandHandler *cmd;
        Simulation *sim;
        static bool running;
    public:
        static Handler* instance;
        Handler();
        ~Handler();
        CommandHandler *getCommandHandler();
        Simulation *getSimulation();
        void start();
    };

}

#endif
