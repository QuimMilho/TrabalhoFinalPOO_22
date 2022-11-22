#include "Coelho.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../handler/Handler.hpp"

namespace tppoo {

    Coelho::Coelho(int x, int y, int weight) : Animal('C', x, y, weight, 0, 4, 20) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SCoelho");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
        try {
            maxLifetime = Handler::instance->getSimulation()->getVar("VCoelho");
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Coelho::~Coelho() = default;

    int Coelho::tick() {
        addLifetime();
        if (getLifetime() > maxLifetime) {
            kill();
            return 1;
        }
        std::vector<Entity *> v;

        setHunger(getHunger() + 1);
        if (getHunger() > 10) {
            setLife(getLife() - 1);
        } else if (getHunger() > 20) {
            setLife(getLife() - 2);
        }
        if (isDead()) return 1;

        int k;
        if (getHunger() > 10) {
            k = Handler::instance->random(1, 3);
        } else if (getHunger() > 20) {
            k = Handler::instance->random(1, 4);
        } else {
            k = Handler::instance->random(1, 2);
        }

        for (int i = 0; i < k; i++) {
            v = Handler::instance->getSimulation()->getEntitiesInside(getX() - getPerc(),
                  getY() - getPerc(),getX() + getPerc(), getY() + getPerc());
            //North, South, West, East
            bool mov[4] = {false, false, false, false};
            for (Entity * e : v) {

            }
        }

        if (getLifetime() % 8 == 0) {

        }

        return 0;
    }

    bool Coelho::isCoelho() const {
        return true;
    }

}
