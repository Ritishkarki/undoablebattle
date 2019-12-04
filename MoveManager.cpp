#include <iostream>
#include "Stack.hpp"
#include "BattleMoves.hpp"
using namespace std; 

class MoveManager{
    private:
        Stack<IMove*> stack; 
    public:
        MoveManager():
            stack{Stack<IMove*>()}
        {}

        void ExecuteMove(IMove* move){
            move->execute(); 
            stack.Push(move); 
        }

        void UndoLastMove(){
            if(stack.IsEmpty()){
                cout << "Nothing to undo." << endl;
                return; 
            }

            IMove* cmd = stack.Top(); 
            cmd->undo(); 
            delete stack.Top(); 
            stack.Pop(); 
        }

        ~MoveManager(){
            while(!stack.IsEmpty()){
                delete stack.Top(); 
                stack.Pop(); 
            }
        }
}; 