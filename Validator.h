// Name         : Validator.h
// Author       : Kevin Tran
// Version      : 1.00 -- Initial Commit.
// Description  : Validator.h class has a method that would ask the user for a
// big integer and will process a number by taking each digit and pushing them
// to the integer LinkedStack.

#ifndef ASSIGNMENT3_3_VALIDATOR_H
#define ASSIGNMENT3_3_VALIDATOR_H

#include <iostream>
#include "LinkedStack.h"
using namespace std;

//intString method
void intString(LinkedStack<int>* ret){
    string input;
    cout<<"Enter a very large number: ";
    cin>>input;
    cout<<endl;
    bool beginning0s = true;

    //while loop will start if constraints are not met. It will clear the cin
    //and give a user error and recurses the process to make sure it is entered
    //correctly.
    for(int i=0; i<input.length(); i++){

        //Use of isDigit here to check if the current character is an integer.
        if(!isdigit(input[i])) {
            cout << "Invalid number input. Try again. " << endl << endl;
            intString(ret);

            //Will not allow any leading zeros that do not help with adding the
            //big integer. Zero entries explicitly called by the user (0 by
            //itself) are ok.
        }else if(beginning0s==true && input[i]=='0' && input.length()!=1){
            continue;
        }
        else{
            beginning0s = false;
            int inp = input[i]-'0';
            ret->push(inp);
        }
    }
}

#endif //ASSIGNMENT3_3_VALIDATOR_H
