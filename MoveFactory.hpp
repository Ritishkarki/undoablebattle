// This file contains a class that will create Battle Moves
#ifndef BATTLE_MOVE_FACTORY_H
#define BATTLE_MOVE_FACTORY_H

class MoveFactory {
    public:
        static BattleMove* BuildMove(MoveType type, Actor* self, Actor* other) {
            BattleMove* m; 
            switch(type){
                case MoveType::AttackOne:
                    m =  new AttackOne(self, other);
                    break;
                case MoveType::AttackTwo:
                    m = new AttackTwo(self, other);
                    break; 
                case MoveType::Heal:
                    m =  new Heal(self, other);
                    break;
                default: 
                    throw "unknown move";
            }
            return m; 
        }
};

#endif