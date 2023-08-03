/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#ifndef NOVEL_HPP_
#define NOVEL_HPP_

#include "Book.hpp"

#include <vector>

struct review {
  double score_;
  std::string rating_;
};

class Novel: public Book {
  public:
    /**
    Default constructor.
    Default-initializes all private members. 
    */
    Novel();

  /**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : A flag indicating whether the book is in digital form 
                with DEFAULT VALUE False (a Boolean)
  @param     : The genre of the novel (a string)
  @param     : A flag indicating whether there is a film adaptation 
                for this novel with DEFAULT VALUE False (a Boolean)
  */
  Novel(std::string name, std::string author, int page_count, std::string genre, bool is_digital = false, bool has_adaptation = false);

  /**
  @return   : the value of the genre private member
  **/
  std::string getGenre() const;

  /**
    @param  : a string indicating the genre of the book
    @post   : sets sets genre_ private member to the 
              value of the parameter
    **/
  void setGenre(const std::string & genre);

  /**
  @return   : the vector containing the list of characters for this novel
  **/
  std::vector < std::string > getCharacterList() const;

  /**
  @return    : a string of all the characters in the 
                character_list_ private member, concatenated 
                and separated by a space " " .
                For example: "character1 character2 character3"
  **/
  std::string getCharacterListString();

  /**
  @param  : a string indicating a character
  @post   : inserts the character into the character_list_ vector
  **/
  void addCharacter(const std::string & character);

  /**
  @return   : the value of the film_adaptation private member
  **/
  bool hasFilmAdaptation() const;

  /**
  @post   : sets has_film_adaptation_ private member to true
  **/
  void setFilmAdaptation();

  /**
  @return   : the value of the average rating private member
  **/
  double getAverageRating() const;

  /**
  @param    : a floating point number (double) indicating 
              the score of the  review
  @param    : a string indicating the rating of the review
  @return   : creates and returns a review data type with 
              score and rating as indicated by the parameters
  */
  review createReview(const double & score,
    const std::string & rating);

  /**
  @param  : a review object
  @post   : inserts the review argument into the reviews_ vector
  **/
  void addReview(const review & my_review);

  /**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
  **/
  void calculateAverageRating();

  /**
    @post     : displays Novel data in the form:
    "[title_] is written by [author_]. Genre: [genre_]. [It has/ It does not have] a film adaptation. Page Count: [page_count_]. [It is / It is not] available digitally.\n"     
    */
  void display();

  //Example:
  //Enders Game is written by Orson Scott Card. Genre: science fiction. It has a film adaptation. Page Count: 324. It is not available digitally. 

  /**
    @param    : a reference to a string key to match the genre of the Novel
    @post     : calls display() if the key argument is equal to genre_ (e.g. "horror")   
    */
  void displayFilter(std::string & key);

  private: std::string genre_; // a string indicating the genre of the novel
  std::vector < std::string > character_list_; // a vector of strings storing the characters in the novel (a character list)
  std::vector < review > reviews_; // a vector of reviews (type review defined in the above struct) storing the reviews for this novel
  double average_rating_; // a floating point number (double) storing the average rating
  bool has_film_adaptation_; // a boolean indicating whether a film adaptation for this novel exists
};

#endif