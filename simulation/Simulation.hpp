#ifndef TRABALHOFINALPOO_22_SIMULATION_HPP
#define TRABALHOFINALPOO_22_SIMULATION_HPP

#include "../entities/Entity.hpp"

#include <unordered_map>
#include <vector>

namespace tppoo {

    class Simulation {
    private:
        static int nl;
        static int nc;
        int x, y;
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
        void tickMultiple(int n, int t);
        void start();
        void loadConfigFile();
        void addOffset(int x, int y);
        void addXOffset(int x);
        void addYOffset(int y);
        int getXOffset();
        int getYOffset();
        void summon(Entity * ent);
        void kill(int i);
        int getNEntities();
        Entity *getEntity(int n);
        int getVar(std::string varName);
    };

}

#endif
