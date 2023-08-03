<h1>Project 2: Inheritance!</h1>

<div style="width:800px; height:350px; display: block;
margin-left: auto;
margin-right: auto;">

![books](./book.jpg)

</div>



Inheritance is a key feature in OOP that allows us to create a new class that can be derived from an existing base class. The derived (or child) class will inherit members from the base class while adding new members to make it more specialized.  

For Project 2 you will need to build on Project 1 to work with ***inheritance*** and ***separate compilation***: after completion of this project you should be comfortable compiling multiple classes
into one program, understand #includes and work with basic inheritance.
**Note:** You must have completed and understood project 1 completely before moving onto this project. If you need assistance please seek help immediately (contact the instructor or visit the labs to work with our UTAs).

**You will need to write 3 classes that derive from our ```Book``` class but also have additional attributes and methods specific to their type:**
* The ```Manual``` class. Instruction manuals are those oversized books you get with an elecronic instrument or some house appliance. Each ```Manual``` has a device that it belongs to, an **optional** website associated with it, and **optional** visual aids (for example, assembly instructions).
* The ```Textbook``` class. Every ```Textbook``` has a subject (e.g., math, computer science, politics, etc.) and a "grade level" difficulty to determine what type of students the textbook is meant for (college or high school). Textbooks may or may not have practice review questions in them.
* The ```Novel``` class. What we mostly think of when we think of books. Fictional novels come in all sorts of genres (horror, mystery, etc.) and they include a cast of characters. Novels may have film adaptations. Each ```Novel``` also has a list of reviews. Each review has a score that is used to calculate the average score of the novel.



***The link to accept the GitHub Classroom assignment can be found on Blackboard***

---

### Some additional resources on Inheritance, Regular Expressions and Enums

-   [Code Beauty on inheritance programming](https://youtu.be/-W-TYjL0aFE)
-   [Caleb Curry on base and subclass inheritance](https://youtu.be/_rzEUwv2-eQ)
-   [Regular Expression in C++](https://cplusplus.com/reference/regex/)
-   [Validating Regex as a link](https://stackoverflow.com/questions/5620235/cpp-regular-expression-to-validate-url)
-   [enums](https://www.geeksforgeeks.org/enumerated-types-or-enums-in-c/)

---


## Implementation
***You  must  write  the  3  Book-subclasses: `Manual`, `Texbook` and `Novel`.***  
  **Work incrementally!** Work through the tasks sequentially (implement and TEST). Only move on to a task when you are positive that the previous one has been completed correctly. Remember that the **function names, returns, parameters, pre and post conditions must be exactly as specified in this project specification**. This is a contract, it gives you all the information necessary to complete this assignment correctly. If you don't understand this project specification and its requirements, ask for clarification before you proceed. Remember that accessor functions (e.g. getID()) are used to access the private data members (e.g. all getID() will do is return id_). As  you  implement  these  classes  think  about  what  is  inherited  and  what  is  not  (e.g. constructors are not inherited!!!). Also think about the order in which constructors are called,   and   how/where   must   you   explicitly   call   the   base   class   constructor.  
**Remember to make parameters read-only when appropriate.  
 You must thoroughly document your code!!!**


---


---
## **Task 1: The `Manual` class**
---
Define and implement the `Manual` class.


The `Manual` class **must** have the following _private member variables_:

```
  - a string that represents a url
  - a string that represents the name of the device
  - a boolean indicating whether the Manual has a visual aid
  - a boolean indicating whether the Manual has a website
```
### Constructors

```
/**
  Default constructor.
  Default-initializes all private members.
*/


/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : The name of the device (a string)
  @param     : The URL that is in the format
                'https://www.something.something'
                or 'http://www.something.something'
                with the last 'something' being at least 2 characters
                with DEFAULT VALUE empty string (a string)
  @param     : A Boolean indicating the presence of a visual aid
                with DEFAULT VALUE False
  @post      : The private members are set to the values of the
                corresponding parameters.
                If a URL is provided, the website flag is set to True.
                If the URL is ill-formatted, the website is set to
                empty string and the website flag is set to False.
*/
```

### Unique methods

```
/**
  @param  : a reference to a string representing the device
  @post   : sets the private member variable to the value of the parameter
**/
setDevice


/**
  @return  : the variable indicating the device the manual is for
**/
getDevice


/**
  @param   : a reference to a website link (string) that is in the format
             'https://www.something.something'
             or 'http://www.something.something'
             with the last 'something' being at least 2 characters
  @return  : has_website_ flag (a boolean)
  @post    : If the link is not correctly formatted,
             store "Broken Link" in the link member variable (see <regex>)
             and either way set the has website flag to True
**/
setWebsite


/**
  @return  : the url for the website
**/
getWebsite


/**
  @param  : a boolean
  @post   : sets the private member variable indicating the presence
            of a visual aid to the value of the parameter
**/
setVisualAid()


/**
  @return  : the visual aid flag
**/
hasVisualAid()


/**
  @return  : the has website flag
**/
 hasWebsite
```

---
## **Task 2: The `Textbook` class**
---
Define and implement the `Textbook` class.

### Data and Types


The `Textbook` class **must** define the following  _type_ (defined within it's interface but not part of the class):

```
   - An enum named `grade_level`
     with values `{NONE,  ELEMENTARY, JUNIOR_HIGH, HIGH_SCHOOL, COLLEGE}`
     in that order.
```

The `Textbook` class **must** have the following _private member variables_:

```
   - a string the represents the subject of the book
   - variable of type grade_level that represents the grade level of the book
   - a boolean that indicates whether the book has review questions or not
```



The `Textbook` class **must** have the following _public member functions_:

### Constructors

```
/**
  Default constructor.
  Default-initializes all private members.
*/


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
```
### Unique methods

```

/**
  @param  : a reference to a string representing the the subject of the book
  @post   : sets the private member variable to the value of the parameter
**/
setSubject


/**
  @return  : the subject of the textbook
**/
getSubject


/**
  @param  : a reference to a grade_level
  @post   : sets the private member variable to the value of the parameter
**/
setGradeLevel


/**
  @return  : a string representative of the grade_level
            (e.g. if the grade level is JUNIOR_HIGH,
            it returns "JUNIOR HIGH")
**/
getGradeLevel


/**
  @post   : sets the review question flag to True
**/
setReviewQuestions


/**
  @return  : the flag indicating if the texbook has review questions
**/
checkReviewQuestions

```

---
## **Task 3: The `Novel` class**
---
Define and implement the `Novel` class.

### Data and Types


The `Novel` class **must** define the following  _type_ (defined within it's interface but not part of the class):

```
struct review {
    double score_;
    std::string rating_;
};
```

The `Novel` class **must** have the following _private member variables_:

```
  - a string indicating the genre of the novel
  - a vector of strings storing the characters
    in the novel (a character list)
  - a vector of reviews (type review defined in the above struct)
    storing the reviews for this novel
  - a floating point number (double) storing the average rating
  - a boolean indicating whether a film adaptation for this
    novel exists
```

The `Novel` class **must** have the following _public member functions_:

### Constructors

```
/**
  Default constructor.
  Default-initializes all private members.
*/


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
```

### Unique methods

```
/**
  @return   : the value of the genre private member
**/
getGenre


/**
  @param  : a string indicating the genre of the book
  @post   : sets sets genre_ private member to the
              value of the parameter
**/
setGenre


/**
  @return   : the vector containing the list of characters for this novel
**/
getCharacterList


/**
  @return    : a string of all the characters in the
              character_list_ private member, concatenated
              and separated by a space " " .
              For example: "character1 character2 character3"
**/
getCharacterListString


/**
  @param  : a string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
addCharacter


/**
  @return   : the value of the film_adaptation private member
**/
hasFilmAdaptation



/**
  @post   : sets has_film_adaptation_ private member to true
**/
setFilmAdaptation


/**
  @return   : the value of the average rating private member
**/
getAverageRating



/**
  @param    : a floating point number (double) indicating
              the score of the  review
  @param    : a string indicating the rating of the review
  @return   : creates and returns a review data type with
              score and rating as indicated by the parameters
*/
createReview


/**
  @param  : a review object
  @post   : inserts the review argument into the reviews_ vector
**/
addReview


/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/  
calculateAverageRating


```
***Note***: This class uses a **struct** type. Struct is just short for "structure" and it is a user-defined type, much like a class. It is not a full fledge class, however. We use it to bundle data items with no or very few functions (non in this case). When initializing a new review you may use ```review``` as the data type. For example for ```int x```, ```int``` is our primitive data type. If we want to make a review called x we would write ```review x```.
* More on structs here: https://www.educative.io/edpresso/what-is-a-cpp-struct
***
***

### Testing
How to compile:
```
make rebuild
```
You must always implement and test you programs **INCREMENTALLY!!!**
What does this mean? Implement and test one method at a time.
* Implement one function/method and test it thoroughly (multiple test cases + edge cases if applicable).
* Implement the next function/method and test in the same fashion.
    **How do you do this?** Write your own `main()` function to test your class. In this course you will never submit your test program, but you must always write one to test your classes. Choose the order in which you implement your methods so that you can test incrementally: i.e. implement mutator functions before accessor functions. Sometimes functions depend on one another. If you need to use a function you have not yet implemented, you can use stubs: a dummy implementation that always returns a single value for testing. Don’t forget to go back and implement the stub!!! If you put the word STUB in a comment, some editors will make it more visible.

---
### Grading Rubric

**Correctness 80%** (distributed across unit testing of your submission)  
**Documentation 15%**  
**Style and Design 5%** (proper naming, modularity, and organization)

---

**Important:** You must start working on the projects as soon as they are assigned to detect any problems with submitting your code and to address them with us **well before** the deadline so that we have time to get back to you **before** the deadline.   

#### There will be no negotiation about project grades after the submission deadline. #####

---
### Submission:  

**We will grade the following** :  

`Manual.hpp`, 
`Manual.cpp`, 
`Textbook.hpp`, 
`Textbook.cpp`, 
`Novel.hpp`, 
`Novel.cpp`

Your project must be submitted to Gradescope through GitHub Classroom. Although Gradescope allows multiple submissions, it is not a platform for testing and/or debugging and it should not be used for that. You **MUST** test and debug your program locally. Before submitting to Gradescope you **MUST** ensure that your program compiles (with g++) and runs correctly on the Linux machines in the labs at Hunter (see detailed instructions on how to upload, compile and run your files in the “Programming Rules” document). That is your baseline, if it runs correctly there it will run correctly on Gradescope, and if it does not, you will have the necessary feedback (compiler error messages, debugger or program output) to guide you in debugging, which you don’t have through Gradescope. “But it ran on my machine!” is not a valid argument for a submission that does not compile. Once you have done all the above you submit it to Gradescope.  
**Gradescope will only accept 5 submissions per day.**
