
#include <iostream>
#include "CmdAnimal.hpp"
#include "../../../../exceptions/InvalidArguments.hpp"
#include "../../../../utils/utils.hpp"
#include "../../../../exceptions/NotANumber.hpp"
#include "../../../../handler/Handler.hpp"
#include "../../../../entities/animal/list/Coelho.hpp"
#include "../../../../entities/animal/list/Ovelha.hpp"
#include "../../../../entities/animal/list/Lobo.hpp"
#include "../../../../entities/animal/list/Canguru.hpp"
#include "../../../../entities/animal/list/AnimMisterio.hpp"
#include "CmdKill.hpp"
#include "../../../../exceptions/WrongType.hpp"
#include "CmdKillId.hpp"
#include "../../../../exceptions/EntityAlreadyDead.hpp"
#include "CmdAnim.hpp"
#include "../../../../exceptions/OutOfBounds.hpp"
#include "CmdVisanim.hpp"

namespace tppoo {

    int CmdAnimal::execute(std::string cmd, std::string *args, int nargs) {
        Handler *handler = Handler::instance;
        int x, y, k = 1;
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
        if (k == 1) {
            if (args[0] == "c") {
                handler->getSimulation()->summon(new Coelho(x, y, handler->random(1, 4)));
            } else if (args[0] == "o") {
                handler->getSimulation()->summon(new Ovelha(x, y, handler->random(4, 8)));
            } else if (args[0] == "l") {
                handler->getSimulation()->summon(new Lobo(x, y));
            } else if (args[0] == "g") {
                handler->getSimulation()->summon(new Canguru(x, y, nullptr));
            } else if (args[0] == "m") {
                handler->getSimulation()->summon(new AnimMisterio(x, y));
            } else throw InvalidArguments();
        } else {
            for (int i = 0; i < k; i++) {
                x = handler->random(Simulation::getNC());
                y = handler->random(Simulation::getNL());
                if (args[0] == "c") {
                    handler->getSimulation()->summon(new Coelho(x, y, handler->random(1, 4)));
                } else if (args[0] == "o") {
                    handler->getSimulation()->summon(new Ovelha(x, y, handler->random(4, 8)));
                } else if (args[0] == "l") {
                    handler->getSimulation()->summon(new Lobo(x, y));
                } else if (args[0] == "g") {
                    handler->getSimulation()->summon(new Canguru(x, y, nullptr));
                } else if (args[0] == "m") {
                    handler->getSimulation()->summon(new AnimMisterio(x, y));
                } else throw InvalidArguments();
            }
        }
        return 2;
    }

    int CmdKill::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 2) throw InvalidArguments();
        Handler *handler = Handler::instance;
        int x = toNumber(args[0]);
        int y = toNumber(args[1]);
        for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
            Entity *e = handler->getSimulation()->getEntity(i);
            if (e->isAnimal() && !e->isDead()) {
                if (e->getX() % Simulation::getNC() == x && e->getY() % Simulation::getNL() == y)
                    e->kill();
            }
        }
        return 2;
    }

    int CmdKillId::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 1) throw InvalidArguments();
        int n = toNumber(args[0]);
        Entity *e = Handler::instance->getSimulation()->getEntity(n);
        if (!e->isAnimal()) throw WrongType();
        if (e->isDead()) throw EntityAlreadyDead();
        e->kill();
        return 2;
    }

    int CmdAnim::execute(std::string cmd, std::string *args, int nargs) {
        Handler *handler = Handler::instance;
        if (nargs == 0) {
            for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                Entity *e = handler->getSimulation()->getEntity(i);
                if (e->isAnimal() && !e->isDead()) {
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
                    Animal *a = (Animal *) e;
                    std::cout << ", Saude: " << a->getLife() << std::endl;
                }
            }
        } else if (nargs == 1) {
            if (args[0] == "c") {
                for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                    Entity *e = handler->getSimulation()->getEntity(i);
                    if (e->isCoelho() && !e->isDead()) {
                        std::cout << "Id: " << i << ", Especie: Coelho";
                        Animal *a = (Animal *) e;
                        std::cout << ", Saude: " << a->getLife() << std::endl;
                    }
                }
            } else if (args[0] == "o") {
                for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                    Entity *e = handler->getSimulation()->getEntity(i);
                    if (e->isOvelha() && !e->isDead()) {
                        std::cout << "Id: " << i << ", Especie: Ovelha";
                        Animal *a = (Animal *) e;
                        std::cout << ", Saude: " << a->getLife() << std::endl;
                    }
                }
            } else if (args[0] == "l") {
                for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                    Entity *e = handler->getSimulation()->getEntity(i);
                    if (e->isLobo() && !e->isDead()) {
                        std::cout << "Id: " << i << ", Especie: Lobo";
                        Animal *a = (Animal *) e;
                        std::cout << ", Saude: " << a->getLife() << std::endl;
                    }
                }
            } else if (args[0] == "g") {
                for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                    Entity *e = handler->getSimulation()->getEntity(i);
                    if (e->isCanguru() && !e->isDead()) {
                        std::cout << "Id: " << i << ", Especie: Canguru";
                        Animal *a = (Animal *) e;
                        std::cout << ", Saude: " << a->getLife() << std::endl;
                    }
                }
            } else if (args[0] == "m") {
                for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                    Entity *e = handler->getSimulation()->getEntity(i);
                    if (e->isAnimMisterio() && !e->isDead()) {
                        std::cout << "Id: " << i << ", Especie: Animal Misterio";
                        Animal *a = (Animal *) e;
                        std::cout << ", Saude: " << a->getLife() << std::endl;
                    }
                }
            } else throw InvalidArguments();
        } else if (nargs == 4) {
            int x1 = toNumber(args[0]);
            int y1 = toNumber(args[1]);
            int x2 = toNumber(args[2]);
            int y2 = toNumber(args[3]);
            if (x1 < 0 || x1 >= Simulation::getNC()) throw OutOfBounds();
            if (y1 < 0 || y1 >= Simulation::getNL()) throw OutOfBounds();
            if (x2 < 0 || x2 >= Simulation::getNC()) throw OutOfBounds();
            if (y2 < 0 || y2 >= Simulation::getNL()) throw OutOfBounds();
            for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
                Entity *e = handler->getSimulation()->getEntity(i);
                if (e->isAnimal() && !e->isDead() && isBetweenOrEquals(e->getX(), e->getY(), x1, y1, x2, y2)) {
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
                    Animal *a = (Animal *) e;
                    std::cout << ", Saude: " << a->getLife() << std::endl;
                }
            }
        } else throw InvalidArguments();
        return 0;
    }

    int CmdVisanim::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 0) throw InvalidArguments();
        Handler * handler = Handler::instance;
        int x = handler->getSimulation()->getXOffset(), y = handler->getSimulation()->getYOffset();
        for (int i = 0; i < handler->getSimulation()->getNEntities(); i++) {
            Entity *e = handler->getSimulation()->getEntity(i);
            if (e->isAnimal() && !e->isDead() && isBetweenOrEquals(e->getX(), e->getY(), x, y, x + 52, y + 18)) {
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
                Animal *a = (Animal *) e;
                std::cout << ", Saude: " << a->getLife() << std::endl;
            }
        }
        return 0;
    }

}
