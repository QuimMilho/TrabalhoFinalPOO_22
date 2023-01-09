#ifndef TRABALHOFINALPOO_22_ENTITY_HPP
#define TRABALHOFINALPOO_22_ENTITY_HPP

namespace tppoo {

    class Entity {
    private:
        char representative;
        int x, y, lifetime;
        bool dead;
        bool createNew(int newX, int newY);
    protected:
        Entity(char c, int x, int y);
        bool reproduce(int radiusX, int radiusY);
        bool reproduce(int radius);
    public:
        void addLifetime();
        char getChar() const;
        virtual int tick() = 0;
        int getLifetime() const;
        int getX() const;
        int getY() const;
        void kill();
        bool isDead() const;
        virtual bool isAnimal() const;
        virtual bool isFood() const;
        virtual bool isCoelho() const;
        virtual bool isOvelha() const;
        virtual bool isLobo() const;
        virtual bool isCanguru() const;
        virtual bool isAnimMisterio() const;
        virtual bool isRelva() const;
        virtual bool isCenoura() const;
        virtual bool isCorpo() const;
        virtual bool isBife() const;
        virtual bool isAlimMisterio() const;
        virtual ~Entity();
        void setX(int n);
        void setY(int n);
    };

}

#endif
