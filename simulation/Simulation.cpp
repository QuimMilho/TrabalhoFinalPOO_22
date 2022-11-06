#include <iostream>
#include "Simulation.h"
#include "../utils/utils.h"
#include "../handler/Handler.h"
#include "../exceptions/CommandNotFound.h"

namespace tppoo {

    int Simulation::nc = 0;
    int Simulation::nl = 0;

    Simulation::Simulation() {
        vars = new std::unordered_map<std::string, int>();
        entities = new std::vector<Entity *>;
        loadConfigFile();
    }

    Simulation::~Simulation() {
        delete vars;
        for (Entity *e : *entities) {
            delete e;
        }
        delete entities;
    }

    void Simulation::loadConfigFile() {

    }

    int Simulation::getNL() {
        return nl;
    }

    int Simulation::getNC() {
        return nc;
    }

    void Simulation::setNL(int value) {
        nl = value;
    }

    void Simulation::setNC(int value) {
        nc = value;
    }

    void Simulation::tick() {

    }

    void Simulation::render() { // 120x30

    }

    void Simulation::tickMultiple(int n) {
        for (int i = 0; i < n; i++) {
            tick();
        }
        render();
    }

    void Simulation::tickTimed(int n, int t) {
        int i = 0;
        long long startTime = getCurrentTime();
        long long now, offset = 0;
        while (i < n) {
            now = getCurrentTime();
            if (startTime + offset - now > t * 1000 || i == 0) {
                tick();
                render();
                offset += (t * 1000);
                i++;
            }
        }
    }

    void Simulation::start() {
        int exit;
        CommandHandler * cmdHand = Handler::instance->getCommandHandler();
        render();
        do {
            std::string cmd;
            std::cout << ">";
            std::getline(std::cin, cmd);
            try {
                exit = cmdHand->executeCommand(cmd);
            } catch (CommandNotFound& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            }
        } while (!exit);
    }

}