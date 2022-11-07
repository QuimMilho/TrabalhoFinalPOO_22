
#include <iostream>
#include "CmdSee.hpp"
#include "../../../exceptions/InvalidArguments.hpp"
#include "../../../Handler/Handler.hpp"
#include "../../../entities/animal/Animal.hpp"
#include "../../../entities/food/Food.hpp"
#include "CmdInfo.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"

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
                    std::cout << "Id: " << i << ", Especie: ";
                    if (e->isCoelho()) {
                        std::cout << "Coelho";
                    } else if (e->isCanguru()) {
                        std::cout << "Canguru";
                    } else if (e->isLobo()) {
                        std::cout << "Lobo";
                    } else if (e->isOvelha()) {
                        std::cout << "Ovelha";
                    } else {
                        std::cout << "Animal Mistério";
                    }
                    std::cout << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                            ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime() << std::endl;
                } else {
                    Food *f = (Food *) e;
                    std::cout << "Id: " << i << ", Tipo: ";
                    if (e->isCenoura()) {
                        std::cout << "Cenoura";
                    } else if (e->isRelva()) {
                        std::cout << "Relva";
                    } else if (e->isCorpo()) {
                        std::cout << "Corpo";
                    } else if (e->isBife()) {
                        std::cout << "Bife";
                    } else {
                        std::cout << "Alimento Mistério";
                    }
                    std::cout << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                            ", Lifetime: " << e->getLifetime() << std::endl;
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
            std::cout << "Id: " << n << ", Especie: ";
            if (e->isCoelho()) {
                std::cout << "Coelho";
            } else if (e->isCanguru()) {
                std::cout << "Canguru";
            } else if (e->isLobo()) {
                std::cout << "Lobo";
            } else if (e->isOvelha()) {
                std::cout << "Ovelha";
            } else {
                std::cout << "Animal Mistério";
            }
            std::cout << ", Vida: " << a->getLife() << ", Peso: " << a->getWeight() <<
                      ", Fome: " << a->getHunger() << ", Lifetime: " << e->getLifetime()
                      << ", X: " << e->getX() << ", Y: " << e->getY() << std::endl;
        } else {
            Food *f = (Food *) e;
            std::cout << "Id: " << n << ", Tipo: ";
            if (e->isCenoura()) {
                std::cout << "Cenoura";
            } else if (e->isRelva()) {
                std::cout << "Relva";
            } else if (e->isCorpo()) {
                std::cout << "Corpo";
            } else if (e->isBife()) {
                std::cout << "Bife";
            } else {
                std::cout << "Alimento Mistério";
            }
            std::cout << ", Nutrientes: " << f->getNut() << ", Toxicidade: " << f->getTox() <<
                      ", Lifetime: " << e->getLifetime()<< ", X: " << e->getX() << ", Y: " <<
                      e->getY() << std::endl;
        }
        return 0;
    }

}
