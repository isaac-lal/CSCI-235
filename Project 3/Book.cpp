/*
Sheridan Siguencia
Sheridan.siguencia98@myhunter.cuny.edu


creates a Book class with author, title, number of pages, 
and determines if it is difital or not 
*/

#include "Book.hpp"

Book::Book(): title_ {
  ""
}, author_ {
  ""
}, page_count_ {
  0
}, is_digital_ {
  false
} {}

/**
  Parameterized constructor.
  @param      : The title of the book (a string)
  @param      : The author of the book (a string)
  @param      : The number of pages in the book (a positive int)
  @param      : A flag indicating whether the book is in digital form (a Boolean),
                with default value False
  @post       : The private members are set to the values of the corresponding parameters.
*/
Book::Book(std::string title, std::string author, int page_count, bool is_digital):
  title_ {
    title
  }, author_ {
    author
  }, page_count_ {
    page_count
  }, is_digital_ {
    is_digital
  } {}

/**
@param     : A reference to the right hand side of the == operator.
@return     : Returns true if the right hand side book is the identical, false otherwise.

Note: ALL attributes must be equal for two books to be deemed equal.

Example: In order for book1 to be == to book 2 we must have:
- The same title
- The same author
- The same page count
- They must either be both digital or both not
*/
bool Book::operator == (const Book & b) {
  if ((title_ == b.title_) && (author_ == b.author_) && (page_count_ == b.page_count_) && (is_digital_ == b.is_digital_))
    return true;

  return false; // if not the same then false
}

/**
 @param     : A reference to the right hand side of the != operator.
@return     : Returns true if the right hand side book is NOT identical (!=), false otherwise.

Note: ALL attributes must be equal for two books to be deemed equal.
*/

bool Book::operator != (const Book & b) {
  if ((title_ == b.title_) && (author_ == b.author_) && (page_count_ == b.page_count_) && (is_digital_ == b.is_digital_))
    return false;

  return true; // if not the same then true
}

/**
 @post     : displays Book data in the form:
"[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n"     
*/
void Book::display() const {
  std::string digg = (is_digital_) ? "It is" : "It is not";
  std::cout << title_ << "is written by " << author_ << ". Page Count: " << page_count_ << ". " << digg << " available digitally.\n";
}

/**
   @return : the title of the Book
*/
std::string Book::getTitle() const {
  return title_;
}
/**
  @return : the author of the Book
*/
std::string Book::getAuthor() const {
  return author_;
}

/**
  @return : the page count
*/
int Book::getPageCount() const {
  return page_count_;
}

/**
  @return : true if the book is available in digital form, false otherwise

  Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
*/
bool Book::isDigital() const {
  return is_digital_;
}

/**
  @param  : a reference to title of the Book
  @post   : sets the Book's title to the value of the parameter
*/
void Book::setTitle(const std::string & title) {
  title_ = title;
}

/**
  @param  : a reference to the name of the author of the Book
  @post   : sets the Book's author to the value of the parameter
*/
void Book::setAuthor(const std::string & author) {
  author_ = author;
}

/**
  @param  : a reference to a positive integer page count
  @pre    : page count > 0 - books cannot have a negative number of pages
  @post   : sets the page count to the value of the parameter
*/
void Book::setPageCount(const int & page_count) {
  if (page_count > 0) {
    page_count_ = page_count;
  }
}

/**
  @post   : sets the digital flag to true
*/
void Book::setDigital() {
  is_digital_ = true;
}