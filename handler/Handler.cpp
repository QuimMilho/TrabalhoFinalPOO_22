#include <iostream>
#include "Handler.h"
#include "../exceptions/AlreadyRunning.h"

namespace tppoo {

    bool Handler::running = false;
    Handler *Handler::instance = nullptr;

    Handler::Handler() {
        cmd = new CommandHandler();
        sim = new Simulation();
    }

    Handler::~Handler() {
        delete cmd;
        delete sim;
    }

    CommandHandler *Handler::getCommandHandler() {
        return cmd;
    }

    Simulation *Handler::getSimulation() {
        return sim;
    }

    void Handler::start() {
        if (Handler::running) throw AlreadyRunning();
        Handler::running = true;
        sim->start();
    }

}