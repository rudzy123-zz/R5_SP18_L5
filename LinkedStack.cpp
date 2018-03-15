/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  stack.
 *
 *  Adapted from pages 246-8 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 27 Feb 2018
 *
 *  @version 7.0 */

//#define NDEBUG

#include <new>
#include <stdexcept>
#include <exception>
#include <cassert>
#include <new>
#include <memory>
#include "PrecondViolatedExcept.h"

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {
    
    if (!aStack.topPtr) {
        topPtr = nullptr;
    }
    else {
        auto origChainPtr(aStack.topPtr);
        
        try {
            topPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem() );
            
            newChainPtr = topPtr;
            
            origChainPtr = origChainPtr->getNext();
            
            while (origChainPtr) {
                newChainPtr->setNext(std::make_shared<Node<ItemType>>(origChainPtr->getItem()) );
                
                newChainPtr = newChainPtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }
        }
        catch (const std::bad_alloc&) {
            while (!isEmpty() ) {
                pop();
            }
            throw;
        }
    }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

    while (!isEmpty() ) {
        pop();
    }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    
    return !topPtr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {
    
    bool canPush(true);
    
    try {
        topPtr= std::make_shared<Node<ItemType>>(newItem, topPtr);
    }

    catch (const std::bad_alloc&) {
        canPush = false;
    }
    
    return canPush;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {
    
    bool canPop(!isEmpty() );
    
    if (canPop) {
        auto nodeToDeletePtr(topPtr);
        
        topPtr = topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
    }
    
    return canPop;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    //   throw(PrecondViolatedExcep) {

    if (isEmpty() ) {
        std::string message("LinkedStack::peek() ");
        message += "called on an empty stack.";

        throw PrecondViolatedExcept(message);
    }

    return topPtr->getItem();
}


//template <typename ItemType>
//ItemType LinkedStack<ItemType>::peek() const {
//
//    assert(!isEmpty() );
//
//    return topPtr->getItem();
//}
