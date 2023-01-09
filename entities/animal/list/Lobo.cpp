#include "Lobo.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"
#include "../../food/list/Corpo.hpp"
#include "../../../exceptions/OutOfBounds.hpp"

namespace tppoo {

    Lobo::Lobo(int x, int y) : Animal('L', x, y, 15, 0, 5, 25) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SLobo");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
        try {
            int k = Handler::instance->getSimulation()->getVar("VLobo");
            rep = Handler::instance->random(5, k);
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Lobo::~Lobo() = default;

    int Lobo::tick() {
        addLifetime();

        setHunger(getHunger() + 2);
        if (getHunger() > 25) {
            setLife(getLife() - 2);
        } else if (getHunger() > 15) {
            setLife(getLife() - 1);
        }
        if (isDead()) return 1;

        int k = 1, maxSteps = 1;
        if (getHunger() > 15) {
            k = Handler::instance->random(1, 2);
            maxSteps = 2;
        }

        std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(
                getX() - getPerc(), getY() - getPerc(),getX() + getPerc(), getY() + getPerc());
        int goalX = -1, goalY = -1, p = 0, maxDis = 0;

        for (Entity * e : v) {
            if (e->isAnimal()) {
                Animal * a = (Animal *) e;
                if (isBetweenOrEquals(e->getX(), e->getY(), getX() - 1, getY() - 1, getX() + 1, getY() + 1)) {
                    if (a->getWeight() < getWeight()) {
                        a->kill();
                        continue;
                    } else {
                        if (Handler::instance->random(a->getWeight() + getWeight()) < getWeight()) {
                            kill();
                            return 1;
                        } else a->kill();
                    }
                }
                if (a->getWeight() > maxDis && p != 2) {
                    if (p != 1) {
                        p = 1;
                        if (getHunger() > 15) {
                            k = 3;
                        } else {
                            k = 2;
                        }
                    }
                    maxDis = a->getWeight();
                    goalX = a->getX();
                    goalY = a->getY();
                }
            } else {
                Food * f = (Food *) e;
                if (contains(f->getSmells(), "carne")) {
                    if (p != 2) {
                        maxDis = INT_MAX;
                    }
                    if (k < maxSteps) k = maxSteps;
                    int dis = abs(getX() - f->getY()) + abs(getY() - f->getY());
                    if (maxDis > dis) {
                        goalX = f->getX();
                        goalY = f->getY();
                        p = 2;
                        maxDis = dis;
                    }
                }

            }
        }

        move(goalX, goalY, k);

        eat();

        if (isDead()) return 1;

        if (getLifetime() == rep) {
            reproduce(15);
        }

        return 0;
    }

    bool Lobo::isLobo() const {
        return true;
    }

    void Lobo::kill() {
        if (isDead()) throw EntityAlreadyDead();
        setDead();
        try {
            Handler::instance->getSimulation()->summon(new Corpo(getX(), getY(), 10, 0));
        } catch (OutOfBounds &e) {
            e.what();
        }
    }

}