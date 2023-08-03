/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#include "LibraryRecord.hpp"


/** default constructor with pointer Books**/
LibraryRecord::LibraryRecord(): ArrayBag < Book * > () {}

/** @param:   A reference to file that is to be read
    @post:      A parameterized constructor that read file 
    with these params in order
  title,author,page_count,is_digital,genre,subject,grade_level,
  has_film_adaptation,has_review_questions,device_model,website,book_type
*/
LibraryRecord::LibraryRecord(const std::string & file) {
  std::ifstream file_name(file); //open file to read 

  //variable holders of the data needed for Books subclasses
  std::string sentence, holder, title, author, genre, subject, device_model, website;
  int page_count, book_type;
  bool is_digital, has_film_adaptation, has_review_questions;
  grade_level grades = NONE;

  while (std::getline(file_name, sentence)) {
    //streams the sentence
    std::istringstream s(sentence);

    std::getline(s, holder, ',');
    title = holder;

    std::getline(s, holder, ',');
    author = holder;

    std::getline(s, holder, ',');
    std::istringstream page(holder); //convert to int
    page >> page_count;

    std::getline(s, holder, ',');
    std::istringstream digtal(holder); //convert to bool
    digtal >> is_digital;

    std::getline(s, holder, ',');
    genre = holder;

    std::getline(s, holder, ',');
    subject = holder;

    std::getline(s, holder, ',');
    if (holder == "ELEMENTARY")
      grades = ELEMENTARY;
    else if (holder == "JUNIOR_HIGH")
      grades = JUNIOR_HIGH;
    else if (holder == "HIGH SCHOOL")
      grades = HIGH_SCHOOL;
    else if (holder == "COLLEGE")
      grades = COLLEGE;
    else
      grades = NONE;

    std::getline(s, holder, ',');
    std::istringstream film(holder);
    film >> has_film_adaptation;

    std::getline(s, holder, ',');
    std::istringstream review(holder);
    review >> has_review_questions;

    std::getline(s, holder, ',');
    device_model = holder;

    std::getline(s, holder, ',');
    website = holder;

    std::getline(s, holder); //defualt looks for \n
    std::istringstream type(holder);
    type >> book_type;

    //Dynamically allocating each Book pointer. 
    if (book_type == 1) {
      //title, author, page_count, is_digital, genre, has_film_adaptation
      Book * novel = new Novel(title, author, page_count, genre, is_digital, has_film_adaptation);
      checkIn(novel);
    } else if (book_type == 2) {
      //title, author, page_count, is_digital, subject, grade_level, has_review_questions
      Book * textbook = new Textbook(title, author, page_count, subject, is_digital, grades, has_review_questions);
      checkIn(textbook);

    } else if (book_type == 3) {
      //title, author, page_count, is_digital, device_model, website, visual_aid doesn't exists in this program
      Book * manual = new Manual(title, author, page_count, device_model, is_digital, website, 0);
      checkIn(manual);
    }
  }

  file_name.close(); //close file
}

/** 
    @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items, false otherwise
    @post:    adds book to items.
*/
bool LibraryRecord::checkIn(Book * new_entry) {
  bool has_room = (item_count_ < DEFAULT_CAPACITY);
  if (has_room) {
    items_[item_count_] = new_entry;
    item_count_++;
    return true;
  } // end if

  return false;

  /*
  // Add to beginning of chain: new node references rest of chain;
  // (head_ptr_ is null if chain is empty)
  Node<T>* new_node_ptr = new Node<T>;
  new_node_ptr->setItem(new_entry);
  new_node_ptr->setNext(head_ptr_); // New node points to chain
  head_ptr_ = new_node_ptr;// New node is now first node
  item_count_++;
  return true;
  */
}

/** @param:   A reference to a Book object to be checked out   
    @return:  returns true if a book was successfully removed from items_, false otherwise
    @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the check_out_history_ vector.
 **/
bool LibraryRecord::checkOut(Book * an_entry) {
  int found_index = getIndexOf(an_entry);
  bool can_remove = !isEmpty() && (found_index > -1);
  if (can_remove) {
    item_count_--;
    items_[found_index] = items_[item_count_];
    check_out_history_.push_back(an_entry);
  }

  return can_remove;
}

/**
    @post:    Outputs the names of the Books in the LibraryRecord and the number of times each Book has been checked out

      For each Book in the LibraryRecord you will output:
             [title_] is written by [author_]. Page Count: [page_count_]. [it is / is not] available digitally.\n
             It has been checked out [_] times.
**/
void LibraryRecord::display() {
  for (int i = 0; i < item_count_; i++) {
    int count = getCheckOutHistory(items_[i]);
    items_[i] -> display();
    std::cout << "It has been checked out " << count << " times." << std::endl;
  }
}

void LibraryRecord::displayFilter(std::string & key) {
  for (int i = 0; i < getCurrentSize(); i++)
    items_[i] -> displayFilter(key);
}

/**
  @post:    Prints the title of each Book in the LibraryRecord
  Example:
  "title1, title2, title3, title4!" Note the commas and exclamation mark.
*/
void LibraryRecord::displayTitles() {
  for (int i = 0; i < item_count_; i++) {
    if (i < item_count_ - 1) {
      std::cout << items_[i] -> getTitle() << ", ";
    } else {
      std::cout << items_[i] -> getTitle() << "!\n";
    }
  }
}

/**
  @param:   A reference to a Book object
  @return:  The number of times (int) the referenced Book has been checked out
*/
int LibraryRecord::getCheckOutHistory(Book * an_entry) {
  int count = 0;

  for (int j = 0; j < check_out_history_.size(); j++) {
    if (check_out_history_[j] == an_entry) {
      count++;
    }
  }
  return count;
}

/** @param:   A reference to another ArrayBag object
      @post:    Combines the contents from both ArrayBag objects, EXCLUDING duplicates.
      Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

      IMPORTANT: We are carrying over the amount of times a book has been checked out.
      If book4 is in LibraryRecord2 and has been checked out 2 times then it should still be checked out 2 times in LibraryRecord2
      Hint: use getCheckOutHistory and your checkOutHistory_ vector
    */
void LibraryRecord::operator /= (LibraryRecord a_library_record) {
  int index = 0;
  int itemsToAdd = a_library_record.item_count_;
  while (itemsToAdd > 0) {
    if (this -> item_count_ == DEFAULT_CAPACITY) {
      break;
    }
    if (contains(a_library_record.items_[index])) {
      break;
    }
    this -> checkIn(a_library_record.items_[index]);
    int counter = a_library_record.getCheckOutHistory(a_library_record.items_[index]);
    for (int i = 0; i < counter; i++) {
      check_out_history_.push_back(a_library_record.items_[index]);
    }
    index++;
    itemsToAdd--;
  }
}

/**
       @param:   A reference to another LibraryRecord object
       @post:    Combines the contents from both LibraryRecord objects, including duplicates.
       Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

       IMPORTANT: We are carrying over the amount of times a book has been checked out.
       If book4 is in LibraryRecord2 and has been checked out 2 times then it should still be checked out 2 times in LibraryRecord2
       Hint: use getCheckOutHistory and your checkOutHistory_ vector
   */
void LibraryRecord::operator += (LibraryRecord a_library_record) {
  int index = 0;
  int itemsToAdd = a_library_record.item_count_;
  while (itemsToAdd > 0) {
    if (this -> item_count_ == DEFAULT_CAPACITY) {
      break;
    }
    this -> checkIn(a_library_record.items_[index]);
    int counter = a_library_record.getCheckOutHistory(a_library_record.items_[index]);
    for (int i = 0; i < counter; i++) {
      check_out_history_.push_back(a_library_record.items_[index]);
    }
    index++;
    itemsToAdd--;
  }
}

/**
       @param:   A reference to another LibraryRecord object
       @post:    Combines the contents from both LibraryRecord objects, including duplicates.
       Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

       IMPORTANT: We are carrying over the amount of times a book has been checked out.
       If book4 is in LibraryRecord2 and has been checked out 2 times then it should still be checked out 2 times in LibraryRecord2
       Hint: use getCheckOutHistory and your checkOutHistory_ vector
   */
std::vector < Book * > LibraryRecord::toVector() {
  std::vector < Book * > bag_contents;
  for (int i = 0; i < item_count_; i++)
    bag_contents.push_back(items_[i]);

  return bag_contents;
}

/**
  @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
  @post:      Duplicates all the items in the LibraryRecord
  Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
*/
bool LibraryRecord::duplicateStock() {
  if (item_count_ * 2 > DEFAULT_CAPACITY) {
    return false;
  }

  for (int i = 0; i < item_count_; i++) {
    items_[i + item_count_] = items_[i];
  }
  item_count_ = item_count_ * 2;
  return true;
}

/**
  @param:   A reference to a book
  @return: True or false depending on whether or not an item was removed
  @post: remove all elements of that book
*/
bool LibraryRecord::removeStock(Book * an_entry) {
  bool res = false;
  while (contains(an_entry)) {
    int found_index = getIndexOf(an_entry);
    item_count_--;
    for (int i = found_index; i < item_count_; i++) {
      items_[i] = items_[i + 1];
    }
    res = true;
  }
  return res;
}

/**
  @param:   A reference to another LibraryRecord
  @return:  Returns true if the 2 library records have the contents, regardless of their order. 
            For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
            and those of the referenced LibraryRecord are [book3, book1, book2], it will return true
*/
bool LibraryRecord::equivalentRecords(LibraryRecord a_library_record) {
  bool result = true;

  //copy contents to count duplicates by marking them as empty
  // use copy because should not modify items_
  std::vector < Book * > library_copy = toVector();
  std::vector < Book * > other_copy = a_library_record.toVector();
  Book * empty = nullptr;

  for (int i = 0; i < library_copy.size(); i++) {
    for (int j = 0; j < other_copy.size(); j++) {
      if (other_copy[j] != empty && other_copy[j] == library_copy[i]) {
        library_copy[i] = empty;
        other_copy[j] = empty;
      }
    }
  }
  //check that all entries have been accounted for
  // i.e. there are no non-empty left
  for (int i = 0; i < item_count_; i++) {
    if (library_copy[i] != empty) {
      result = false;
    }
  }
  //check that all entries have been accounted for
  // i.e. there are no non-empty left
  for (int i = 0; i < a_library_record.item_count_; i++) {
    if (other_copy[i] != empty) {
      result = false;
    }
  }
  return result;
}