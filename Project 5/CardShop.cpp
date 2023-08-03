/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

#include "CardShop.hpp"

#include "Node.hpp"

#include <iostream>

#include <fstream>

#include <sstream>


/**
  @pre  : the input file is in csv format: "name,type,level_rank,race,attribute,atk,def"
  @param: the name of the input file
  @post:  Reads the input file and adds pointers to YGOCard objects 
          instantiated with the information read from the file. 
    */
CardShop::CardShop(std::string input_file_name) {
  std::ifstream fin(input_file_name);
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading. \n";
    exit(1); // exit if failed to open the file
  }
  //we don't use the first line
  std::string ignore;
  getline(fin, ignore);

  //the columns of the csv associated with the data members
  std::string name, type, race, attribute;
  int level_rank, atk, def;

  std::string temp_string;
  int temp_int;
  int item_counter = 0;
  while (getline(fin, temp_string, ',')) {
    name = temp_string;

    getline(fin, type, ',');

    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    level_rank = temp_int;

    getline(fin, race, ',');

    getline(fin, attribute, ',');

    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    atk = temp_int;

    getline(fin, temp_string);
    std::istringstream(temp_string) >> temp_int;
    def = temp_int;

    //create new card
    YGOCard * card_ptr = new YGOCard(name, type, level_rank, race, attribute, atk, def);

    //add to linked list and increment counter
    insert(item_counter++, card_ptr);
  }
}

//@post: removes all cards from the shop
//Deallocate and delete items 
void CardShop::clear() {
  for (int i = 0; i < item_count_; i++) {
    YGOCard * ptr = getItem(i);
    delete ptr;
    ptr = nullptr;
  }
  DoublyLinkedList::clear();
}

//destructor
CardShop::~CardShop() {
  clear();
}

//@post: displays information of all cards in the shop, one per line
void CardShop::display() {
  for (int i = 0; i < item_count_; i++) {
    getItem(i) -> display();
  }
}

//@param: the index of the first card to be displayed
//@param: the index of the last card to be displayed
//@post: displays the names of all cards in the shop with startRange and endRange, 
//       inclusive, one per line
void CardShop::displayName(int startRange, int endRange) {
  for (int i = startRange; i <= endRange; i++) {
    getItem(i) -> displayName();
    if (i != endRange) {
      std::cout << ", ";
    } else {
      std::cout << std::endl;
    }
  }
}

//@return:  true if all the cards in rhs are equal to the cards in the shop, false otherwise
bool CardShop::operator == (const CardShop & rhs) const {
  if (getLength() != rhs.getLength()) {
    return false;
  }
  for (int i = 0; i < getLength(); i++) {
    if ( * (getPointerTo(i) -> getItem()) == * (rhs.getPointerTo(i) -> getItem())) {} else {
      return false;
    }
  }
  return true;
}

/**
Bubble sort
*/

template < typename Comparator >
  int CardShop::bubbleSort(Comparator comp, std::string key) {
    int count = 0;
    for (int i = 0; i < getLength(); i++) {
      for (int j = 0; j < getLength() - 1; j++) {

        if (key == "atk") {
          if (comp(getItem(j + 1) -> getAtk(), getItem(j) -> getAtk())) {
            swap(j, j + 1);
            count++;
          }
        }

        if (key == "def") {
          if (comp(getItem(j + 1) -> getDef(), getItem(j) -> getDef())) {
            swap(j, j + 1);
            count++;
          }
        }
      }

    }

    return count;
  }

template < typename Comparator >
  int CardShop::insertionSort(Comparator comp, std::string key) {
    int count = 0;

    // for(int i =0; i < getLength(); i++)
    //   for (int j =i; j >0; j-- )
    //   {
    //     if(key == "atk")
    //     {
    //       if (comp(getItem(j)->getAtk(), getItem(j-1)->getAtk()))
    //       {
    //         swap(j, j-1);
    //         count++;
    //       }else{
    //         break;
    //       }
    //     } 

    //     if(key == "def")
    //     {
    //       if (comp(getItem(j)->getAtk(), getItem(j-1)->getAtk()))
    //       {
    //         swap(j, j-1);
    //         count++;
    //       }else{
    //         break;
    //       }
    //     } 
    //   }
    int size = getLength();
    // unsorted = first index of the unsorted region,
    // Initially, sorted region is the_array[0],
    // unsorted region is the_array[1 ... size-1].
    // In general, sorted region is the_array[0 ... unsorted-1],
    // unsorted region the_array[unsorted ... size-1]
    for (int unsorted = 1; unsorted < size; unsorted++) {
      // At this point, the_array[0 ... unsorted-1] is sorted.
      // Keep swapping item to be inserted currently at the_array[unsorted]
      // with items at lower indices as long as its value is >
      int current = unsorted; //the index of the item currently being inserted
      if (key == "atk") {
        while ((current > 0) && comp((getItem(current) -> getAtk()), (getItem(current - 1) -> getAtk()))) {

          swap(current - 1, current);
          count++;
          current--;
        }
      }

      if (key == "def") {
        while ((current > 0) && comp((getItem(current) -> getDef()), (getItem(current - 1) -> getDef()))) {

          swap(current - 1, current);
          count++;
          current--;
        }
      } // end while
    } // end for

    return count;
  }

template < typename Comparator >
  int CardShop::quickSort(Comparator comp, std::string key) {
    int count = 0;

    return count;
  }

template < typename Comparator >
  int CardShop::mergeSort(Comparator comp, std::string key) {

    int count = 0;

    return count;
  }