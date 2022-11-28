#ifndef TRABALHOFINALPOO_22_HANDLER_HPP
#define TRABALHOFINALPOO_22_HANDLER_HPP

#include "../commands/CommandHandler.hpp"
#include "../simulation/Simulation.hpp"
#include "../utils/utils.hpp"
#include "../utils/Terminal.h"

#define TOP 0
#define BOTTOM 2
#define LEFT 1
#define RIGHT 3

namespace tppoo {

    class Handler {
    private:
        static bool running;
        CommandHandler *cmd;
        Simulation *sim;
        std::unordered_map<std::string, Simulation *> *simulations;
        Random *rand;
        std::string active;
        term::Terminal &term = term::Terminal::instance();
        // Simulation coords
        term::Window topCoordsWindow = term.create_window(2, 1, 7, 1, false);
        term::Window botCoordsWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(MAX_X_SIZE - 1 - (MAX_X_SIZE - Simulation::getNC()), 19, 7, 1, false) :
                term.create_window(52, 19, 7, 1, false);

        // Simulation Borders
        term::Window topBorderWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(2,2,MAX_X_SIZE - (MAX_X_SIZE - Simulation::getNC()) + 4,1, false)
                : term.create_window(2,2,57,1, false);
        term::Window botBorderWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(2, 18,MAX_X_SIZE - (MAX_X_SIZE - Simulation::getNC()) + 4,1, false)
                : term.create_window(2,18,57,1, false);
        term::Window rightBorderWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(MAX_X_SIZE - (MAX_X_SIZE - Simulation::getNC()) + 4, 3, 2, 15, false)
                : term.create_window(57,3,2,15, false);
        term::Window leftBorderWindow = term.create_window(2,3,2,15, false);
    public:
        // Windows
        term::Window simulationWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(4, 3, MAX_X_SIZE - (MAX_X_SIZE - Simulation::getNC()), MAX_Y_SIZE, false)
                : term.create_window(4, 3, 53, 15, false);
        term::Window historyWindow = Simulation::getNC() < MAX_X_SIZE ?
                term.create_window(61 - (MAX_X_SIZE - Simulation::getNC()), 1, 57 + (MAX_X_SIZE - Simulation::getNC()), 19)
                : term.create_window(61, 1, 57, 19);
        term::Window commandWindow = term.create_window(2, 21, 116, 8);

        static Handler* instance;
        Handler();
        ~Handler();
        CommandHandler *getCommandHandler() const;
        Simulation *getSimulation() const;
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
        void updateCoords();
        void updateBorder(int b, char c);
    };

}

#endif
