/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio for CSCI 235 Hunter College

/** @file Node.cpp 
    Listing 4-2 */
#include "Node.hpp"
 //#include <cstddef>

//default constructor
template < class ItemType >
  Node < ItemType > ::Node(): next_(nullptr) {} // end default constructor

// parameterized constructor
template < class ItemType >
  Node < ItemType > ::Node(const ItemType & an_item): item_(an_item), next_(nullptr) {} // end constructor

// parameterized constructor
template < class ItemType >
  Node < ItemType > ::Node(const ItemType & an_item, Node < ItemType > * next_node_ptr):
  item_(an_item), next_(next_node_ptr) {} // end constructor

/**@param an_item the data item */
template < class ItemType >
  void Node < ItemType > ::setItem(const ItemType & an_item) {
    item_ = an_item;
  } // end setItem

/**@param next_node_ptr a pointer to the next node in the chain*/
template < class ItemType >
  void Node < ItemType > ::setNext(Node < ItemType > * next_node_ptr) {
    next_ = next_node_ptr;
  } // end setNext

/**@param previous_node_ptr a pointer to the previous node in the chain*/
template < class ItemType >
  void Node < ItemType > ::setPrevious(Node < ItemType > * previous_node_ptr) {
    previous_ = previous_node_ptr;
  } // end setPrevious

/**@return returns the data item*/
template < class ItemType >
  ItemType Node < ItemType > ::getItem() const {
    return item_;
  } // end getItem

/**@return returns a pointer to the next node in the chain*/
template < class ItemType >
  Node < ItemType > * Node < ItemType > ::getNext() const {
    return next_;
  } // end getNext

/**@return returns a pointer to the previous node in the chain*/
template < class ItemType >
  Node < ItemType > * Node < ItemType > ::getPrevious() const {
    return previous_;
  } // end getPrevious