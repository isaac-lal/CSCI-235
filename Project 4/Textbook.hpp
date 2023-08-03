/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#ifndef TEXTBOOK_HPP_
#define TEXTBOOK_HPP_

#include "Book.hpp"

// An enum named `grade_level`
// with values `{NONE,  ELEMENTARY, JUNIOR_HIGH, HIGH_SCHOOL, COLLEGE}` in that order.
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
    @param     : A flag indicating whether the book is in digital form 
                with DEFAULT VALUE False (a Boolean)
    @param     : The subject of the book (a string)
    @param     : The grade level of the book (of type grade_level) 
                with DEFAULT VALUE NONE
    @param     : A boolean to indicate whether the book has review 
                questions with DEFAULT VALUE False
    @post      : The private members are set to the values of the 
                corresponding parameters.
  */
  Textbook(std::string name, std::string author, int page_count, std::string subject, bool is_digital = false, grade_level grade = NONE, bool has_review = false);

  /**
    @return  : the subject of the textbook
  **/
  std::string getSubject() const; //return subject_

  /**
    @return  : a string representative of the grade_level 
            (e.g. if the grade level is JUNIOR_HIGH, 
            it returns "JUNIOR HIGH")
  **/
  std::string getGradeLevel() const;

  /**
    @return  : the flag indicating if the texbook has review questions
  **/
  bool checkReviewQuestions() const; //return has_review_questions_

  /**
    @param  : a reference to a string representing the the subject of the book
    @post   : sets the private member variable to the value of the parameter
  **/
  void setSubject(const std::string & subject);

  /**
    @param  : a reference to a grade_level
    @post   : sets the private member variable to the value of the parameter
  **/
  void setGradeLevel(const grade_level & level);

  /**
    @post   : sets the review question flag to True
  **/
  void setReviewQuestions(); //set has_review_questions_ to true
  /**
    @post     : displays Textbook data in the form:
    "[title_] is written by [author_] for [grade_level_] students. Subject: [subject_]. [It has/ It does not have] review questions. Page Count: [page_count_]. [It is / It is not] available digitally.\n" 
    */
  void display();
  //Example:
  //Calculus: Early Transcendentals written by James Stewart for COLLEGE students. Subject: mathematics. It has review questions. Page Count: 867. It is available digitally.

  /**
    @param    : a reference to a string key to match the subject of the Textbook
    @post     : calls display() if the key argument is equal to subject_ (e.g. "mathematics")   
    */
  void displayFilter(std::string & key);

  private: std::string subject_; // a string the represents the subject of the book
  int grade_level_; // variable of type grade_level that represents the grade level of the book
  bool has_review_questions_; // a boolean that indicates whether the book has review questions or not

};

#endif