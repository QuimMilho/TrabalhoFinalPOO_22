#include <iostream>
#include "Handler.hpp"
#include "../exceptions/AlreadyRunning.hpp"
#include "../exceptions/SimulationNotFound.hpp"
#include "../entities/animal/list/AnimMisterio.hpp"
#include "../entities/animal/list/Canguru.hpp"
#include "../entities/animal/list/Lobo.hpp"
#include "../entities/animal/list/Ovelha.hpp"
#include "../entities/animal/list/Coelho.hpp"
#include "../entities/food/Food.hpp"
#include "../entities/food/list/Bife.hpp"
#include "../entities/food/list/Corpo.hpp"
#include "../entities/food/list/Cenoura.hpp"
#include "../entities/food/list/Relva.hpp"
#include "../entities/food/list/AlimMisterio.hpp"
#include "../exceptions/CommandNotFound.hpp"
#include "../exceptions/NotANumber.hpp"
#include "../exceptions/InvalidArguments.hpp"
#include "../exceptions/FileNotFound.hpp"
#include "../exceptions/EntityNotFound.hpp"
#include "../exceptions/EntityAlreadyDead.hpp"
#include "../exceptions/OutOfBounds.hpp"
#include "../exceptions/WrongType.hpp"

namespace tppoo {

    bool Handler::running = false;
    Handler *Handler::instance = nullptr;

    Handler::Handler() {
        cmd = new CommandHandler();
        sim = new Simulation();
        rand = new Random();
        simulations = new std::unordered_map<std::string, Simulation *>();
    }

    Handler::~Handler() {
        delete cmd;
        delete rand;
        for (std::pair<std::string, Simulation *> s : *simulations) {
            delete s.second;
        }
        delete simulations;
        sim->deleteVars();
        delete sim;
    }

    CommandHandler *Handler::getCommandHandler() {
        return cmd;
    }

    Simulation *Handler::getSimulation() {
        return sim;
    }

    void Handler::start() {
        if (Handler::running) throw AlreadyRunning();
        Handler::running = true;
        int exit;
        sim->loadConfigFile();
        sim->render();
        do {
            std::string cmdText;
            std::cout << ">";
            std::getline(std::cin, cmdText);
            try {
                exit = cmd->executeCommand(cmdText);
            } catch (CommandNotFound& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (NotANumber& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (InvalidArguments& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (FileNotFound& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (EntityNotFound& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (EntityAlreadyDead& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (OutOfBounds& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (WrongType& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (SimulationNotFound& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            } catch (std::exception& e) {
                std::cout << "Ocorreu um erro ao executares esse comando: " << e.what() << std::endl;
            }
            if (exit == 2) {
                sim->render();
                exit = 0;
            }
            if (exit == 3) {
                sim->render();
                exit = 1;
            }
        } while (exit != 1);
    }

    int Handler::random(int n) {
        return rand->random(n);
    }

    int Handler::random(int a, int b) {
        return rand->random(a, b);
    }

    bool Handler::simulationExists(const std::string& name) {
        if (simulations->find(name) == simulations->end()) return false;
        return true;
    }

    void Handler::setActive(const std::string& name) {
        if (!simulationExists(name)) throw SimulationNotFound();
        delete sim;
        sim = new Simulation();
        copySim(simulations->at(name));
    }

    void Handler::saveSim(const std::string& name) {
        if (simulationExists(name)) delete simulations->at(name);
        Simulation *newSim = new Simulation();
        copySim(sim, newSim);
        simulations->insert(std::pair<std::string, Simulation *>(name, newSim));
    }

    void Handler::newSim() {
        delete sim;
        sim = new Simulation();
    }

    void Handler::newSim(std::string name) {
        saveSim(name);
        delete sim;
        sim = new Simulation();
    }

    void Handler::deleteSim(std::string name) {
        if (!simulationExists(name)) throw SimulationNotFound();
        Simulation * p = simulations->at(name);
        delete p;
        simulations->erase(name);
    }

    void Handler::copySim(Simulation *saved) {
        copySim(saved, sim);
    }

    void Handler::copySim(Simulation *saved, Simulation *newSim) {
        if (saved->getXOffset() != 0 || saved->getYOffset() != 0)
            newSim->addOffset(saved->getXOffset(), saved->getYOffset());
        for (int i = 0; i < saved->getNEntities(); i++) {
            Entity * e = saved->getEntity(i);
            if (e->isAnimal()) {
                Animal *a = (Animal *) e;
                if (e->isAnimMisterio()) {
                    newSim->summon(new AnimMisterio(e->getX(), e->getY()));
                } else if (e->isCanguru()) {
                    newSim->summon(new Canguru(e->getX(), e->getY(), nullptr));
                } else if (e->isLobo()) {
                    newSim->summon(new Lobo(e->getX(), e->getY()));
                } else if (e->isOvelha()) {
                    newSim->summon(new Ovelha(e->getX(), e->getY(), a->getWeight()));
                } else {
                    newSim->summon(new Coelho(e->getX(), e->getY(), a->getWeight()));
                }
                Animal * anim = (Animal *) newSim->getEntity(i);
                anim->setHunger(a->getHunger());
                anim->setWeight(a->getWeight());
                anim->setLife(a->getLife());
            } else {
                Food * f = (Food *) e;
                if (e->isBife()) {
                    newSim->summon(new Bife(e->getX(), e->getY()));
                } else if (e->isCorpo()) {
                    Corpo * c = (Corpo *) e;
                    newSim->summon(new Corpo(e->getX(), e->getY(), c->getInitValorNut(),
                                          c->getInitValorTox()));
                } else if (e->isCenoura()) {
                    newSim->summon(new Cenoura(e->getX(), e->getY()));
                } else if (e->isRelva()) {
                    newSim->summon(new Relva(e->getX(), e->getY()));
                } else {
                    newSim->summon(new AlimMisterio(e->getX(), e->getY()));
                }
                Food * food = (Food *) newSim->getEntity(i);
                food->setNut(f->getNut());
                food->setTox(f->getTox());
            }
            if (e->isDead()) e->kill();
            for (int h = 0; h < e->getLifetime(); h++) e->addLifetime();
        }
    }

}