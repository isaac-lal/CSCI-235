/*
Sheridan Siguencia
Sheridan.siguencia98@myhunter.cuny.edu
2/21/23

*/

#include "Textbook.hpp"



/**
  Default constructor.
  Default-initializes all private members.
*/
    Textbook::Textbook() :Book() {}


/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The subject of the book (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : The grade level of the book (of type grade_level)
                with DEFAULT VALUE NONE
  @param     : A boolean to indicate whether the book has review
                questions with DEFAULT VALUE False
  @post      : The private members are set to the values of the
                corresponding parameters.
*/          

    Textbook::Textbook(std::string title, std::string author, int page_count, std::string subject, bool is_digital, grade_level grade_lvl, bool has_review_q): 
            Book(title, author, page_count, is_digital), subject_{subject}, grade_lvl_{grade_lvl}, has_review_q_{has_review_q}{}


/**
  @param  : a reference to a string representing the the subject of the book
  @post   : sets the private member variable to the value of the parameter
**/
    void Textbook::setSubject(const std::string &subject)
    {
        subject_ = subject;
    }



/**
  @return  : the subject of the textbook
**/
    std::string Textbook::getSubject() const
    {
        return subject_;
    }


/**
  @param  : a reference to a grade_level
  @post   : sets the private member variable to the value of the parameter
**/
    void Textbook::setGradeLevel(const grade_level &grade_lvl)
    {
        grade_lvl_ = grade_lvl;
    }


/**
  @return  : a string representative of the grade_level
            (e.g. if the grade level is JUNIOR_HIGH,
            it returns "JUNIOR HIGH")
**/
    std::string Textbook::getGradeLevel() const
    {
        switch (grade_lvl_) 
        {
            case 0:
                return"NONE";
            case 1:
                return"ELEMENTARY";
            case 2:
                return "JUNIOR HIGH";
            case 3:
                return "HIGH SCHOOL";
            case 4:
                return "COLLEGE";
        }
        
        return "Error";
    }


/**
  @post   : sets the review question flag to True
**/
    void Textbook::setReviewQuestions()
    {
        has_review_q_ = true;
    }


/**
  @return  : the flag indicating if the texbook has review questions
**/
    bool Textbook::checkReviewQuestions() const
    {
        return has_review_q_;
    }