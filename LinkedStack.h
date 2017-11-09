// Name         : LinkedStack.h
// Modified     : Kevin Tran
// Version      : 1.03 -- Fixed constructor.
// Description  : LinkedStack class implements itself as if it was a LinkedList
// but behaviorally acts as if it was a Stack. It's public methods are there as
// if it was a Stack. It's private variables are similar to those seen in
// LinkedList and Stack. This LinkedStack, like other structures, can be used
// for different types of Object types.

#ifndef ASSIGNMENT3_3_LINKEDSTACK_H
#define ASSIGNMENT3_3_LINKEDSTACK_H

#include <iostream>
using namespace std;

//node definition
template <class T>
struct node{
    T data;
    node<T>* next;
};

//LinkedStack class definition with elements of LinkedList and Stack. Overrides
// the << operator so actual information can be outputted effectively.

template <class T>
class LinkedStack {
private:
    //curSize is the current number of elements inside the LinkedStack can have
    //while size is the maximum number of elements that a LinkedStack can hold.
    int size, curSize;

    //Utilizes same node system as seen in LinkedList.
    node<T> *front, *back;

public:
    LinkedStack(int=-1);
    bool isEmpty();
    bool isFull();
    int getElementCount();
    void destroy();
    void push(T&);
    T pop();
    T printTop();
    template <class U>
    friend ostream& operator<<(ostream& os, const LinkedStack<U>* stack);
    virtual ~LinkedStack();
};

//currentSize outputs the number of elements currently in the LinkedStack.
template <class T>
int LinkedStack<T>::getElementCount(){
    return this->curSize;
}

//Constructor (also the default) that takes in a integer that limits the size of
//the LinkedStack. It has the ability to be not size bounded (unlimited) by
// setting the size to -1.
template <class T>
LinkedStack<T>::LinkedStack(int sizeSet) {

    //if it is 0 or some negative integer other than -1, output a warning to
    //console and default the size to unlimited (size to -1)
    if(sizeSet<-1 || sizeSet==0){
        cout<<"Size cannot be zero or less than -1. All are unknown operation "
            << "values. Defaulted to unlimited (-1). ";
        sizeSet=-1;
    }
    this->curSize=0;
    this->size = sizeSet;
}

//overloaded output operator will print all elements in the stack from the
//bottom(left-most output) to the top(right most output). Warning message will
// pop out in console in case the LinkedStack was empty.
template <class T>
ostream& operator<<(ostream& os, const LinkedStack<T>* stack){
    if (stack->curSize!=0){
        node<T> *p = (stack->front);
        os<<"From the bottom(left) to the top(right): ";
        while (p != stack->back && &p != NULL) {
            os << p->data << " ";
            p = p->next;
        }
        os << p->data;
    }else{
        os << "There is nothing in this current LinkedStack. ";
    }
    return os;
}

//Default (virtual) destructor which calls destroy to destroy the current
//LinkedStack.
template <class T>
LinkedStack<T>::~LinkedStack() {
    destroy();
}

//checks to see if the number of items in the LinkedStack is zero.
template <class T>
bool LinkedStack<T>::isEmpty(){
    return curSize==0;
}

//checks to see if the number of items in the stack reaches the stated max
//number of elements for that LinkedStack.
template <class T>
bool LinkedStack<T>::isFull(){
    return size>-1&&curSize==size;
}

//push method takes in the item of type T and puts it into the LinkedStack.
//Warning message will pop out in console in case the LinkedStack is already
//full upon attempted adding.
template <class T>
void LinkedStack<T>::push(T& data1){

    //if this if statement is valid, then the first node (front), will have its
    //data filled.
    if(isEmpty()){
        this->front=this->back = new node<T>;
        this->front->data=data1;
        this->curSize++;

        //else if the LinkedStack is not full at the moment, make another node next
        //to it so new data can be added to the rear.
    }else if(!isFull()){
        this->back->next = new node<T>;
        this->back=back->next;
        this->back->data=data1;
        this->curSize++;
    }else{
        cout<<"LinkedStack is full. Cannot push. "<<endl;
    }
}

//pop takes out the last element from the LinkedStack and returns it. Warning
//message will pop out in console in case the LinkedStack was empty.
template <class T>
T LinkedStack<T>::pop(){
    if(!isEmpty()){

        //there are two nodes, find will find the last node while findBefore
        //will keep the reference of the node before the lsat node.
        node<T> *find = this->front;
        node<T> *findBefore;
        while(find!=this->back){
            findBefore=find;
            find=find->next;
        }

        //Keeps a reference of the item in the last node to return later.
        T d = this->back->data;

        //the findBefore node is used to reaffix the back node to the correct
        //node that still exists and is the new back node.
        this->back=findBefore;

        //finally delete the last node, change the current item size, and return
        //the temporary item.
        delete find;
        curSize--;
        return d;
    }else{
        cout<<"LinkedStack is empty. Cannot pop. ";
    }
}

//printTop prints the top element of the LinkedStack (the last in). Warning
//message will pop out in console in case the LinkedStack was empty.
template <class T>
T LinkedStack<T>::printTop(){
    if(!isEmpty()){
        return this->back->data;
    }else{
        cout<<"LinkedStack is empty. Nothing is on the top. ";
    }
}

//destroy method pops everything in the LinkedStack until nothing is left.
template <class T>
void LinkedStack<T>::destroy(){
    while(isEmpty()){
        pop();
    }
}

#endif //ASSIGNMENT3_3_LINKEDSTACK_H
