/*
Name: Isaac Lal
Email: isaac.lal46@myhunter.cuny.edu
Professor: Tiziana Ligorio
Date: February 10, 2023
*/

#ifndef BOOK_HPP
#define BOOK_HPP

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
      @param      : A flag indicating whether the book is in digital form (a Boolean), with default value False
      @post       : The private members are set to the values of the corresponding parameters.
    */
    Book(std::string title_book, std::string author, int number_pages, bool digital = 0);

    /**
      @param  : the title of the Book
      @post   : sets the Book's title to the value of the parameter
    */
    void setTitle(const std::string &title_book);

    /**
      @return : the title of the Book
    */
    std::string getTitle() const;

    /**
      @param  : the name of the author of the Book
      @post   : sets the Book's author to the value of the parameter
    */
    void setAuthor(const std::string &author);

    /**
      @return : the author of the Book
    */
    std::string getAuthor() const;

    /**
      @param  : a positive integer page count
      @pre    : page count > 0 - books cannot have a negative number of pages
      @post   : sets the page count to the value of the parameter
    */
    void setPageCount(const int &number_pages);

    /**
      @return : the page count
    */
    int getPageCount() const;

    /**
      @post   : sets the digital flag to true
    */
    void setDigital();

    /**
      @return true if the book is available in digital form, false otherwise
      Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
    */
    bool isDigital() const;

  private:
    //private data members 
    std::string title_book_;
    std::string author_;
    int number_pages_;
    bool digital_;
};

#endif //end of BOOK_HPP