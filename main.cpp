#include "Actor.hpp"
#include "enums.hpp"

int main(void){
    vector<Actor*> actors; 
    actors.push_back(new Knight("Lazerus", 4, {attackone, heal})); 
    actors.push_back(new Ghost("Casper", 5, {attacktwo, heal})); 

    cout << *actors[0] << endl;
    cout << *actors[1] << endl;

    while(!actors[0]->IsDead() && !actors[1]->IsDead())
    {
        actors[0]->Attack(*actors[1]); 
        actors[1]->Attack(*actors[0]); 
        
        cout << *actors[0] << endl;
        cout << *actors[1] << endl;
    }

    cout << "Winner is: " << actors[actors[0]->IsDead()? 1 : 0]->GetInfo() << endl;
}