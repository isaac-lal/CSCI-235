#include "Manual.hpp"

/**
  @param  : a const to a string representing a url
  @post   : test to see if the url is in the right format
  @return : true if right format, false if wrong format
**/
bool checkFormat(const std::string & url) {
  //this is to check the ending of the url to be greater than 2
  std::string str = url.substr(url.find_last_of('.'));

  int count = 0; //count represents the number of periods in the url

  // this is the loop counting the number of time '.' appears in the url since in every working wbesite url there are only two '.'
  for (int i = 0; i = url.find('.', i) != std::string::npos; i++) count++;

  if (count != 2 || str.size() < 2 || (url.substr(0, 11) != "http://www." && url.substr(0, 12) != "https://www.")) return false;

  //if all is good in the hood return true
  return true;
}

/**
  Default constructor.
  Default-initializes all private members.
*/
Manual::Manual(): Book() {}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The name of the device (a string)
  @param     : A flag indicating whether the book is in digital form with DEFAULT VALUE False (a Boolean)
  @param     : The URL that is in the format 'https://www.something.something' or 'http://www.something.something' with the last 'something' being at least 2 characters with DEFAULT VALUE empty string (a string)
  @param     : A Boolean indicating the presence of a visual aid with DEFAULT VALUE False
  @post      : The private members are set to the values of the corresponding parameters. If a URL is provided, the website flag is set to True. If the URL is ill-formatted, the website is set to empty string and the website flag is set to False.
*/
Manual::Manual(std::string title, std::string author, int page_count, std::string device_name, bool is_digital, std::string url, bool has_visual_aid):
  Book(title, author, page_count, is_digital), device_name_ {
    device_name
  }, has_visual_aid_ {
    has_visual_aid
  } {
    if (!checkFormat(url)) {
      url_ = "";
      is_website_ = false;
    } else {
      url_ = url;
      is_website_ = true;
    }
  }

/**
  @param  : a reference to a string representing the device
  @post   : sets the private member variable to the value of the parameter
**/
void Manual::setDevice(const std::string & device_name) {
  device_name_ = device_name;
}

/**
  @return  : the variable indicating the device the manual is for
**/
std::string Manual::getDevice() const {
  return device_name_;
}

/**
  @param   : a reference to a website link (string) that is in the format 'https://www.something.something' or 'http://www.something.something' with the last 'something' being at least 2 characters
  @return  : has_website_ flag (a boolean)
  @post    : If the link is not correctly formatted, store "Broken Link" in the link member variable (see <regex>) and either way set the has website flag to True
**/
bool Manual::setWebsite(const std::string & url) {
  //check formating
  if (!checkFormat(url))
    url_ = "Broken Link";
  else
    url_ = url;

  is_website_ = true; //true reguardless

  return is_website_;
}

/**
  @return  : the url for the website
**/
std::string Manual::getWebsite() {
  return url_;
}

/**
  @param  : a boolean
  @post   : sets the private member variable indicating the presence of a visual aid to the value of the parameter
**/
void Manual::setVisualAid(const bool & has_visual_aid) {
  has_visual_aid_ = has_visual_aid;
}

/**
  @return  : the visual aid flag
**/
bool Manual::hasVisualAid() const {
  return has_visual_aid_;
}

/**
 @return  : the has website flag
**/
bool Manual::hasWebsite() const {
  return is_website_;
}