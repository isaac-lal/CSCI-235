/*
Name: Isaac Lal
Email: isaac.lal46@myhunter.cuny.edu
Professor: Tiziana Ligorio
Date: February 21, 2023
*/

#ifndef TEXTBOOK_HPP_
#define TEXTBOOK_HPP_

#include "Book.hpp"
#include <iostream>
#include <string>

// An enum named `grade_level` with values `{NONE,  ELEMENTARY, JUNIOR_HIGH, HIGH_SCHOOL, COLLEGE}` in that order.
enum grade_level {
  NONE,
  ELEMENTARY,
  JUNIOR_HIGH,
  HIGH_SCHOOL,
  COLLEGE
};

class Textbook: public Book {
  public:
    /**
      Default constructor.
      Default-initializes all private members.
    */
    Textbook();

    /**
      Parameterized constructor.
      @param     : The title of the book (a string)
      @param     : The author of the book (a string)
      @param     : The number of pages in the book (a positive integer)
      @param     : The subject of the book (a string)
      @param     : A flag indicating whether the book is in digital form with DEFAULT VALUE False (a Boolean)
      @param     : The grade level of the book (of type grade_level) with DEFAULT VALUE NONE
      @param     : A boolean to indicate whether the book has review questions with DEFAULT VALUE False
      @post      : The private members are set to the values of the corresponding parameters.
    */
    Textbook(std::string title, std::string author, int page_count, std::string subject, bool is_digital = false, grade_level grade_lvl = NONE, bool has_review_q = false);

    /**
      @param  : a reference to a string representing the the subject of the book
      @post   : sets the private member variable to the value of the parameter
    **/
    void setSubject(const std::string &subject);

    /**
      @return  : the subject of the textbook
    **/
    std::string getSubject() const;

    /**
      @param  : a reference to a grade_level
      @post   : sets the private member variable to the value of the parameter
    **/
    void setGradeLevel(const grade_level &grade_lvl);

    /**
      @return  : a string representative of the grade_level (e.g. if the grade level is JUNIOR_HIGH, it returns "JUNIOR HIGH")
    **/
    std::string getGradeLevel() const;

    /**
      @post   : sets the review question flag to True
    **/
    void setReviewQuestions();

    /**
      @return  : the flag indicating if the texbook has review questions
    **/
    bool checkReviewQuestions() const;

  private: 
    std::string subject_; // a string the represents the subject of the book
    grade_level grade_lvl_; //variable of type grade_level that represents the grade level of the book
    bool has_review_q_; //a boolean that indicates whether the book has review questions or not
};

#endif //ends TEXTBOOK_HPP_