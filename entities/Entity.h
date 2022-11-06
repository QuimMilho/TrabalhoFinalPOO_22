#ifndef TRABALHOFINALPOO_22_ENTITY_H
#define TRABALHOFINALPOO_22_ENTITY_H

namespace tppoo {

    class Entity {
    private:
        char representative;
        int x, y, lifetime;
        bool dead, render;
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
        bool isDead();
        virtual bool isAnimal();
        virtual bool isFood();
        virtual bool isCoelho();
        virtual bool isOvelha();
        virtual bool isLobo();
        virtual bool isCanguru();
        virtual bool isAnimMisterio();
        virtual bool isRelva();
        virtual bool isCenoura();
        virtual bool isCorpo();
        virtual bool isBife();
        virtual bool isAlimMisterio();
        void setRender(bool render);
        bool toRender();
        virtual ~Entity();
    };

}

#endif
