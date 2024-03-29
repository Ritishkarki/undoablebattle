// source credit course instructor Eugene Lymar
#ifndef STACK_H
#define STACK_H
#include <iostream>
#pragma once
#define MAX_LENGTH 100
class StackEmptyException{};
class StackFullException{};

template <typename T>
class Stack{
private:
        T* data; 
        int top;
        int maxLength;
public:
    Stack():maxLength{MAX_LENGTH}{
        data = new T[maxLength];
        top = -1;
    }
    Stack(int len):maxLength{len}{
        data = new T[maxLength];
        top = -1;
    }    
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(T item);
    T Top(); 
    void Pop();   
};

template <typename T>
void Stack<T>::MakeEmpty(){
    top = -1;
}

template <typename T>
bool Stack<T>::IsEmpty(){
    return top == -1; 
}

template <typename T>
bool Stack<T>::IsFull(){
    return top == maxLength - 1;
}

template <typename T>
void Stack<T>::Push(T item){
    if(IsFull()) throw "max no of moves for battle reached \n";
    
    data[++top] = item;
}
template <typename T>
T Stack<T>::Top(){
    if(IsEmpty()){
        throw "\nYou have undone all of the battle moves and players are in full health \n";
    }

    return data[top];
}

template <typename T>
void Stack<T>::Pop(){
    if(IsEmpty()) throw StackEmptyException();

    top--;
}

#endif // STACK_H