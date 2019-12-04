// This file contains battle moves classes definition

#ifndef BATTLE_MOVE_H
#define BATTLE_MOVE_H

#include <random>

// General move
class IMove
{
	public:
		void virtual execute() = 0;
		void virtual undo() = 0;
};

// Move that can either hurt the opponent, or heal the player
class BattleMove : public IMove
{
	public:
		BattleMove(Actor * s, Actor * o);
	protected:
		Actor* self;
		Actor* other;
};

// Move that generate a random damage between 10 and 15
class AttackOne : public BattleMove
{
	public:
		AttackOne(Actor * s, Actor * o);
		void execute();
		void undo();
	private:
		int amount;
};

// Move that generate a random damage between 0 and 25
class AttackTwo : public BattleMove
{
	public:
		AttackTwo(Actor * s, Actor * o);
		void execute();
		void undo();
	private:
		int amount;
};

// Move that generate a random heal amount between 10 and 15
class Heal : public BattleMove
{
	public:
		Heal(Actor * s, Actor * o);
		void execute();
		void undo();
	private:
		int amount;
};

#endif