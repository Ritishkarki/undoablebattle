#include "Actor.cpp"
#include "enums.hpp"

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
