
#include <iostream>
#include <sstream>
#include "CmdSee.hpp"
#include "../../../exceptions/InvalidArguments.hpp"
#include "../../../Handler/Handler.hpp"
#include "../../../entities/animal/Animal.hpp"
#include "../../../entities/food/Food.hpp"
#include "CmdInfo.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"
#include "CmdEmpty.hpp"

namespace tppoo {

    int CmdSee::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs != 2) throw InvalidArguments();
        std::stringstream ss;
        int x = toNumber(args[0]) % Simulation::getNC();
        int y = toNumber(args[1]) % Simulation::getNL();
        for (int i = 0; i < Handler::instance->getSimulation()->getNEntities(); i++) {
            Entity * e = Handler::instance->getSimulation()->getEntity(i);
            if (e->getX() == x && e->getY() == y && !e->isDead()) {
                if (e->isAnimal()) {
                    Animal *a = (Animal *) e;
                    ss << "Id: " << i << ", Especie: ";
                    if (e->isCoelho()) {
                        ss << "Coelho";
                    } else if (e->isCanguru()) {
                        ss << "Canguru";
                    } else if (e->isLobo()) {
                        ss << "Lobo";
                    } else if (e->isOvelha()) {
                        ss << "Ovelha";
                    } else {
                        ss << "Animal Mistério";
                    }
                    ss << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                            ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime();
                } else {
                    Food *f = (Food *) e;
                    ss << "Id: " << i << ", Tipo: ";
                    if (e->isCenoura()) {
                        ss << "Cenoura";
                    } else if (e->isRelva()) {
                        ss << "Relva";
                    } else if (e->isCorpo()) {
                        ss << "Corpo";
                    } else if (e->isBife()) {
                        ss << "Bife";
                    } else {
                        ss << "Alimento Mistério";
                    }
                    ss << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                            ", Lifetime: " << e->getLifetime();
                }
                v.push_back(ss.str());
                ss.str(std::string());
            }
        }
        return 0;
    }

    int CmdInfo::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs != 1) throw InvalidArguments();
        std::stringstream ss;
        int n = toNumber(args[0]);
        Entity * e = Handler::instance->getSimulation()->getEntity(n);
        if (e->isDead()) throw EntityAlreadyDead();
        if (e->isAnimal()) {
            Animal *a = (Animal *) e;
            ss << "Id: " << n << ", Especie: ";
            if (e->isCoelho()) {
                ss << "Coelho";
            } else if (e->isCanguru()) {
                ss << "Canguru";
            } else if (e->isLobo()) {
                ss << "Lobo";
            } else if (e->isOvelha()) {
                ss << "Ovelha";
            } else {
                ss << "Animal Mistério";
            }
            ss << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                      ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime()
                      << ", X: " << e->getX() << ", Y: " << e->getY();
        } else {
            Food *f = (Food *) e;
            ss << "Id: " << n << ", Tipo: ";
            if (e->isCenoura()) {
                ss << "Cenoura";
            } else if (e->isRelva()) {
                ss << "Relva";
            } else if (e->isCorpo()) {
                ss << "Corpo";
            } else if (e->isBife()) {
                ss << "Bife";
            } else {
                ss << "Alimento Mistério";
            }
            ss << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                      ", Lifetime: " << e->getLifetime()<< ", X: " << e->getX() << ", Y: " <<
                      e->getY();
        }
        v.push_back(ss.str());
        ss.str(std::string());
        return 0;
    }

    int CmdEmpty::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs != 2) throw InvalidArguments();
        int x = toNumber(args[0]);
        int y = toNumber(args[1]);
        std::vector<Entity *> ve = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
        for (Entity * e : ve) {
            if (!e->isDead()) e->kill();
        }
        return 2;
    }

}
