// This file contains a class that Will handle a stack of IMove
#ifndef MOVE_MANAGER
#define MOVE_MANAGER

#include "Stack.hpp"

class MoveManager : public Stack<IMove*> {
    public:
        // takes a move as argument and push into the stack
        void ExecuteMove(IMove* move) {
            move->execute();
            this->Push(move);
        }

        // undo the last move in the stack
        void UndoLastMove() {
            this->Top()->undo();
            this->Pop();
        }
};

#endif