/*
Isaac Lal
2/10/23

In this implementation for a class named "Book", it represents the contents of a book such as the author, title, number of pages, and if it is digital.
Each of these contents are declared in its own private varibles with getters and setters functions. 
*/

#include "Book.hpp"

/**
  Default constructor.
  Default-initializes all private members. Booleans are default-initialized to False.
*/
Book::Book() {
  title_book_ = "";
  author_ = "";
  number_pages_ = 0;
  digital_ = false;
}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive int)
  @param     : A flag indicating whether the book is in digital form (a Boolean), with default value False
  @post      : The private members are set to the values of the corresponding parameters.
*/
Book::Book(std::string title_book, std::string author, int number_pages, bool digital) {
  title_book_ = title_book;
  author_ = author;
  number_pages_ = number_pages;
  digital_ = digital;
}

/**
  @param  : the title of the Book
  @post   : sets the Book's title to the value of the parameter
*/
void Book::setTitle(const std::string & title_book) {
  title_book_ = title_book;
}

/**
  @return : the title of the Book
*/
std::string Book::getTitle() const {
  return title_book_;
}

/**
  @param  : the name of the author of the Book
  @post   : sets the Book's author to the value of the parameter
*/
void Book::setAuthor(const std::string & author) {
  author_ = author;
}

/**
   @return : the author of the Book
*/
std::string Book::getAuthor() const {
  return author_;
}

/**
  @param  : a positive integer page count
  @pre    : page count > 0 - books cannot have a negative number of pages
  @post   : sets the page count to the value of the parameter
*/
void Book::setPageCount(const int & number_pages) {
  if (number_pages > 0) number_pages_ = number_pages;
}

/**
   @return : the page count
*/
int Book::getPageCount() const {
  return number_pages_;
}

/**
  @post   : sets the digital flag to true
*/
void Book::setDigital() {
  digital_ = true;
}

/**
  @return true if the book is available in digital form, false otherwise
  Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
*/
bool Book::isDigital() const {
  return digital_;
}