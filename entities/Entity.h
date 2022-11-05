#ifndef TRABALHOFINALPOO_22_ENTITY_H
#define TRABALHOFINALPOO_22_ENTITY_H

namespace tppoo {

    class Entity {
    private:
        char representative;
        int x, y, lifetime;
        bool dead;
    protected:
        Entity(char c, int x, int y);
        void addLifetime();
        void setX(int n);
        void setY(int n);
    public:
        char getChar();
        virtual int tick() = 0;
        int getLifetime();
        int getX();
        int getY();
        void kill();
    };

}

#endif
