/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 7
*/

#ifndef EMPLOYEE_
#define EMPLOYEE_

#include<string>

class Employee {
  public: Employee(std::string name, int id);
  std::string getName() const;
  int getId() const;

  //All comparison operators compare Employee IDs
  bool operator == (const Employee & rhs) const;
  bool operator > (const Employee & rhs);
  bool operator < (const Employee & rhs);

  private: std::string name_;
  int id_;
};

#endif