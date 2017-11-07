// Name         : Launcher.cpp
// Author       : Kevin Tran
// Version      : 1.00 -- Initial Commit.
// Description  : Launcher.cpp class has a main method that runs the program in
// which it will add very large integers and prints them back out. It utilizes
// LinkedStack to hold and organize the integers one by one. The user entered
// values are created by asking the user to input integers. The inputs are
// handled by Validator.h.

#include "Validator.h"

using namespace std;

//answer method will take in the two stacks full of numbers and construct a
//string that will output the correct answer.
void answer(LinkedStack<int>* one, LinkedStack<int>* two){
    int least = min(one->getElementCount(), two->getElementCount());
    int diff = max(one->getElementCount(), two->getElementCount())-least;
    string computedString = "";
    int carryOver = 0;

    //This portion will create a pointer that will point to the bigger stack.
    LinkedStack<int>* stillLeft;
    if(one->getElementCount()>two->getElementCount()){
        stillLeft=one;
    }else{
        stillLeft=two;
    }

    //for loop will go through all of the (of the minimum size) and maximum size
    //stacks at the minimum required interval.
    for(int i=0; i<least;i++) {
        int answerSum = (one->pop()) + (two->pop()) + carryOver;
        carryOver = answerSum / 10;

        //if statement will check if it is at the end, if it does then print out
        //the total added value of that iteration instead of modulating it to
        //attach the ones place only.
        if(i!=least-1 || (i==least-1 && diff!=0)) {
            computedString = to_string(answerSum % 10) + computedString;
        }else{
            computedString = to_string(answerSum) + computedString;
        }
    }

    //Then pop out everything in that stack and keep adding the numbers to the
    //front of the string each time and return it.
    while(!stillLeft->isEmpty()){
        int answerSum = (stillLeft->pop()-0) + carryOver;
        carryOver = answerSum/10;

        //if statement will check if it is at the end, if it does then print out
        //the total added value of that iteration instead of modulating it to
        //attach the ones place only.
        if(!stillLeft->isEmpty()) {
            computedString = to_string(answerSum % 10) + computedString;
        }else{
            computedString=to_string(answerSum) + computedString;
        }

    }
    cout<<"sum= " + computedString;
}

int main() {
    LinkedStack<int>* one = new LinkedStack<int>();
    LinkedStack<int>* two = new LinkedStack<int>();
    intString(one);
    intString(two);
    answer(one, two);
    return 0;
}