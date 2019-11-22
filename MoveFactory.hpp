#include <iostream>
#include "enums.hpp"
#include "Actor.cpp"
#include "BattleMove.hpp"

class MoveFactory{
    public:
        static BattleMove* BuildMove(MoveType type, Actor* self, Actor* other){
            BattleMove* m; 
            switch(type){
                case MoveType::attackone:
                    m =  new AttackOne(self, other);
                    break;
                case MoveType::attacktwo:
                    m = new AttackTwo(self, other);
                    break; 
                case MoveType::heal:
                    m =  new Heal(self, other);
                    break;
                default: 
                    cerr << "Unexistent: " << (int)type;
                    throw "Non-existent move";
            }
            return m; 
        }
};