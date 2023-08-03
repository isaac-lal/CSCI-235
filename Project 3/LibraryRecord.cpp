/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 3
*/

#include "LibraryRecord.hpp"

#include <vector>


//LibraryRecord() : ArrayBag(){}

/** @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items_, false otherwise
    @post:    adds book to items_.
**/

bool LibraryRecord::checkIn(const Book & book) {
  return (add(book));
}

/** @param:   A reference to a Book object to be checked out   
    @return:  returns true if a book was successfully removed from items_, false otherwise
    @post:    removes the book from the LibraryRecord and if remove was successful, 
    it adds the book to the vector of checked-out books.
**/

bool LibraryRecord::checkOut(const Book & book) {
  if (remove(book)) {
    check_out_history_.push_back(book);
    return true;
  }
  return false;

}

/**
 @param:   A reference to a Book object
@return:  The number of times (int) the referenced Book has been checked out
*/
int LibraryRecord::getCheckOutHistory(Book & book) {
  int count = 0;
  for (int i = 0; i < check_out_history_.size(); i++) {
    if (check_out_history_[i] == book)
      count++;
  }

  return count;
}

/**
    @post: Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out

    For each Book in the LibraryRecord you will output:
            "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n
            It has been checked out [_] times.\n"
**/
void LibraryRecord::display() {
  for (int i = 0; i < item_count_; i++) {
    items_[i].display(); //prints out book info

    std::cout << "It has been checked out " << getCheckOutHistory(items_[i]) << " times.\n";
  }
}

/**
 @post:    Prints the title of each Book in the LibraryRecord
Example:
"title1, title2, title3, title4!\n" Note the commas and exclamation mark.
*/
void LibraryRecord::displayTitles() const {
  for (int i = 0; i < item_count_; i++) {
    std::cout << items_[i].getTitle();
    if (i + 1 == item_count_) //if it is the same size as items_size then it is last element
      std::cout << "!\n";
    else
      std::cout << ", ";

  }
}

/**
 @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
@post:      Duplicates all the items in the LibraryRecord
Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
*/
bool LibraryRecord::duplicateStock() {
  int temp = item_count_;
  //there is 2 items then item_count_ is 2

  for (int i = 0; i < temp; i++)
    add(items_[i]);

  if (item_count_ == (2 * temp))
    return true;

  return false;
}

/**
 @param:   A reference to a book
@return: True if at least one copy of the referenced book was removed from items_, false otherwise 
@post: remove all occurrences of the referenced book
*/
bool LibraryRecord::removeStock(Book & book) {
  while (contains(book))
    remove(book);

  if (contains(book))
    return false;

  return true;
}

/**
 @param:   A reference to another LibraryRecord
@return:  Returns true if the 2 library records have the same contents (including the same 
number of duplicates for each book), regardless of their order. For example, if the current 
holdings of the LibraryRecord are [book1, book2, book3]
and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.

However, [book1, book2, book2, book3] is not equivalent to [book1, book2, book3, book3], because it contains two copies of book2 and only one copy of book3*/
bool LibraryRecord::equivalentRecords(LibraryRecord & lr) {

  for (int i = 0; i < lr.item_count_; i++) {
    if (!(contains(lr.items_[i])) || !(lr.getFrequencyOf(lr.items_[i]) == getFrequencyOf(lr.items_[i])))
      return false;

  }

  return true;

}

/**
    @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, including duplicates.
    Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

    IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and
    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation
    Hint: use getCheckOutHistory and the checkout history vector
*/
void LibraryRecord::operator += (LibraryRecord & lr) {

  std::vector < Book > vect = lr.toVector();

  for (int i = 0; i < lr.getCurrentSize(); i++) {
    if (!(item_count_ < DEFAULT_CAPACITY))
      break;

    add(vect[i]);

    for (int j = 0; j < lr.getCheckOutHistory(lr.items_[i]); j++)
      check_out_history_.push_back(lr.items_[i]);
  }
  /*
  int size= lr.getCurrentSize();

  for(int i = 0; i <size; i++)
  {
      if(!(add(lr.items_[i])))
          return;
      for(int j=0; j < getCheckOutHistory(lr.items_[i]); j++)
      {
          check_out_history_.push_back(lr.items_[i]);
      }
  }
  */
}

/** @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
    Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

    IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and
    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation
    Hint: use getCheckOutHistory and the checkout history vector
*/
void LibraryRecord::operator /= (LibraryRecord & lr) {
  std::vector < Book > vect = lr.toVector();

  for (int i = 0; i < lr.getCurrentSize(); i++) {
    if (!(item_count_ < DEFAULT_CAPACITY))
      break;

    if (!(contains(vect[i]))) {
      add(vect[i]);
      for (int j = 0; j < lr.getCheckOutHistory(lr.items_[i]); j++)
        check_out_history_.push_back(lr.items_[i]);
    }

  }
}

/*
look at checkOut history and then add it with 
int size= lr.getCurrentSize();
for(int = 0; i <size; i++)
{
    if(!(add(lr.items_[i])))
        return;
    for(int j=0; j < getCheckOutHistory(lr.items_[i]; j++))
    {
        checked.out.push_back(lr.items_[i])
    }
}

if (contains(lr.items_[i]))
    continue;
*/