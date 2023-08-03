#include "Novel.hpp"


/**
  Default constructor.
  Default-initializes all private members.
*/
Novel::Novel(): Book() {};

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The genre of the novel (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : A flag indicating whether there is a film adaptation
                for this novel with DEFAULT VALUE False (a Boolean)
*/
Novel::Novel(std::string title, std::string author, int page_count, std::string genre, bool is_digital, bool has_film):
  Book(title, author, page_count, is_digital), genre_ {
    genre
  }, has_film_ {
    has_film
  } {}

/**
  @return   : the value of the genre private member
**/
std::string Novel::getGenre() const {
  return genre_;
}

/**
  @param  : a reference to string indicating the genre of the book
  @post   : sets genre_ private member to the
              value of the parameter
**/
void Novel::setGenre(const std::string & genre) {
  genre_ = genre;
}

/**
  @return   : the vector containing the list of characters for this novel
**/
std::vector < std::string > Novel::getCharacterList() const {
  return character_list_;
}

/**
  @return    : a string of all the characters in the
              character_list_ private member, concatenated
              and separated by a space " " .
              For example: "character1 character2 character3"
**/
std::string Novel::getCharacterListString() {
  std::string str = "";
  if (character_list_.size() > 0)
    for (int i = 0; i < character_list_.size(); i++)
      str += character_list_[i] + " ";

  return str;
}

/**
  @param  : a reference to string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
void Novel::addCharacter(const std::string & character) {
  character_list_.push_back(character);
}

/**
  @return   : the value of the film_adaptation_ private member
**/
bool Novel::hasFilmAdaptation() const {
  return has_film_;
}

/**
  @post   : sets has_film_adaptation_ private member to true
**/
void Novel::setFilmAdaptation() {
  has_film_ = true;
}

/**
  @param    : a reference to floating point number (double) indicating
              the score of the  review
  @param    : a reference to string indicating the rating of the review
  @return   : creates and returns a review data type with
              score and rating as indicated by the parameters
*/

review Novel::createReview(const double & score,
  const std::string & rating) {
  struct review rev;
  rev.rating_ = rating;
  rev.score_ = score;

  return rev;
}

/**
  @param  : a reference to review object
  @post   : inserts the review argument into the reviews_ vector
**/
void Novel::addReview(const review & r) {
  reviews_.push_back(r);
}

/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/
void Novel::calculateAverageRating() {
  average_rating_ = 0;

  for (int i = 0; i < reviews_.size(); i++)
    average_rating_ += reviews_[i].score_;

  average_rating_ = average_rating_ / reviews_.size();

}
/**
  @return   : the value of the average rating private member
**/
double Novel::getAverageRating() const {
  return average_rating_;
}