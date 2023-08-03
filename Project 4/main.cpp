/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#include "Book.cpp"

#include "Manual.cpp"

#include "Textbook.cpp"

#include "Novel.cpp"

#include <iostream>

int main() {
  std::cout << "TEST 1: TEST DEFAULT CONSTRUCTOR & ACCESSORS" << std::endl;

  // Test default constructor
  Novel my_book;

  // Test accessor functions
  std::cout << my_book.getTitle() << std::endl;
  std::cout << my_book.getAuthor() << std::endl;
  std::cout << my_book.getPageCount() << std::endl;
  std::cout << my_book.isDigital() << std::endl;
  std::cout << "no" << my_book.getGenre() << std::endl;
  std::cout << "nothing" << my_book.getCharacterListString() << std::endl;
  std::cout << "film: " << my_book.hasFilmAdaptation() << std::endl;
  std::cout << my_book.getAverageRating() << std::endl;

  std::cout << "\nTEST 2: TEST PARAMETERIZED CONSTRUCTOR & ACCESSORS" << std::endl;

  // Test parameterized constructor
  Novel my_book1("Harry Potter and the Chamber of Secrets", "J.K Rowling", 253, "Fantasy", 1, 1);
  Novel my_book2("Moby Dick", "Herman Melville", 378, "Realistic fiction");

  // Test accessor functions
  std::cout << my_book1.getTitle() << " By " << my_book1.getAuthor() <<
    " with page count " << my_book1.getPageCount() << std::endl;
  std::cout << "Digital: " << my_book1.isDigital() << std::endl;

  std::string k = "realistic fiction";
  my_book2.displayFilter(k);
}