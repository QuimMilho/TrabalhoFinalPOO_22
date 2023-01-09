#include "Canguru.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"
#include "../../food/list/Corpo.hpp"
#include "../../../exceptions/OutOfBounds.hpp"

namespace tppoo {

    Canguru::Canguru(int x, int y, Canguru * mother) : Animal('C', x, y, 10, 0, 7, 20),
            mother(mother) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SCanguru");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
        try {
            maxLifetime = Handler::instance->getSimulation()->getVar("VCanguru");
        } catch (VarNotFound &e) {
            e.what();
            maxLifetime = 70;
        }
    }

    Canguru::~Canguru() = default;

    int Canguru::tick() {
        addLifetime();
        if (getLifetime() > maxLifetime) {
            kill();
            return 1;
        }

        if (getLifetime() == 20) setWeight(20);

        if (getLifetime() <= 10 && mother != nullptr) {
            int howMany = 1;
            std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(
                    getX() - getPerc(), getY() - getPerc(),getX() + getPerc(), getY() + getPerc());
            for (Entity * e : v) {
                if (e->isAnimal() && e != mother) {
                    howMany = 2;
                    break;
                }
            }
            move(Handler::instance->random(mother->getX() - (4 - howMany), mother->getX() - (4 - howMany)),
                 Handler::instance->random(mother->getY() - (4 - howMany), mother->getY() - (4 - howMany)),
                 howMany);
        } else {
            if (getLifetime() <= 10) {
                move(Handler::instance->random(getX() - 10, getX()  + 10),
                     Handler::instance->random(getY() - 10, getY()  + 10),
                     Handler::instance->random(2, 4));
            } else {
                int goalX = getX(), goalY = getY();
                int k = Handler::instance->random(4);
                if (k < 2) {
                    if (k % 2 == 0) goalX--;
                    else goalX++;
                } else {
                    if (k % 2 == 0) goalY--;
                    else goalY++;
                }
                move(goalX, goalY, 1);
            }

        }

        if (getLifetime() % 30 == 0) {
            reproduce(3);
        }

        return 0;
    }

    bool Canguru::isCanguru() const {
        return true;
    }

    void Canguru::kill() {
        if (isDead()) throw EntityAlreadyDead();
        setDead();
        try {
            Handler::instance->getSimulation()->summon(new Corpo(getX(), getY(), 15, 5));
        } catch (OutOfBounds &e) {
            e.what();
        }
    }

}