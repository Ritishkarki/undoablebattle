// This class produces actors according to the given type
#ifndef ACTOR_FACTORY_H
#define ACTOR_FACTORY_H

class ActorFactory {
    public:
        static Actor* CreateActor(ActorType actor) {
            switch(actor) {
                case ActorType::Ghost:
                    return new Ghost;
                case ActorType::Knight:
                    return new Knight;
                case ActorType::Warrior:
                    return new Warrior;
                default:
                    throw "Non-existent actor type";
            }
        }
};
#endif