// Battle moves class definition

#ifndef BATTLE_MOVE_H
#define BATTLE_MOVE_H

#include <random>

// base move class
class IMove {
	public:
		void virtual execute() = 0;
		void virtual undo() = 0;
};

// Battle move that will either hurt or Heal the player
class BattleMove : public IMove {
	protected:
		Actor* self;
		Actor* other;

	public:
		BattleMove(Actor * self, Actor * other);
};

//AttackOne class that will generate a random damage between 10 and 15
class AttackOne : public BattleMove {
	private:
		int amount;
		
	public:
		AttackOne(Actor * self, Actor * other);
		void execute();
		void undo();
};

// AttackTwo class that will generate a random damage between 0 and 25
class AttackTwo : public BattleMove {
	private:
		int amount;

	public:
		AttackTwo(Actor * self, Actor * other);
		void execute();
		void undo();
};

// Heal class that will generate a random Heal amount between 10 and 15
class Heal : public BattleMove {
	private:
		int amount;
		
	public:
		Heal(Actor * self, Actor * other);
		void execute();
		void undo();
};

#endif