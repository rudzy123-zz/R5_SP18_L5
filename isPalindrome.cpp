//
//  isPalindrome.cpp
//  Project5
//
//  Created by Rudolf Musika on 3/14/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include <stdio.h>
#include "PrecondViolatedExcept.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <ctype.h>
#include "isPalindrome.h"
#include <string>


bool isPalindrome(const std::string& Entry){
    // Instantiation of Stack
    LinkedStack<char> theStack;
    //Instantiation of Queue
    LinkedQueue<char> theQueue;
    //Declaration of Boolean
    for (unsigned int i(0); i<Entry.length(); i++){
        char z = Entry[i];
        //Enqueue it in queue
        theQueue.enqueue(z);
        //Push it in the stack
        theStack.push(z);
    }
    bool isAPalindrome(true);
    while(!theQueue.isEmpty() && !theStack.isEmpty() &&
          isAPalindrome){
        if(theQueue.peekFront() != theStack.peek()){
            //Update the boolean variable
            isAPalindrome = false;
        }
        else{
            //Perform the dequeue operation on queue
            theQueue.dequeue();
            //Perform the pop operation on the stack
            theStack.pop();
        }
    }
    
    return isAPalindrome;
}
