/** 
 * undoable battle game written in c++.
 * Data Structure Assignment3
 * Written by Ritish Karki. Student ID 00676516
 * **/

#include <iostream>
#include <ctime>
// forward declaration of Actor class
class Actor;

#include <enums.hpp>
#include <BattleMove.hpp>
#include <MoveManager.hpp>
#include <MoveFactory.hpp>
#include <Actor.hpp>
#include <ActorFactory.hpp>

#include <Actor.cpp>
#include <BattleMove.cpp>

using namespace std;

int generateRandomMove(string type){
  // for generating different set of random numbers every time
  srand(time(0));

  int moves[2] = {0};
  int randomMoveOption = rand()%2;

  // mapping the correct move set according to the character
  if(type == "Knight"){
   moves[0] = 1;
   moves[1] = 2;
  }else if(type == "Ghost"){
    moves[0] = 0;
    moves[1] = 2;
  }else{
    moves[0] = 0;
    moves[1] = 1;
  }

  // returning random move according to the mapped moves
  return moves[randomMoveOption];
};

int main() {

  int inputOption;
  MoveManager movemanager;

  // selecting and creating a player
  cout << "\nSelect a player:" << '\n' << "1) Ghost" << '\n' << "2) Knight" << '\n' << "3) Warrior" << '\n';
  cin >> inputOption;

  while(inputOption < 1 || inputOption > 3 || !inputOption){
    // if not a numeric option clear the input stream
    if(!inputOption){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
    
    cout << "unknown option, please enter again: ";
    cin >> inputOption;
  };

  cout << "\nYou selected: " << ActorTypeStrings[inputOption-1] << '\n';
  Actor* player = ActorFactory::CreateActor(ActorType(inputOption-1));

  // selecting and creating an opponent
  cout << "\nSelect a Opponent:" << '\n' << "1) Ghost" << '\n' << "2) Knight" << '\n' << "3) Warrior" << '\n';
  cin >> inputOption;

  while(inputOption < 1 || inputOption > 3 || !inputOption){
    // if not a numeric option clear the input stream
    if(!inputOption){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }

    cout << "unknown option, please enter again: ";
    cin >> inputOption;
  };

  cout << "\nYou selected: " << ActorTypeStrings[inputOption-1] << '\n';

  Actor* opponent = ActorFactory::CreateActor(ActorType(inputOption-1));


  // begining the match after creating the actors
  cout << "\n=====================================";
  cout << "\nBeginning match!" << '\n';
  cout << "[" << (*player) << "],[" << (*opponent) << "]\n";
  cout << "=====================================" << '\n';

  while (not (*player).IsDead() and not (*opponent).IsDead()) {
    cout << "\nChoose a move:" << '\n' << "1) P1 -> P2" << '\n' << "2) P2 -> P1" << '\n' << "3) Undo" << '\n';
    cin >> inputOption;

    cout << "\n--------------------------------------\n";

    while(inputOption < 1 || inputOption > 3 || !inputOption){
      // if not a numeric option clear the input stream
      if(!inputOption){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
      }
      
      cout << "unknown option, please enter again: ";
      cin >> inputOption;
    };

    // generate random number selecting the move type
    int randomMoveOption;

    if (inputOption == 1) {  // if player performs move on the opponent
      randomMoveOption = generateRandomMove(player -> GetType());
      (*player).doMove(movemanager, MoveType(randomMoveOption), opponent);
    } else if (inputOption == 2){ // if opponent performs move on the player
      randomMoveOption = generateRandomMove(opponent -> GetType());
      (*opponent).doMove(movemanager, MoveType(randomMoveOption), player);
    } else { //undo the last move
      try{
          movemanager.UndoLastMove();
      } catch(const char* & exec) {
          cout << exec << '\n';
      }
    }

    cout << "[" << (*player) << "],[" << (*opponent) << "]\n";
    cout << "--------------------------------------\n";
  }

  return 0;
}