/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

#ifndef YGOCARD_HPP_
#define YGOCARD_HPP_

#include <string>

#include <iostream>

#include <iomanip>

class YGOCard {

  public:

    //default constructor
    YGOCard();
  //parameterized constructor											
  YGOCard(std::string name, std::string type, int level, std::string race, std::string attribute, int atk, int def); //parameterized constructor

  //Accessor functions
  //@return:  the name of the card 
  std::string getName() const;

  //@return:  the type of card (effect, syncro, XYZ, ritual ect) 
  std::string getType() const;

  //@return:  the Level/Rank of the card (1-12) generally
  int getLevel() const;

  //@return:  the race of the monster on the card (spellcaster, machine, fiend)
  std::string getRace() const;

  //@return:     the attribute of card (Earth, Wind, Fire, Do you remember, The 21st Night of September)
  std::string getAttribute() const;

  //@return:  the attack value of the card
  int getAtk() const;

  //@return:    the defense value of the card           
  int getDef() const;

  //Mutator Functions

  //@param: sets the name of the card to the value of the argument
  void setName(std::string name);
  //@param: sets the type of the card to the value of the argument
  void setType(std::string type);
  //@param: sets the rank of the card to the value of the argument
  void setRank(int rank);
  //@param: sets the race of the card to the value of the argument
  void setRace(std::string race);
  //@param: sets the attribute of the card to the value of the argument
  void setAttribute(std::string attribute);
  //@param: sets the attack of the card to the value of the argument
  void setAtk(int atk);
  //@param: sets the defense of the card to the value of the argument
  void setDef(int def);

  //utility
  //@post:  displays all card data member values to the standard output
  void display();
  //@post:  displays the name of the card to the standard output
  void displayName();
  //@return:  true if all data members of rhs are equal to the card's data members, false otherwise
  bool operator == (const YGOCard & rhs) const;
  //@return:  true if at least one data member of rhs is not equal to the card's data members, false otherwise
  bool operator != (const YGOCard & rhs) const; // not equal operator overload

  private: std::string name_;
  std::string type_;
  int level_rank_;
  std::string race_;
  std::string attribute_;
  int atk_;
  int def_;
};

#endif