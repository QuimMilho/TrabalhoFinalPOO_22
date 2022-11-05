#ifndef TRABALHOFINALPOO_22_SIMULATION_H
#define TRABALHOFINALPOO_22_SIMULATION_H

#include "../entities/Entity.h"

#include <unordered_map>
#include <vector>

namespace tppoo {

    class Simulation {
    private:
        static int nl;
        static int nc;
        std::unordered_map<std::string, int> *vars;
        std::vector<Entity *> *entities;
    public:
        Simulation();
        ~Simulation();
        static int getNL();
        static int getNC();
        static void setNL(int nl);
        static void setNC(int nc);
        void tick();
        void render();
        void tickMultiple(int n);
        void tickTimed(int n, int t);
        void start();
        void loadConfigFile();
    };

}

#endif
