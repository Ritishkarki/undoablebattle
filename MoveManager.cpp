#include <vector>
#include <iostream>
#include "Stack.hpp"
#include "enums.hpp"
#include "BattleMove.hpp"
using namespace std; 

class MoveManager{
    private:
        Stack<IMove*> stack; 
    public:
        MoveManager():
            stack{Stack<IMove*>()}
        {}

        void ExecuteMove(IMove* move){
            move->Execute(); 
            stack.Push(move); 
        }

        void UndoLastMove(){
            if(stack.IsEmpty()){
                cout << "Nothing to undo." << endl;
                return; 
            }
            IMove* cmd = stack.Top(); 
            cmd->Undo(); 
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