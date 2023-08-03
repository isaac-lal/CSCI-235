/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 7
*/

#include "BinarySearchTree.cpp"


int main() {
  BinarySearchTree < int > a(100);

  a.add(20);
  a.add(10);
  a.add(30);

  a.add(200);
  a.add(150);

  a.add(300);

  //a.remove(150);

  a.displayPreorder();

  std::cout << "\nInorder: ";
  a.displayInorder();

  //a.displayVector();

  a.makeIncreasingBST();

  a.displayPreorder();

  std::cout << "\nInorder: ";
  a.displayInorder();

  return 0;
}