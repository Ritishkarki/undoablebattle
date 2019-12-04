#ifndef ENUMS_H
#define ENUMS_H

// for move types
enum class MoveType { 
    AttackOne, 
    AttackTwo, 
    Heal 
};

std::string MoveTypeStrings[] = { 
    "AttackOne", 
    "AttackTwo", 
    "Heal" 
};

// for actor types
enum class ActorType { 
    Ghost, 
    Knight, 
    Warrior 
};

std::string ActorTypeStrings[] = { 
    "Ghost", 
    "Knight", 
    "Warrior" 
};

#endif // end enum definitions
