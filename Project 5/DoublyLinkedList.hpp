/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

//
//  DoublyLinkedList.hpp
//
//  A doubly-liked list implementation for class project CSci 235 Software Design and Analysis II
//
//  Created by Tiziana Ligorio
//  Modified 2021

//

#ifndef LIST_H_
#define LIST_H_

#include <iostream>

#include <algorithm>

#include "Node.hpp"

template < class T >
  class DoublyLinkedList {

    public: DoublyLinkedList(); // constructor
    DoublyLinkedList(const DoublyLinkedList < T > & a_list); // copy constructor
    virtual~DoublyLinkedList(); // destructor

    /**@return true if list is empty - item_count_ == 0 */
    bool isEmpty() const;

    /**@return the number of items in the list - item_count_ */
    size_t getLength() const;

    /**
       @param position indicating point of insertion
       @param new_element to be inserted in list
       @post new_element is added at position in list (the node previously at that position is now at position+1)
       @return true always - it always inserts, if position > item_count_ it inserts at end of list */
    bool insert(size_t position,
      const T & new_element);

    /**
       @param position indicating point of deletion
       @post node at position is deleted, if any. List order is retains
       @return true if ther eis a node at position to be deleted, false otherwise */
    virtual bool remove(size_t position);

    /**
       @param position of item to be retrieved
       @return the item at position in list if there is one */
    T getItem(size_t position) const;

    //if position > item_count_ returns nullptr
    Node < T > * getPointerTo(size_t position) const;

    /**
        returns first_ 
      */
    Node < T > * getHeadNode() const;

    /**
  
  @param: i is the index (integer) of the first item we are swapping in the list
  @param: j is the index (integer) of the second item we are swapping in the list
  @pre: i < j
  @post:  swaps the element at position i with the element at position j
  @example we have 1, 2, 3, 4, 5 in our list so calling swap(1,2) will make it:
  1, 3, 2, 4, 5 (note we start from index 0)
*/
    void swap(int i, int j);

    // void bubbleSort();

    // void insertionSort();
    /**@post the list is empty and item_count_ == 0*/
    virtual void clear();

    //added to project 5
    virtual void display();

    protected: Node < T > * first_; // Pointer to first node
    Node < T > * last_; // Pointer to last node
    size_t item_count_; // number of items in the list

  }; // end List

#include "DoublyLinkedList.cpp"

#endif // LIST_H_