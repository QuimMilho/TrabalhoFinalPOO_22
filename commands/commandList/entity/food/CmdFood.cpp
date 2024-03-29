
#include <iostream>
#include <sstream>
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
#include "CmdComida.hpp"

namespace tppoo {

    int CmdFood::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
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

    int CmdFeed::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs != 3 && nargs != 4) throw InvalidArguments();
        int x = toNumber(args[0]);
        int y = toNumber(args[1]);
        int nut = toNumber(args[2]);
        int tox = 0;
        if (nargs == 4) tox = toNumber(args[3]);
        std::vector<Entity *> ve = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
        for (Entity * e : ve) {
            if (e->isAnimal() && !e->isDead()) {
                Animal * a = (Animal *) e;
                a->setHunger(a->getHunger() - nut);
                a->setLife(a->getLife() + nut - tox);
            }
        }
        return 0;
    }

    int CmdFeedId::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
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

    int CmdNoFood::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs == 1) {
            int id = toNumber(args[0]);
            Entity * e = Handler::instance->getSimulation()->getEntity(id);
            if (!e->isFood()) throw WrongType();
            e->kill();
        } else if (nargs == 2) {
            int x = toNumber(args[0]);
            int y = toNumber(args[1]);
            std::vector<Entity *> ve = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
            for (Entity * e : ve) {
                if (e->isFood()) {
                    e->kill();
                    return 2;
                }
            }
        } else throw InvalidArguments();
        return 0;
    }

    int CmdComida::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        std::stringstream ss;
        if (nargs == 0) {
            for (int i = 0; i < Handler::instance->getSimulation()->getNEntities(); i++) {
                Entity * e = Handler::instance->getSimulation()->getEntity(i);
                if (e->isFood() && !e->isDead()) {
                    ss << "Id: " << i << ", tipo: ";
                    if (e->isRelva()) {
                        ss << "Relva";
                    } else if (e->isCenoura()) {
                        ss << "Cenoura";
                    } else if (e->isCorpo()) {
                        ss << "Corpo";
                    } else if (e->isBife()) {
                        ss << "Bife";
                    } else {
                        ss << "Alimento Misterio";
                    }
                    ss << ", X: " << e->getX() << ", Y: " << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
            }
        } else if (nargs == 1) {
            if (args[0] != "r" && args[0] != "t" && args[0] != "b" && args[0] != "a" && args[0] != "p")
                throw InvalidArguments();
            for (int i = 0; i < Handler::instance->getSimulation()->getNEntities(); i++) {
                Entity * e = Handler::instance->getSimulation()->getEntity(i);
                if (e->isDead()) continue;
                if (e->isRelva() && args[0] == "r") {
                    ss << "Id: " << i << ", tipo: " << "Relva" << ", X: " << e->getX() << ", Y: "
                            << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
                if (e->isCenoura() && args[0] == "t") {
                    ss << "Id: " << i << ", tipo: " << "Cenoura" << ", X: " << e->getX() << ", Y: "
                            << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
                if (e->isCorpo() && args[0] == "p") {
                    ss << "Id: " << i << ", tipo: " << "Corpo" << ", X: " << e->getX() << ", Y: "
                            << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
                if (e->isBife() && args[0] == "b") {
                    ss << "Id: " << i << ", tipo: " << "Bife" << ", X: " << e->getX() << ", Y: "
                            << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
                if (e->isAlimMisterio() && args[0] == "a") {
                    ss << "Id: " << i << ", tipo: " << "Alimento Misterio" << ", X: " << e->getX()
                            << ", Y: " << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
            }
        } else if (nargs == 4) {
            int x1 = toNumber(args[0]);
            int y1 = toNumber(args[1]);
            int x2 = toNumber(args[2]);
            int y2 = toNumber(args[3]);
            for (int i = 0; i < Handler::instance->getSimulation()->getNEntities(); i++) {
                Entity * e = Handler::instance->getSimulation()->getEntity(i);
                if (e->isFood() && isBetweenOrEquals(e->getX(), e->getY(), x1, y1, x2, y2) && !e->isDead()) {
                    ss << "Id: " << i << ", tipo: ";
                    if (e->isRelva()) {
                        ss << "Relva";
                    } else if (e->isCenoura()) {
                        ss << "Cenoura";
                    } else if (e->isCorpo()) {
                        ss << "Corpo";
                    } else if (e->isBife()) {
                        ss << "Bife";
                    } else {
                        ss << "Alimento Misterio";
                    }
                    ss << ", X: " << e->getX() << ", Y: " << e->getY();
                    v.push_back(ss.str());
                    ss.str(std::string());
                }
            }
        } else throw InvalidArguments();
        return 0;
    }

}