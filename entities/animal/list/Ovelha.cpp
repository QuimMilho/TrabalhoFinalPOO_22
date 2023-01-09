#include "Ovelha.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../food/Food.hpp"
#include "../../../exceptions/OutOfBounds.hpp"
#include "../../food/list/Corpo.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"

namespace tppoo {

    Ovelha::Ovelha(int x, int y, int weight) : Animal('O', x, y, weight, 0, 3, 30) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SOvelha");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
        try {
            maxLifetime = Handler::instance->getSimulation()->getVar("VOvelha");
        } catch (VarNotFound &e) {
            maxLifetime = 35;
            e.what();
        }
    }

    Ovelha::~Ovelha() = default;

    int Ovelha::tick() {
        addLifetime();
        if (getLifetime() > maxLifetime) {
            kill();
            return 1;
        }

        setHunger(getHunger() + 1);
        if (getHunger() > 20) {
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
                getX() - getPerc(),getY() - getPerc(),getX() + getPerc(), getY() + getPerc());

        int goalX = -1, goalY = -1, p = 0, maxDis = INT_MAX;
        for (Entity * e : v) {
            if (e->isFood() && p != 2) {
                Food * f = (Food *) e;
                k = maxSteps;
                if (contains(f->getSmells(), "erva")) {
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
                if (a->getWeight() > 15) {
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

        if (getLifetime() % 15 == 0) {
            reproduce(12);
        }

        return 0;
    }

    bool Ovelha::isOvelha() const {
        return true;
    }

    void Ovelha::kill() {
        if (isDead()) throw EntityAlreadyDead();
        setDead();
        try {
            Handler::instance->getSimulation()->summon(new Corpo(getX(), getY(), getWeight(), 0));
        } catch (OutOfBounds &e) {
            e.what();
        }
    }

}