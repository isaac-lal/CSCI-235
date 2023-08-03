/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 7
*/

//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Adapted for CSCI 235000 Project 7 Spring 2023

/** @file BinaryNode.cpp */

#include "BinaryNode.hpp"

#include <cstddef>

template < class T >
  BinaryNode < T > ::BinaryNode(): item(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr) {} // end default constructor

template < class T >
  BinaryNode < T > ::BinaryNode(const T & anItem): item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {} // end constructor

template < class T >
  BinaryNode < T > ::BinaryNode(const T & anItem,
    std::shared_ptr < BinaryNode < T > > leftPtr,
    std::shared_ptr < BinaryNode < T > > rightPtr): item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {} // end constructor

template < class T >
  void BinaryNode < T > ::setItem(const T & anItem) {
    item = anItem;
  } // end setItem

template < class T >
  T BinaryNode < T > ::getItem() const {
    return item;
  } // end getItem

template < class T >
  bool BinaryNode < T > ::isLeaf() const {
    return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
  }

template < class T >
  void BinaryNode < T > ::setLeftChildPtr(std::shared_ptr < BinaryNode < T > > leftPtr) {
    leftChildPtr = leftPtr;
  } // end setLeftChildPtr

template < class T >
  void BinaryNode < T > ::setRightChildPtr(std::shared_ptr < BinaryNode < T > > rightPtr) {
    rightChildPtr = rightPtr;
  } // end setRightChildPtr

template < class T >
  std::shared_ptr < BinaryNode < T > > BinaryNode < T > ::getLeftChildPtr() const {
    return leftChildPtr;
  } // end getLeftChildPtr		

template < class T >
  std::shared_ptr < BinaryNode < T > > BinaryNode < T > ::getRightChildPtr() const {
    return rightChildPtr;
  } // end getRightChildPtr		