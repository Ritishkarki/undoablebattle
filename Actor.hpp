// This file contains character classes definition

#ifndef Actor_H
#define Actor_H

#include <vector>

// General game character
class Actor {
	protected:
		int health;
		std::string type;
		std::vector<MoveType> moves;


		friend std::ostream & operator<< (std::ostream & out, const Actor & actor);

	public:
		Actor(int health, std::string type);
		Actor(const Actor & actor);
		Actor & operator= (const Actor & actor);
		
		// performs actor's move, it will go through the MoveManager's method so that history is recorded on the stack
		void doMove(MoveManager & mgr, const MoveType & moveType, Actor * other );
		
		// actor is damaged by certain amount
		void Hit(int damage);

		// actor is healed by certain amount
		void Heal(int amount);

		// get actor type
		std::string GetType() const;

		// list of battle moves
		const std::vector<MoveType> & GetMoves() const;
		
		// checks if the actor is dead
		bool IsDead() const;
};

// Ghost with 100 health and AttackOne and Heal moves
class Ghost : public Actor {
	public:
		Ghost(int health = 100, std::string type = "Ghost") : Actor(health, type) {
			moves.push_back(MoveType::AttackOne);
			moves.push_back(MoveType::Heal);
		}
		
};

// Knight with 100 health and Attackone and Heal moves
class Knight : public Actor {
	public:
		Knight(int health = 100, std::string type = "Knight") : Actor(health, type) {
			moves.push_back(MoveType::AttackTwo);
			moves.push_back(MoveType::Heal);
		}
		
};

// Warrior with 100 health and AttackOne and AttackTwo moves
class Warrior : public Actor {
	public:
		Warrior(int health = 100, std::string type = "Warrior") : Actor(health, type) {
			moves.push_back(MoveType::AttackOne);
			moves.push_back(MoveType::AttackTwo);
		}
		
};

#endif // end actor definition