#include <string>
#include <vector>
#include <iostream>
#include "enums.hpp"
#include "MoveManager.cpp"
using namespace std;
string MoveTypeStrings[3] = {"attackone","attackone","heal"};

class Actor {
	protected:
		string type;
		int health;
		std::vector<MoveType> moves;

    public:

		Actor(){}

		Actor(int health, string type)
			:type{type}, health{health}
		{}

		void DoMove(MoveManager& mgr, MoveType moveType, Actor* other){
			cout << this -> type << " used: " << MoveTypeStrings[static_cast<int>(moveType)] << endl;
			mgr.ExecuteMove(MoveFactory::BuildMove(moveType, this, other));
		}

		//public method to hit THIS actor with damage
		void Hit(int damage){
			health -= damage;
		}

		//public method to heal this actor with an amount
		void Heal(int amount){
			health += amount;
		}

		// vector of MoveTypes
		// MoveType GetMoves(){
		// 	return moves;
		// }

		bool IsDead(){
			if(health == 0){
				return true;
			}else{
				return false;
			}
		}
};

class Ghost: public Actor{
	public:
		Ghost(){}
		Ghost(int health, string type):Actor(health, type){
			type = "Ghost"; 
			health = 100;
		}
		
};

class Knight: public Actor{
	public:
		Knight(){}
		Knight(int health, string type):Actor(health, type){
			type = "Knight"; 
			health = 100;
		}
};

class Warrior: public Actor{
	public:
		Warrior(){}
		Warrior(int health, string type):Actor(health, type){
			type = "Warrior"; 
			health = 100;
		}
};