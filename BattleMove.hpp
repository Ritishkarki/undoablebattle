#include <cstdlib>
#include "Actor.cpp"

class IMove{
    public:
        virtual void Execute()=0;
		virtual void Undo()=0;
};

class BattleMove: public IMove{
    private:
        Actor* self;
        Actor* other;
    public:
        BattleMove(){};
        BattleMove(Actor* self, Actor* other)
			:self{self}, other{other}
		{}
};

class AttackOne : public BattleMove{
    private:
        int damage;
        Actor* self;
		Actor* other;

    public:
        AttackOne(){}
        AttackOne(Actor* self, Actor* other)
            :self{self}, other{other}
        {
            damage = rand() % (15 - 10) + 10;
        }

        void Execute(){
            other -> Hit(damage);
        }

        void Undo(){
            other -> Heal(damage);
        }
};

class AttackTwo: public BattleMove{
    private:
        int damage;
		Actor* self;
		Actor* other;

    public:
        AttackTwo(){}
        AttackTwo(Actor* self, Actor* other)
           :self{self}, other{other}
        {
            damage = rand() % 25;
        }

        void Execute(){
            other -> Hit(damage);
        }

        void Undo(){
            other -> Heal(damage);
        }
};

class Heal: public BattleMove{
    private:
        int heal;
		Actor* self;
		Actor* other;

    public:
        Heal(){}
        Heal(Actor* self, Actor* other)
           :self{self}, other{other}
        {
            heal = rand() % (15 - 10) + 10;
        }

        void Execute(){
            self -> Heal(heal);
        }

        void Undo(){
            self -> Hit(heal); 
        }
};
