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

    CommandHandler *Handler::getCommandHandler() const {
        return cmd;
    }

    Simulation *Handler::getSimulation() const {
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
            commandWindow << ">";
            commandWindow >> cmdText;
            commandWindow.clear();
            try {
                exit = cmd->executeCommand(cmdText);
            } catch (CommandNotFound& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (NotANumber& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (InvalidArguments& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (FileNotFound& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (EntityNotFound& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (EntityAlreadyDead& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (OutOfBounds& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (WrongType& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (SimulationNotFound& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
            } catch (std::exception& e) {
                commandWindow << "Ocorreu um erro ao executares esse comando: " << e.what() << "\n";
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
            Entity * newEnt;
            if (e->isAnimal()) {
                Animal *a = (Animal *) e;
                if (e->isAnimMisterio()) {
                    newEnt = new AnimMisterio(e->getX(), e->getY());
                } else if (e->isCanguru()) {
                    newEnt = new Canguru(e->getX(), e->getY(), nullptr);
                } else if (e->isLobo()) {
                    newEnt = new Lobo(e->getX(), e->getY());
                } else if (e->isOvelha()) {
                    newEnt = new Ovelha(e->getX(), e->getY(), a->getWeight());
                } else {
                    newEnt = new Coelho(e->getX(), e->getY(), a->getWeight());
                }
                newSim->summon(newEnt);
                Animal * anim = (Animal *) newEnt;
                anim->setHunger(a->getHunger());
                anim->setWeight(a->getWeight());
                anim->setLife(a->getLife());
            } else {
                Food * f = (Food *) e;
                if (e->isBife()) {
                    newSim->summon(new Bife(e->getX(), e->getY()));
                } else if (e->isCorpo()) {
                    Corpo * c = (Corpo *) e;
                    newEnt = new Corpo(e->getX(), e->getY(), c->getInitValorNut(),
                                      c->getInitValorTox());
                } else if (e->isCenoura()) {
                    newEnt = new Cenoura(e->getX(), e->getY());
                } else if (e->isRelva()) {
                    newEnt = new Relva(e->getX(), e->getY());
                } else {
                    newEnt = new AlimMisterio(e->getX(), e->getY());
                }
                newSim->summon(newEnt);
                Food * food = (Food *) newEnt;
                food->setNut(f->getNut());
                food->setTox(f->getTox());
            }
            if (e->isDead()) newEnt->kill();
            for (int h = 0; h < e->getLifetime(); h++) newEnt->addLifetime();
        }
    }

    void Handler::updateCoords() {
        //Update coords
        topCoordsWindow.clear();
        topCoordsWindow << sim->getXOffset() << " " << sim->getYOffset();

        botCoordsWindow.clear();
        botCoordsWindow << sim->getXOffset() + (Simulation::getNC() < MAX_X_SIZE ? Simulation::getNC() - 1 : MAX_X_SIZE - 1)
        << " " << sim->getYOffset() + MAX_Y_SIZE - 1;

        //Update borders
            //Topo
        if (sim->getYOffset() <= 0) {
            updateBorder(TOP, (char) 219);
        } else {
            updateBorder(TOP, (char) 177);
        }
            //Direita
        if (sim->getXOffset() <= 0) {
            updateBorder(LEFT, (char) 219);
        } else {
            updateBorder(LEFT, (char) 177);
        }
            //Baixo
        if (sim->getYOffset() + MAX_Y_SIZE >= Simulation::getNL()) {
            updateBorder(BOTTOM, (char) 219);
        } else {
            updateBorder(BOTTOM, (char) 177);
        }
            //Esquerda
        if (sim->getXOffset() + MAX_X_SIZE >= Simulation::getNC()) {
            updateBorder(RIGHT, (char) 219);
        } else {
            updateBorder(RIGHT, (char) 177);
        }
    }

    void Handler::updateBorder(int b, char c) {
        if (b == TOP || b == BOTTOM) {
            if (b == TOP) {
                topBorderWindow.clear();
            } else {
                botBorderWindow.clear();
            }
            for (int i = 0; i < (Simulation::getNC() < MAX_X_SIZE ? Simulation::getNC() + 4 : 57); i++) {
                if (b == TOP) {
                    topBorderWindow << c;
                } else {
                    botBorderWindow << c;
                }
            }
        } else if (b == RIGHT || b == LEFT) {
            if (b == RIGHT) {
                rightBorderWindow.clear();
            } else {
                leftBorderWindow.clear();
            }
            for (int i = 0; i < 15; i++) {
                if (b == RIGHT) {
                    rightBorderWindow << c << c;
                } else {
                    leftBorderWindow << c << c;
                }
            }
        }
    }

}