/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 4
*/

#include "Novel.hpp"


/**
  Default constructor.
  Default-initializes all private members. 
  Booleans are default-initialized to False
*/
Novel::Novel(): genre_ {
  ""
}, average_rating_ {
  0.0
}, has_film_adaptation_ {
  false
} {}

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
Novel::Novel(std::string name, std::string author, int page_count, std::string genre, bool is_digital, bool has_adaptation):
  Book(name, author, page_count, is_digital),
  genre_ {
    genre
  }, average_rating_ {
    0.0
  }, has_film_adaptation_ {
    has_adaptation
  } {}

/**
  @return   : the value of the genre private member
**/
std::string Novel::getGenre() const {
  return genre_;
}

/**
  @param  : a string indicating the genre of the book
  @post   : sets sets genre_ private member to the 
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
  std::string characters = "";
  for (int i = 0; i < character_list_.size(); i++) {
    characters += character_list_[i];
    characters += " ";
  }

  // remove extra space at end
  return characters.substr(0, characters.size() - 1);
}

/**
  @param  : a string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
void Novel::addCharacter(const std::string & character) {
  character_list_.push_back(character);
}

/**
  @return   : the value of the film_adaptation private member
**/
bool Novel::hasFilmAdaptation() const {
  return has_film_adaptation_;
}

/**
  @post   : sets has_film_adaptation_ private member to true
**/
void Novel::setFilmAdaptation() {
  has_film_adaptation_ = true;
}

/**
  @return   : the value of the average rating private member
**/
double Novel::getAverageRating() const {
  return average_rating_;
}

/**
  @param    : a floating point number (double) indicating 
              the score of the  review
  @param    : a string indicating the rating of the review
  @return   : creates and returns a review data type with 
              score and rating as indicated by the parameters
*/
review Novel::createReview(const double & score,
  const std::string & rating) {
  review my_review;
  my_review.score_ = score;
  my_review.rating_ = rating;
  return my_review;
}

/**
  @param  : a review object
  @post   : inserts the review argument into the reviews_ vector
**/
void Novel::addReview(const review & my_review) {
  reviews_.push_back(my_review);
}

/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/
void Novel::calculateAverageRating() {
  double runningTotal = 0.0;
  for (int i = 0; i < reviews_.size(); i++) {
    runningTotal += reviews_[i].score_;
  }
  average_rating_ = runningTotal / reviews_.size();
}

/**
  @post     : displays Novel data in the form:
  "[title_] is written by [author_]. Genre: [genre_]. [It has/ It does not have] a film adaptation. Page Count: [page_count_]. [It is / It is not] available digitally.\n"     
*/
void Novel::display() {
  std::string digital, film_adapt = "It is";
  if (!(isDigital())) {
    digital = "It is not";
  }

  if (!(has_film_adaptation_)) {
    film_adapt = "It is not";
  }
  std::cout << getTitle() << " is written by " << getAuthor() << "Genre: " << getGenre() << ".  " << film_adapt << " a film adaptation. Page Count: " << getPageCount() << ". " << digital << " available digitally.\n";
}

//Example:
//Enders Game is written by Orson Scott Card. Genre: science fiction. It has a film adaptation. Page Count: 324. It is not available digitally. 

/**
  @param    : a reference to a string key to match the genre of the Novel
  @post     : calls display() if the key argument is equal to genre_ (e.g. "horror")   
*/
void Novel::displayFilter(std::string & key) {
  if (genre_ == key)
    display();
}