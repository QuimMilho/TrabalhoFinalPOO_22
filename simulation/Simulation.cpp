#include <iostream>
#include "Simulation.hpp"
#include <fstream>
#include <sstream>
#include "../utils/utils.hpp"
#include "../exceptions/CommandNotFound.hpp"
#include "../exceptions/NotANumber.hpp"
#include "../exceptions/InvalidArguments.hpp"
#include "../exceptions/FileNotFound.hpp"
#include "../exceptions/EntityNotFound.hpp"
#include "../exceptions/EntityAlreadyDead.hpp"
#include "../exceptions/OutOfBounds.hpp"
#include "../exceptions/WrongType.hpp"
#include "../exceptions/VarNotFound.hpp"
#include "../exceptions/SimulationNotFound.hpp"
#include "../handler/Handler.hpp"

namespace tppoo {

    int Simulation::nc = 0;
    int Simulation::nl = 0;
    std::unordered_map<std::string, int> *Simulation::vars = new std::unordered_map<std::string, int>();

    Simulation::Simulation() {
        entities = new std::vector<Entity *>;
        x = 0;
        y = 0;
    }

    Simulation::~Simulation() {
        for (Entity *e : *entities) {
            delete e;
        }
        delete entities;
    }

    void Simulation::deleteVars() {
        delete vars;
    }

    void Simulation::loadConfigFile() {
        std::ifstream file("constantes.txt");
        if (file.bad() || file.fail()) {
            return;
        }
        std::string line, var, value;
        while (std::getline(file, line)) {
            try {
                var = "";
                value = "";
                std::stringstream ss(line);
                ss >> var >> value;
                if (vars->find(var) == vars->end())
                    vars->insert(std::pair<std::string, int>(var, toNumber(value)));
                else
                    vars->at(var) = toNumber(value);
            } catch (NotANumber& e) {
                e.what();
            } catch (std::exception& e) {
                e.what();
            }
        }
        file.close();
    }

    int Simulation::getNL() {
        return nl;
    }

    int Simulation::getNC() {
        return nc;
    }

    void Simulation::setNL(int value) {
        nl = value;
    }

    void Simulation::setNC(int value) {
        nc = value;
    }

    void Simulation::tick() {
        for (int i = 0; i < entities->size(); i++) {
            Entity * e = entities->at(i);
            if (!e->isDead()) e->tick();
        }
    }

    void Simulation::render() {
        if (moved) {
            moved = false;
            Handler::instance->updateCoords();
        }
        Handler::instance->simulationWindow.clear();

        int squareX = MAX_X_SIZE, squareY = MAX_Y_SIZE;
        if (Simulation::nc < MAX_X_SIZE)
            squareX = Simulation::nc;

        std::vector<Entity *> ents = getEntitiesInside(x, y, x + squareX - 1, y + squareY - 1);
        for (int i = 0; i < squareY; i++) {
            for (int h = 0; h < squareX; h++) {
                bool printed = false;
                for (Entity * e : ents) {
                    if (e->getX() == h + x && e->getY() == i + y && !printed) {
                        Handler::instance->simulationWindow << e->getChar();
                        printed = true;
                    }
                }
                if (!printed) Handler::instance->simulationWindow << ' ';
            }
        }
        showStats();
    }

    void Simulation::showStats() {
        Handler::instance->historyWindow.clear();
        int a = 0, f = 0, d = 0, df = 0, da = 0;
        for (Entity * e : *entities) {
            if (e->isDead()) {
                d++;
                if (e->isFood()) df++;
                else da++;
            }
            if (e->isAnimal()) a++;
            if (e->isFood()) f++;
        }
        Handler::instance->historyWindow << "Total de entidades: " << (int) entities->size() << "\n";
        Handler::instance->historyWindow << "Entidades mortas: " << d << "\n";
        Handler::instance->historyWindow << "Animais: " << a << "\n";
        Handler::instance->historyWindow << "Comidas: " << f << "\n";
        Handler::instance->historyWindow << "Entidades vivas: " << (int) entities->size() - d << "\n";
        Handler::instance->historyWindow << "Animais vivos: " << a - da << "\n";
        Handler::instance->historyWindow << "Comidas disponiveis: " << f - df << "\n";
    }

    void Simulation::tickMultiple(int n) {
        for (int i = 0; i < n; i++) {
            tick();
        }
    }

    void Simulation::tickMultiple(int n, int t) {
        for (int i = 0; i < n; i++) {
            tick();
            render();
            delay(t * 1000);
        }
    }

    int Simulation::getXOffset() const {
        return x;
    }

    int Simulation::getYOffset() const {
        return y;
    }

    void Simulation::addOffset(const int x, const int y) {
        if ((nc <= MAX_X_SIZE || x == 0) && (nl <= MAX_Y_SIZE || y == 0)) throw OutOfBounds();
        if (nc > MAX_X_SIZE) {
            int temp = this->x + x;
            if (temp > nc - MAX_X_SIZE) {
                temp = nc - MAX_X_SIZE;
            } else if (temp < 0) {
                temp = 0;
            }
            this->x = temp;
        }
        if (nl > MAX_Y_SIZE) {
            int temp = this->y + y;
            if (temp > nl - MAX_Y_SIZE) {
                temp = nl - MAX_Y_SIZE;
            } else if (temp < 0) {
                temp = 0;
            }
            this->y = temp;
        }
        moved = true;
    }

    void Simulation::addXOffset(const int x) {
        if (nc > MAX_X_SIZE) {
            int temp = this->x + x;
            if (temp > nc - MAX_X_SIZE) {
                temp = nc - MAX_X_SIZE;
            } else if (temp < 0) {
                temp = 0;
            }
            this->x = temp;
        } else throw OutOfBounds();
        moved = true;
    }

    void Simulation::addYOffset(const int y) {
        if (nl > MAX_Y_SIZE) {
            int temp = this->y + y;
            if (temp > nl - MAX_Y_SIZE) {
                temp = nl - MAX_Y_SIZE;
            } else if (temp < 0) {
                temp = 0;
            }
            this->y = temp;
        } else throw OutOfBounds();
        moved = true;
    }

    void Simulation::summon(tppoo::Entity *ent) {
        if (ent->isFood()) {
            int a = ent->getX(), b = ent->getY();
            if (alreadyHasFood(a, b)) {
                if (!alreadyHasFood(a + 1, b)) {
                    ent->setX(a + 1);
                } else if (!alreadyHasFood(a, b + 1)) {
                    ent->setY(b + 1);
                } else if (!alreadyHasFood(a - 1, b)) {
                    ent->setX(a - 1);
                } else if (!alreadyHasFood(a, b - 1)) {
                    ent->setY(b - 1);
                } else {
                    delete ent;
                    throw OutOfBounds();
                }
            }
        }
        entities->push_back(ent);
    }

    void Simulation::kill(int i) {
        if (i < 0 || i >= entities->size()) throw OutOfBounds();
        entities->at(i)->kill();
    }

    int Simulation::getNEntities() const {
        return (int) entities->size();
    }

    Entity *Simulation::getEntity(int n) const {
        if (n < 0 || n >= entities->size()) throw EntityNotFound();
        return entities->at(n);
    }

    int Simulation::getVar(std::string varName) const {
        if (vars->find(varName) == vars->end()) throw VarNotFound();
        return vars->at(varName);
    }

    bool Simulation::alreadyHasFood(int x, int y) {
        for (Entity * e : *entities) {
            if (e->isFood() && e->getY() == y % Simulation::getNL() && e->getX() == x % Simulation::getNC() && !e->isDead())
                return true;
        }
        return false;
    }

    std::vector<Entity *> Simulation::getEntitiesInside(int x1, int y1, int x2, int y2) const {
        std::vector<Entity *> vector;
        if (x1 < 0) x1 = Simulation::getNC() - abs(x1) % Simulation::getNC();
        else x1 = x1 % Simulation::getNC();
        if (y1 < 0) y1 = Simulation::getNL() - abs(y1) % Simulation::getNL();
        else y1 = y1 % Simulation::getNL();
        if (x2 < 0) x2 = Simulation::getNC() - abs(x2) % Simulation::getNC();
        else x2 = x2 % Simulation::getNC();
        if (y2 < 0) y2 = Simulation::getNL() - abs(y2) % Simulation::getNL();
        else y2 = y2 % Simulation::getNL();
        for (Entity * e: *entities) {
            if (isBetweenOrEquals(e->getX(), e->getY(), x1, y1, x2, y2) && !e->isDead())
                vector.push_back(e);
        }
        return vector;
    }

}