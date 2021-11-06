#ifndef GENSTACK_H
#define GENSTACK_H

#include "DoublyLinkedList.h"
#include <iostream>
#include <exception>

using namespace std;


template <class T> class GenStack{
    public:
        GenStack();//default constructor
        GenStack(bool noLimit);//overloaded constructor
        ~GenStack();//destructor

        //core functions
        void push(T data);
        T pop();

        //helpers
        T peek();
        bool isEmpty();
        bool isFull();
        int getSize();
        void print();

    private:
        DoublyLinkedList<T> *list;
        bool noLimit;
        int mSize;
        int top;
};

template <class T>
GenStack<T>::GenStack(){
    mSize = 128;
    top = -1;
    list = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::GenStack(bool l){
    noLimit = l;
    mSize = 1;
    top = -1;
    list = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack(){
    cout << "stack destructed" << endl;
    delete [] list;
}

template <class T>
void GenStack<T>::push(T data){
    //check if full
    if(isFull()){
        throw runtime_error("stack is full !!!!");
    }
    if (noLimit){
      ++mSize;
    }
    ++top;
    list->insertBack(data);
}

template <class T>
T GenStack<T>::pop(){
    //is it empty?
    if(isEmpty()){
        throw runtime_error("stack empty can NOT pop!!");
    }
    if (noLimit){
      --mSize;
    }
    --top;
    return list->removeBack();
}

template <class T>
T GenStack<T>::peek(){
    //is it empty?
    if(isEmpty()){
        throw runtime_error("stack empty can NOT peek!!");
    }
    T _data = list->removeBack();
    list->insertBack(_data);
    return _data;
}

template <class T>
bool GenStack<T>::isFull(){
    return (top == mSize-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

template <class T>
int GenStack<T>::getSize(){
    return (top + 1);
}

#endif
