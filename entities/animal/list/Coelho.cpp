#include "Coelho.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../handler/Handler.hpp"
#include "../../food/Food.hpp"

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

        int k, maxSteps;
        if (getHunger() > 10) {
            maxSteps = 3;
            k = Handler::instance->random(1, 3);
        } else if (getHunger() > 20) {
            maxSteps = 4;
            k = Handler::instance->random(1, 4);
        } else {
            maxSteps = 2;
            k = Handler::instance->random(1, 2);
        }

        v = Handler::instance->getSimulation()->getEntitiesInside(getX() - getPerc(),
                                                                  getY() - getPerc(),getX() + getPerc(), getY() + getPerc());
        int goalX = -1, goalY = -1, p = 0, maxDis = INT_MAX;
        for (Entity * e : v) {
            if (e->isFood() && p != 2) {
                Food * f = (Food *) e;
                k = maxSteps;
                if (contains(f->getSmells(), "verdura")) {
                    int dis = abs(getX() - f->getY()) + abs(getY() - f->getY());
                    if (dis < maxDis) {
                        p = 1;
                        maxDis = dis;
                        goalX = f->getX();
                        goalY = f->getY();
                    }
                }
            } else {
                k = maxSteps;
                Animal * a = (Animal *) e;
                if (a->getWeight() > 10) {
                    if (p != 2) {
                        p = 2;
                        maxDis = 0;
                        goalX = 0;
                        goalY = 0;
                    }
                    goalX += a->getX();
                    goalY += a->getY();
                    maxDis++;
                }
            }
        }

        if (p == 2) {
            move(goalX / maxDis, goalY / maxDis, k);
        } else {
            move(goalX, goalY, k);
        }

        eat();

        if (isDead()) return 1;

        if (getLifetime() % 8 == 0) {
            if (Handler::instance->random(2) == 1)
                reproduce(10);
        }

        return 0;
    }

    bool Coelho::isCoelho() const {
        return true;
    }

}
