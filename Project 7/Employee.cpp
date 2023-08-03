/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 7
*/

#include "Employee.hpp"

Employee::Employee(std::string name, int id) {
  name_ = name;
  id_ = id;
}

std::string Employee::getName() const {
  return name_;
}
int Employee::getId() const {
  return id_;
}

//All comparison operators compare Employee IDs
bool Employee::operator == (const Employee & rhs) const {
  if (getId() == rhs.getId() && getName() == rhs.getName()) {
    return true;
  }

  return false;
}

bool Employee::operator > (const Employee & rhs) {
  if (getId() > rhs.getId()) {
    return true;
  }

  return false;
}
bool Employee::operator < (const Employee & rhs) {
  if (getId() < rhs.getId()) {
    return true;
  }

  return false;
}