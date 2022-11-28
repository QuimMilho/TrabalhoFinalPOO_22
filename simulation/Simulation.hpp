#ifndef TRABALHOFINALPOO_22_SIMULATION_HPP
#define TRABALHOFINALPOO_22_SIMULATION_HPP

#include "../entities/Entity.hpp"

#include <unordered_map>
#include <vector>

#define MAX_X_SIZE 53
#define MAX_Y_SIZE 15

namespace tppoo {

    class Simulation {
    private:
        static int nl;
        static int nc;
        static std::unordered_map<std::string, int> *vars;
        int x, y;
        std::vector<Entity *> *entities;
        bool moved = true;
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
        void loadConfigFile();
        void addOffset(int x, int y);
        void addXOffset(int x);
        void addYOffset(int y);
        int getXOffset() const;
        int getYOffset() const;
        void summon(Entity * ent);
        void kill(int i);
        int getNEntities() const;
        Entity *getEntity(int n) const;
        int getVar(std::string varName) const;
        bool alreadyHasFood(int x, int y);
        std::vector<Entity *> getEntitiesInside(int x1, int y1, int x2, int y2) const;
        void deleteVars();
    };

}

#endif
