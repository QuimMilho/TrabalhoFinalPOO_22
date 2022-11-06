#include <iostream>
#include "Handler.hpp"
#include "../exceptions/AlreadyRunning.hpp"

namespace tppoo {

    bool Handler::running = false;
    Handler *Handler::instance = nullptr;

    Handler::Handler() {
        cmd = new CommandHandler();
        sim = new Simulation();
        rand = new Random();
    }

    Handler::~Handler() {
        delete cmd;
        delete sim;
        delete rand;
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

    int Handler::random(int n) {
        return rand->random(n);
    }

    int Handler::random(int a, int b) {
        return rand->random(a, b);
    }

}