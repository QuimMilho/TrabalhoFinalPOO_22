
#include "CmdFood.hpp"
#include "../../../../simulation/Simulation.hpp"
#include "../../../../handler/Handler.hpp"
#include "../../../../exceptions/NotANumber.hpp"
#include "../../../../exceptions/InvalidArguments.hpp"
#include "../../../../entities/food/list/Relva.hpp"
#include "../../../../entities/food/list/Cenoura.hpp"
#include "../../../../entities/food/list/Bife.hpp"
#include "../../../../entities/food/list/AlimMisterio.hpp"
#include "../../../../exceptions/OutOfBounds.hpp"
#include "CmdFeed.hpp"
#include "../../../../entities/animal/Animal.hpp"
#include "CmdFeedId.hpp"
#include "../../../../exceptions/EntityAlreadyDead.hpp"
#include "CmdNoFood.hpp"
#include "../../../../exceptions/WrongType.hpp"

namespace tppoo {

    int CmdFood::execute(std::string cmd, std::string *args, int nargs) {
        Handler *handler = Handler::instance;
        int x, y, k = 0;
        switch (nargs) {
            case 1:
                x = handler->random(Simulation::getNC());
                y = handler->random(Simulation::getNL());
                break;
            case 2:
                k = toNumber(args[1]);
                break;
            case 3:
                if (!isNumber(args[1]) || !isNumber(args[2])) throw NotANumber();
                x = toNumber(args[1]) % Simulation::getNC();
                y = toNumber(args[2]) % Simulation::getNL();
                break;
            default:
                throw InvalidArguments();
        }
        if (k == 0) {
            if (args[0] == "r") {
                handler->getSimulation()->summon(new Relva(x, y));
            } else if (args[0] == "t") {
                handler->getSimulation()->summon(new Cenoura(x, y));
            } else if (args[0] == "b") {
                handler->getSimulation()->summon(new Bife(x, y));
            } else if (args[0] == "a") {
                handler->getSimulation()->summon(new AlimMisterio(x, y));
            } else throw InvalidArguments();
        } else {
            for (int i = 0; i < k; i++) {
                x = handler->random(Simulation::getNC());
                y = handler->random(Simulation::getNL());
                try {
                    if (args[0] == "r") {
                        handler->getSimulation()->summon(new Relva(x, y));
                    } else if (args[0] == "t") {
                        handler->getSimulation()->summon(new Cenoura(x, y));
                    } else if (args[0] == "b") {
                        handler->getSimulation()->summon(new Bife(x, y));
                    } else if (args[0] == "a") {
                        handler->getSimulation()->summon(new AlimMisterio(x, y));
                    } else throw InvalidArguments();
                } catch (OutOfBounds& e) {
                    e.what();
                }
            }
        }
        return 2;
    }

    int CmdFeed::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 3 && nargs != 4) throw InvalidArguments();
        int x = toNumber(args[0]);
        int y = toNumber(args[1]);
        int nut = toNumber(args[2]);
        int tox = 0;
        if (nargs == 4) tox = toNumber(args[3]);
        std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
        for (Entity * e : v) {
            if (e->isAnimal() && !e->isDead()) {
                Animal * a = (Animal *) e;
                a->setHunger(a->getHunger() - nut);
                a->setLife(a->getLife() + nut - tox);
            }
        }
        return 0;
    }

    int CmdFeedId::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 2 && nargs != 3) throw InvalidArguments();
        int id = toNumber(args[0]);
        int nut = toNumber(args[1]);
        int tox = 0;
        if (nargs == 3) tox = toNumber(args[2]);
        Entity * e = Handler::instance->getSimulation()->getEntity(id);
        if (e->isDead()) throw EntityAlreadyDead();
        if (e->isAnimal()) {
            Animal * a = (Animal *) e;
            a->setHunger(a->getHunger() - nut);
            a->setLife(a->getLife() + nut - tox);
        }
        return 0;
    }

    int CmdNoFood::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs == 1) {
            int id = toNumber(args[0]);
            Entity * e = Handler::instance->getSimulation()->getEntity(id);
            if (!e->isFood()) throw WrongType();
            e->kill();
        } else if (nargs == 2) {
            int x = toNumber(args[0]);
            int y = toNumber(args[1]);
            std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
            for (Entity * e : v) {
                if (e->isFood()) {
                    e->kill();
                    return 2;
                }
            }
        } else throw InvalidArguments();
        return 0;
    }

}