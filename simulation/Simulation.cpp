#include <iostream>
#include "Simulation.hpp"
#include <fstream>
#include <sstream>
#include "../utils/utils.hpp"
#include "../handler/Handler.hpp"
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
        for (Entity * e : *entities) {
            if (!e->isDead()) e->tick();
        }
    }

    void Simulation::render() { // 120x30
        clear();
        std::cout << std::endl << "  " << x << " " << y << std::endl << "  ";

        char borderTop, borderRight, borderLeft, borderBottom;
        if (y == 0) borderTop = (char) 219;
        else borderTop = (char) 176;
        if (y + 18 < Simulation::nl) borderBottom = (char) 176;
        else borderBottom = (char) 219;
        if (x == 0) borderLeft = (char) 219;
        else borderLeft = (char) 176;
        if (x + 52 < Simulation::nc) borderRight = (char) 176;
        else borderRight = (char) 219;

        int squareX = 52, squareY = 18;
        if (Simulation::nc < 52)
            squareX = Simulation::nc;
        if (Simulation::nl < 18)
            squareY = Simulation::nl;

        for (int i = 0; i < squareX + 4; i++) {
            std::cout << borderTop;
        }
        std::cout << std::endl << "  ";

        std::vector<Entity *> v = getEntitiesInside(x, y, x + 52, y + 18);
        for (int i = 0; i < squareY; i++) {
            std::cout << borderLeft << borderLeft;
            for (int h = 0; h < squareX; h++) {
                bool printed = false;
                for (Entity * e : v) {
                    if (e->getX() == h + x && e->getY() == i + y) {
                        std::cout << e->getChar();
                        printed = true;
                        continue;
                    }
                }
                if (!printed) std::cout << ' ';
            }
            std::cout << borderRight << borderRight << std::endl << "  ";
        }

        for (int i = 0; i < squareX + 4; i++) {
            std::cout << borderBottom;
        }
        std::cout << std::endl;
        for (int i = 0; i < squareX + 1; i++) {
            std::cout << ' ';
        }

        std::cout << x + squareX - 1 << " " << y + squareY - 1 << std::endl << std::endl;
    }

    void Simulation::tickMultiple(int n) {
        for (int i = 0; i < n; i++) {
            tick();
        }
        render();
    }

    void Simulation::tickMultiple(int n, int t) {
        for (int i = 0; i < n; i++) {
            tick();
            render();
            delay(t * 1000);
        }
    }

    int Simulation::getXOffset() {
        return x;
    }

    int Simulation::getYOffset() {
        return y;
    }

    void Simulation::addOffset(const int x, const int y) {
        if ((nc <= 52 || x == 0) && (nl <= 18 || y == 0)) throw OutOfBounds();
        if (nc > 52) {
            int temp = this->x + x;
            if (temp > nc - 52) {
                temp = nc - 52;
            } else if (temp < 0) {
                temp = 0;
            }
            this->x = temp;
        }
        if (nl > 18) {
            int temp = this->y + y;
            if (temp > nl - 18) {
                temp = nl - 18;
            } else if (temp < 0) {
                temp = 0;
            }
            this->y = temp;
        }
        std::cout << this->x << " " << this->y << std::endl;
    }

    void Simulation::addXOffset(const int x) {
        if (nc > 52) {
            int temp = this->x + x;
            if (temp > nc - 52) {
                temp = nc - 52;
            } else if (temp < 0) {
                temp = 0;
            }
            this->x = temp;
        } else throw OutOfBounds();
    }

    void Simulation::addYOffset(const int y) {
        if (nl > 18) {
            int temp = this->y + y;
            if (temp > nl - 18) {
                temp = nl - 18;
            } else if (temp < 0) {
                temp = 0;
            }
            this->y = temp;
        } else throw OutOfBounds();
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
                } else throw OutOfBounds();
            }
        }
        entities->push_back(ent);
    }

    void Simulation::kill(int i) {
        if (i < 0 || i >= entities->size()) throw OutOfBounds();
        entities->at(i)->kill();
    }

    int Simulation::getNEntities() {
        return (int) entities->size();
    }

    Entity *Simulation::getEntity(int n) {
        if (n < 0 || n >= entities->size()) throw EntityNotFound();
        return entities->at(n);
    }

    int Simulation::getVar(std::string varName) {
        if (vars->find(varName) == vars->end()) throw VarNotFound();
        return vars->at(varName);
    }

    bool Simulation::alreadyHasFood(int x, int y) {
        for (Entity * e : *entities) {
            if (e->isFood() && e->getY() == y && e->getX() == x)
                return true;
        }
        return false;
    }

    std::vector<Entity *> Simulation::getEntitiesInside(int x1, int y1, int x2, int y2) {
        std::vector<Entity *> vector;
        for (Entity * e: *entities) {
            if (isBetweenOrEquals(e->getX(), e->getY(), x1, y1, x2, y2) && !e->isDead())
                vector.push_back(e);
        }
        return vector;
    }

}