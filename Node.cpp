/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Implementation file for a node that uses smart pointers.
 *
 *  Adapted from page 297 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 14 Mar 2018
 *
 *  @version 7.0 */

#include <memory>

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem)
: item(anItem) {
}

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType>> nextNodePtr)
: item(anItem),
next(nextNodePtr) {
} // end constructor

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
Node<ItemType>::~Node() {
    
    std::cerr << "Node destructor called. on:"
    << "\n\titem: "
    << item
    << "\n\tnext: "
    << next
    << std::endl;
}

#endif

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    
    item = anItem;
} // end setItem

template <typename ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) {
    
    next = nextNodePtr;
}// end setNext

template <typename ItemType>
ItemType Node<ItemType>::getItem() const {
    
    return item;
}// end getItem

template <typename ItemType>
auto Node<ItemType>::getNext() const {
    
    return next;
} // end getNext
