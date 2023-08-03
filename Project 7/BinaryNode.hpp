/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 7
*/

//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Adapted for CSCI 235000 Project 7 Spring 2023

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.hpp */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template < class T >
  class BinaryNode {
    private: T item; // Data portion
    std::shared_ptr < BinaryNode < T > > leftChildPtr; // Pointer to left child
    std::shared_ptr < BinaryNode < T > > rightChildPtr; // Pointer to right child

    public: BinaryNode();
    BinaryNode(const T & anItem);
    BinaryNode(const T & anItem, std::shared_ptr < BinaryNode < T > > leftPtr, std::shared_ptr < BinaryNode < T > > rightPtr);

    void setItem(const T & anItem);
    T getItem() const;

    bool isLeaf() const;

    std::shared_ptr < BinaryNode < T > > getLeftChildPtr() const;
    std::shared_ptr < BinaryNode < T > > getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr < BinaryNode < T > > leftPtr);
    void setRightChildPtr(std::shared_ptr < BinaryNode < T > > rightPtr);
  }; // end BinaryNode

#include "BinaryNode.cpp"

#endif