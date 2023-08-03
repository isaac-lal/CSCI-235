/*
Sheridan Siguencia
Sheridan.siguencia98@myhunter.cuny.edu

In this Project 3 we will continue to build on Projects 1 and 2 to work with Templates 
and ADTs.

Using your knowledge of the ArrayBag you will develop a LibraryRecord ADT that will store 
the Book data type you have been working on in the past projects. The LibraryRecord will 
store Books much like an ArrayBag. In fact, LibraryRecord will be a subclass of ArrayBag 
which specializes for storing Books.  Imagine you are engineering a system for librarians 
and you will design the library system through which they access Book information.

*/

#ifndef LIBRARY_RECORD_HPP_
#define LIBRARY_RECORD_HPP_

#include <iostream>

#include <vector>

#include "ArrayBag.hpp"

#include "Book.hpp"


class LibraryRecord: public ArrayBag < Book > {

  public:

    //LibraryRecord();

    /** @param:   A reference to a Book object to be checked in
        @return:  returns true if a book was successfully added to items_, false otherwise
        @post:    adds book to items_.
    **/
    bool checkIn(const Book & book);

  /** @param:   A reference to a Book object to be checked out   
      @return:  returns true if a book was successfully removed from items_, false otherwise
      @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books.
  **/
  bool checkOut(const Book & book);

  /**
   @param:   A reference to a Book object
  @return:  The number of times (int) the referenced Book has been checked out
  */
  int getCheckOutHistory(Book & book);

  /**
      @post:    Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out

      For each Book in the LibraryRecord you will output:
              "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n
              It has been checked out [_] times.\n"
  **/
  void display();

  /**
   @post:    Prints the title of each Book in the LibraryRecord
  Example:
  "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
  */
  void displayTitles() const;

  /**
   @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
  @post:      Duplicates all the items in the LibraryRecord
  Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
  */
  bool duplicateStock();

  /**
   @param:   A reference to a book
  @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
  @post: remove all occurrences of the referenced book
  */
  bool removeStock(Book & book);

  /**
   @param:   A reference to another LibraryRecord
  @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
  and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.

  However, [book1, book2, book2, book3] is not equivalent to [book1, book2, book3, book3], because it contains two copies of book2 and only one copy of book3*/
  bool equivalentRecords(LibraryRecord & lr);

  /**
      @param:   A reference to another LibraryRecord object
      @post:    Combines the contents from both LibraryRecord objects, including duplicates.
      Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

      IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and
      book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation
      Hint: use getCheckOutHistory and the checkout history vector
  */
  void operator += (LibraryRecord & lr);

  /** @param:   A reference to another LibraryRecord object
      @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
      Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

      IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and
      book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation
      Hint: use getCheckOutHistory and the checkout history vector
  */
  void operator /= (LibraryRecord & lr);

  private: std::vector < Book > check_out_history_; //A vector containing a copy of all the Books that have been checked out.

};

#endif //ends LIBRARY_RECORD_HPP_