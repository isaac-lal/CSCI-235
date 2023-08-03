/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

#ifndef CARD_SHOP_HPP_
#define CARD_SHOP_HPP_#include "DoublyLinkedList.hpp"

#include "YGOCard.hpp"

#include <iostream>

#include <fstream>

#include <sstream>


class CardShop: public DoublyLinkedList < YGOCard * > {
  public: CardShop() =
    default; //default constructor
  ~CardShop(); //destructor calls clear

  /**
  @pre  : the input file is in csv format: "name,type,level_rank,race,attribute,atk,def"
  @param: the name of the input file
  @post:  Reads the input file and adds pointers to YGOCard objects 
          instantiated with the information read from the file. 
    */
  CardShop(std::string input_file_name); //parameterized constructor

  //@post: displays information of all cards in the shop, one per line
  void display();

  //@param: the index of the first card to be displayed
  //@param: the index of the last card to be displayed
  //@post: displays the names of all cards in the shop with startRange and endRange, 
  //       inclusive, one per line
  void displayName(int startRange, int endRange);

  //@post: removes all cards from the shop
  void clear();

  //@return:  true if all the cards in rhs are equal to the cards in the shop, false otherwise
  bool operator == (const CardShop & rhs) const;

  template < typename Comparator >
  int bubbleSort(Comparator comp, std::string key);

  template < typename Comparator >
  int insertionSort(Comparator comp, std::string key);

  template < typename Comparator >
  int quickSort(Comparator comp, std::string key);

  template < typename Comparator >
  int mergeSort(Comparator comp, std::string key);

};

#endif