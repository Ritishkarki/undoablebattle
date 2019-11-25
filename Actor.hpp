#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <vector>
#include <string>
#include "enums.hpp"

using namespace std;

class Actor{
    protected:
        int health; 
        int damage; 
        bool dead; 
        string type;
        vector<MoveType> moves;

    public:
        Actor(){}
        Actor(string type, int health, vector<MoveType> moves)
            :type{type}, health{health}, moves{moves}
        {} 

        virtual void Attack(Actor& actor) = 0;

        virtual void Hit(int damage){
            health -= damage; 
            health = max(0, health);
            if(health == 0)
                dead = true; 
        } 

        virtual void Heal(int heal){
            health += heal;
        }

        void DoMove(){

        }

        vector<MoveType> GetMoves(){
            return moves;
        }

        bool IsDead(){ return this->dead;}

        string GetInfo(){ return type;}

        friend ostream& operator<<(ostream& out, const Actor& a); 
};

ostream& operator<<(ostream& out, const Actor& a){
    out << a.type << " level: " << ", health: " << a.health; 
    if(a.dead)
        out << " (deceased)"; 
    return out; 
}

class Knight: public Actor{
    private:
        int damage; 
    public:
        Knight(){}
        Knight(string type, int health, vector<MoveType> moves):Actor(type, health, moves){
            type = "Knight";
            health = 100;
            damage = 10; 
            dead = false; 
            moves = {attacktwo, heal};
        }

        void Attack(Actor& actor){
            actor.Hit(damage);
        }
};

class Warrior: public Actor{
    private:
        int damage; 
    public:
        Warrior(){}
        Warrior(string type, int health, vector<MoveType> moves):Actor(type, health, moves){
            type = "Warrior";
            health = 100;
            dead = false; 
            moves={attackone,attacktwo};
        }

        void Attack(Actor& actor){
            actor.Hit(damage);
        }
};

class Ghost: public Actor{
    private:
        int spellBonus; 
    public:
        Ghost(){}
        Ghost(string type, int health, vector<MoveType> moves):Actor(type, health, moves){
            type = "Ghost"; 
            health = 100;
            damage = 5;
            dead = false; 
            moves={attackone, heal};
        }
        
        void Attack(Actor& actor){
            actor.Hit(damage); 
        }
};

class ActorFactory{
    public:
    static Actor* CreateActor(ActorType actor){
        Actor* a;
        switch(actor){
            case ActorType::ghost:
                a = new Ghost();
            case ActorType::knight:
                a = new Knight();
            case ActorType::warrior:
                a = new Warrior();
        }
        return a;
    }
};

#endif // ACTOR_H