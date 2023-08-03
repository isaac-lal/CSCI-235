/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <string>

#include <iostream>

class Book {
  public:
    /**
      	Default constructor.
      	Default-initializes all private members. Booleans are default-initialized to False.
   		*/
    Book();

  /**
   Parameterized constructor.
  @param      : The title of the book (a string)
  @param      : The author of the book (a string)
  @param      : The number of pages in the book (a positive int)
  @param      : A flag indicating whether the book is in digital form (a Boolean),
  				with default value False
  @post       : The private members are set to the values of the corresponding parameters.
  */
  Book(std::string title, std::string author, int page_count, bool is_digital_ = false);

  /**
  	 @return : the title of the Book
  */
  std::string getTitle() const; //returns title of book

  /**
  	 @return : the author of the Book
  */
  std::string getAuthor() const; //returns author of book

  /**
  	 @return : the page count
  */
  int getPageCount() const; //returns page count of book

  /**
  	@return : true if the book is available in digital form, false otherwise

  	Note: this is an accessor function and must follow the same convention as
  	all accessor functions even if it is not called getDigital
  */
  bool isDigital() const; //returns true if book is digital

  /**
   	@param  : a reference to title of the Book
  	@post   : sets the Book's title to the value of the parameter
  */
  void setTitle(const std::string & title);

  /**
  	@param  : a reference to the name of the author of the Book
  	@post   : sets the Book's author to the value of the parameter
  */
  void setAuthor(const std::string & author);

  /**
  	@param  : a reference to a positive integer page count
  	@pre    : page count > 0 - books cannot have a negative number of pages
  	@post   : sets the page count to the value of the parameter
  */
  void setPageCount(const int & page_count);

  /**
   @post   : sets the digital flag to true
  */
  void setDigital();

  //addition to project 3

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
  bool operator == (const Book & rhs) const; // Comparison operator overload

  /**
  	@param     : A reference to the right hand side of the != operator.
  	@return     : Returns true if the right hand side book is NOT identical (!=), false otherwise.

  		Note: ALL attributes must be equal for two books to be deemed equal.
  */
  bool operator != (const Book & rhs) const; // Comparison operator overload

  /**
  @post     : displays Book data in the form:
  "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n"     
  */
  virtual void display() = 0;

  /**
   @param:  A reference to a string key
  	@post:   Display book data if key argument matches (key match will be subclass specific) 
  */
  virtual void displayFilter(std::string & key) = 0;

  private:

    std::string title_; // The title of the book (a string)
  std::string author_; // The author of the book (a string)
  int page_count_; // The page count (an integer)
  bool is_digital_; // A flag indicating whether the book is available in digital form (a Boolean)
};

#endif