#include "Book.hpp"
#include "Manual.hpp"
#include "Textbook.hpp"
#include "Novel.hpp"
#include <iostream>

int main()
{
    std::cout << "TEST 1: TEST DEFAULT CONSTRUCTOR & ACCESSORS" << std::endl;

    // Test default constructor
    Novel my_book; 

    // Test accessor functions
    std::cout << my_book.getTitle() << std::endl;
    std::cout << my_book.getAuthor() << std::endl;
    std::cout << my_book.getPageCount() << std::endl;
    std::cout << my_book.isDigital() << std::endl;
    std::cout <<"no" << my_book.getGenre() << std::endl;
    std::cout << "nothing" <<my_book.getCharacterListString() << std::endl;
    std::cout << "film: " << my_book.hasFilmAdaptation() << std::endl;
    std::cout << my_book.getAverageRating() << std::endl;

    std::cout << "\nTEST 2: TEST PARAMETERIZED CONSTRUCTOR & ACCESSORS" << std::endl;

    // Test parameterized constructor
    Novel my_book1("Harry Potter and the Chamber of Secrets", "J.K Rowling", 253, "Fantasy", 1,1);
    Novel my_book2("Moby Dick", "Herman Melville", 378, "Realistic fiction");
    
    // Test accessor functions
    std::cout << my_book1.getTitle() << " By " << my_book1.getAuthor() 
        << " with page count " << my_book1.getPageCount() << std::endl;
    std::cout << "Digital: " << my_book1.isDigital() << std::endl;

    //1 novel
    std::cout <<"Genere: " << my_book1.getGenre() << std::endl;
    std::cout << "Character list: " <<my_book1.getCharacterListString() << std::endl;
    std::cout << "film: " << my_book1.hasFilmAdaptation() << std::endl;
    std::cout << "Average rating: " << my_book1.getAverageRating() << std::endl << std::endl;

//book 2
    std::cout << my_book2.getTitle() << " By " << my_book2.getAuthor() 
        << " with page count " << my_book2.getPageCount() << std::endl;
    std::cout << "Digital: " << my_book2.isDigital() << std::endl;

    //2 Novel
    std::cout <<"Genere: " << my_book2.getGenre() << std::endl;
    std::cout << "Character list: " <<my_book2.getCharacterListString() << std::endl;
    std::cout << "film: " << my_book2.hasFilmAdaptation() << std::endl;
    std::cout << "Average rating: " << my_book2.getAverageRating() << std::endl;
    
    std::cout << "\nTEST 3: TEST MUTATOR FUNCTIONS" << std::endl;

    // Test mutator functions
    Novel my_book3("Moby Dick", "Herman Melville", 378, "Realistic Fiction", 0);
    my_book3.setTitle("50 shades of gray");
    my_book3.setAuthor("E. L. James");
    my_book3.setPageCount(514);
    my_book3.setPageCount(-10);
    my_book3.setDigital();
    my_book3.setFilmAdaptation();
    my_book3.setGenre("Uninteresting");
    my_book3.addReview(my_book3.createReview(75,"C"));
    my_book3.addReview(my_book3.createReview(90,"A"));
    my_book3.addReview(my_book3.createReview(83,"B"));
    my_book3.addCharacter("Nicole");
    my_book3.addCharacter("Jackman");
    my_book3.calculateAverageRating();
    

    // Test accessor functions
    std::cout << my_book3.getTitle() << " By " << my_book3.getAuthor() 
        << " with page count " << my_book3.getPageCount() << std::endl;
    std::cout << "Digital: " << my_book3.isDigital() << std::endl;
    //3 novel

    std::cout <<"Genere: " << my_book3.getGenre() << std::endl;
    std::cout << "Character list: " <<my_book3.getCharacterListString() << std::endl;
    std::cout << "film: " << my_book3.hasFilmAdaptation() << std::endl;
    std::cout << "Average rating: " << my_book3.getAverageRating() << std::endl;

    my_book3.addReview(my_book3.createReview(95,"A+"));
    my_book3.calculateAverageRating();

    std::cout << "Average rating after pablo rates it: " << my_book3.getAverageRating() << std::endl;




    return 0;
}