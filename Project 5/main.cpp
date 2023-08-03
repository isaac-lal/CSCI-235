/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

#include <iostream>

#include "DoublyLinkedList.hpp"

#include "CardShop.cpp"

#include "YGOCard.hpp"


int main() {
  CardShop yogi("cards.csv");

  std::cout << "Number of times cards moved: " << yogi.insertionSort(std::less < int > {}, "atk") << std::endl;
  yogi.display();

  return 0;
}