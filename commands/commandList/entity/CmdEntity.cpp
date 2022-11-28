
#include <iostream>
#include "CmdSee.hpp"
#include "../../../exceptions/InvalidArguments.hpp"
#include "../../../Handler/Handler.hpp"
#include "../../../entities/animal/Animal.hpp"
#include "../../../entities/food/Food.hpp"
#include "CmdInfo.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"
#include "CmdEmpty.hpp"

namespace tppoo {

    int CmdSee::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 2) throw InvalidArguments();
        int x = toNumber(args[0]) % Simulation::getNC();
        int y = toNumber(args[1]) % Simulation::getNL();
        for (int i = 0; i < Handler::instance->getSimulation()->getNEntities(); i++) {
            Entity * e = Handler::instance->getSimulation()->getEntity(i);
            if (e->getX() == x && e->getY() == y && !e->isDead()) {
                if (e->isAnimal()) {
                    Animal *a = (Animal *) e;
                    Handler::instance->commandWindow << "Id: " << i << ", Especie: ";
                    if (e->isCoelho()) {
                        Handler::instance->commandWindow << "Coelho";
                    } else if (e->isCanguru()) {
                        Handler::instance->commandWindow << "Canguru";
                    } else if (e->isLobo()) {
                        Handler::instance->commandWindow << "Lobo";
                    } else if (e->isOvelha()) {
                        Handler::instance->commandWindow << "Ovelha";
                    } else {
                        Handler::instance->commandWindow << "Animal Mistério";
                    }
                    Handler::instance->commandWindow << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                            ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime() << "\n";
                } else {
                    Food *f = (Food *) e;
                    Handler::instance->commandWindow << "Id: " << i << ", Tipo: ";
                    if (e->isCenoura()) {
                        Handler::instance->commandWindow << "Cenoura";
                    } else if (e->isRelva()) {
                        Handler::instance->commandWindow << "Relva";
                    } else if (e->isCorpo()) {
                        Handler::instance->commandWindow << "Corpo";
                    } else if (e->isBife()) {
                        Handler::instance->commandWindow << "Bife";
                    } else {
                        Handler::instance->commandWindow << "Alimento Mistério";
                    }
                    Handler::instance->commandWindow << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                            ", Lifetime: " << e->getLifetime() << "\n";
                }
            }
        }
        return 0;
    }

    int CmdInfo::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 1) throw InvalidArguments();
        int n = toNumber(args[0]);
        Entity * e = Handler::instance->getSimulation()->getEntity(n);
        if (e->isDead()) throw EntityAlreadyDead();
        if (e->isAnimal()) {
            Animal *a = (Animal *) e;
            Handler::instance->commandWindow << "Id: " << n << ", Especie: ";
            if (e->isCoelho()) {
                Handler::instance->commandWindow << "Coelho";
            } else if (e->isCanguru()) {
                Handler::instance->commandWindow << "Canguru";
            } else if (e->isLobo()) {
                Handler::instance->commandWindow << "Lobo";
            } else if (e->isOvelha()) {
                Handler::instance->commandWindow << "Ovelha";
            } else {
                Handler::instance->commandWindow << "Animal Mistério";
            }
            Handler::instance->commandWindow << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                      ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime()
                      << ", X: " << e->getX() << ", Y: " << e->getY() << "\n";
        } else {
            Food *f = (Food *) e;
            Handler::instance->commandWindow << "Id: " << n << ", Tipo: ";
            if (e->isCenoura()) {
                Handler::instance->commandWindow << "Cenoura";
            } else if (e->isRelva()) {
                Handler::instance->commandWindow << "Relva";
            } else if (e->isCorpo()) {
                Handler::instance->commandWindow << "Corpo";
            } else if (e->isBife()) {
                Handler::instance->commandWindow << "Bife";
            } else {
                Handler::instance->commandWindow << "Alimento Mistério";
            }
            Handler::instance->commandWindow << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                      ", Lifetime: " << e->getLifetime()<< ", X: " << e->getX() << ", Y: " <<
                      e->getY() << "\n";
        }
        return 0;
    }

    int CmdEmpty::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 2) throw InvalidArguments();
        int x = toNumber(args[0]);
        int y = toNumber(args[1]);
        std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(x, y, x, y);
        for (Entity * e : v) {
            if (!e->isDead()) e->kill();
        }
        return 2;
    }

}
