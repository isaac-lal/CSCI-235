/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 5
*/

#include "YGOCard.hpp"


//default constructor
YGOCard::YGOCard(): name_ {
    ""
  }, type_ {
    ""
  }, level_rank_ {
    0
  }, race_ {
    ""
  },
  attribute_ {
    ""
  }, atk_ {
    0
  }, def_ {
    0
  } {}

//parameterized constructor		
YGOCard::YGOCard(std::string name, std::string type, int level, std::string race, std::string attribute, int atk, int def):
  name_ {
    name
  }, type_ {
    type
  }, level_rank_ {
    level
  }, race_ {
    race
  },
  attribute_ {
    attribute
  }, atk_ {
    atk
  }, def_ {
    def
  } {}

//Accessor functions

//@return:  the name of the card
std::string YGOCard::getName() const {
  return name_;
}

//@return:  the type of card (effect, syncro, XYZ, ritual ect) 
std::string YGOCard::getType() const {
  return type_;
}

//@return:  the Level/Rank of the card (1-12) generally
int YGOCard::getLevel() const {
  return level_rank_;
}

//@return:  the race of the monster on the card (spellcaster, machine, fiend)
std::string YGOCard::getRace() const {
  return race_;
}

//@return:     the attribute of card (Earth, Wind, Fire, Do you remember, The 21st Night of September)
std::string YGOCard::getAttribute() const {
  return attribute_;
}

//@return:  the attack value of the card
int YGOCard::getAtk() const {
  return atk_;
}

//@return:    the defense value of the card           
int YGOCard::getDef() const {
  return def_;
}

//Mutator Functions

//@param: sets the name of the card to the value of the argument
void YGOCard::setName(std::string name) {
  name_ = name;
}

//@param: sets the type of the card to the value of the argument
void YGOCard::setType(std::string type) {
  type_ = type;
}

//@param: sets the rank of the card to the value of the argument
void YGOCard::setRank(int rank) {
  level_rank_ = rank;
}

//@param: sets the race of the card to the value of the argument
void YGOCard::setRace(std::string race) {
  race_ = race;
}

//@param: sets the attribute of the card to the value of the argument
void YGOCard::setAttribute(std::string attribute) {
  attribute_ = attribute;
}

//@param: sets the attack of the card to the value of the argument
void YGOCard::setAtk(int atk) {
  atk_ = atk;
}

//@param: sets the defense of the card to the value of the argument
void YGOCard::setDef(int def) {
  def_ = def;
}

//@post:  displays all card data member values to the standard output
void YGOCard::display() {
  std::cout << std::setw(50) << std::left << getName() << std::setw(5) << " Atk: " << std::setw(5) << getAtk() << std::setw(5) << "     Def: " << std::setw(5) << getDef() << std::endl;
}

//@post:  displays the name of the card to the standard output
void YGOCard::displayName() {
  std::cout << name_;
}

//@return:  true if all data members of rhs are equal to the card's data members, false otherwise
bool YGOCard::operator == (const YGOCard & rhs) const {
  bool nameEq = rhs.getName() == name_;
  bool typeEq = rhs.getType() == type_;
  bool rankEq = rhs.getLevel() == level_rank_;
  bool raceEq = rhs.getRace() == race_;
  bool attributeEq = rhs.getAttribute() == attribute_;
  bool atkEQ = rhs.getAtk() == atk_;
  bool defEQ = rhs.getDef() == def_;
  bool result = nameEq && typeEq && rankEq && raceEq && attributeEq && atkEQ && defEQ;
  return result;
}

//@return:  true if at least one data member of rhs is not equal to the card's data members, false otherwise
bool YGOCard::operator != (const YGOCard & rhs) const {
  bool nameEq = rhs.getName() != name_;
  bool typeEq = rhs.getType() != type_;
  bool rankEq = rhs.getLevel() != level_rank_;
  bool raceEq = rhs.getRace() != race_;
  bool attributeEq = rhs.getAttribute() == attribute_;
  bool atkEQ = rhs.getAtk() != atk_;
  bool defEQ = rhs.getDef() != def_;
  bool result = nameEq || typeEq || rankEq || raceEq || attributeEq || atkEQ || defEQ;
  return result;
}