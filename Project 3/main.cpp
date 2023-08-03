/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 3
*/

#include "LibraryRecord.hpp"
#include "Book.hpp"
#include <iostream>
#include <vector>
#include <string>


int main()
{
    Book book_1("The Catcher in the Rye","J.D. Salinger",234, 1);
    Book book_2("Harry Potter and the Chamber of Secrets", "J.K Rowling", 253, 1);
    Book book_5("Some Book", "Don't worry about it", 1000);
    
    LibraryRecord first_record;
    LibraryRecord second_record;
    first_record.checkIn(book_1);
    first_record.checkIn(book_2);

    second_record.checkIn(book_1);
    second_record.checkIn(book_2);
    second_record.checkIn(book_5);

    //first_record.checkOut(book_1);
    /*
    second_record.checkOut(book_1);//1
    second_record.checkIn(book_1);
    second_record.checkOut(book_1);//2
    second_record.checkIn(book_1);
    
    second_record.checkOut(book_1);//3
    second_record.checkIn(book_1);
    second_record.checkOut(book_1);//4
    second_record.checkIn(book_1);
    if(!(add(lr.items_[i])))
            return;
    */
    
    std::cout << "Library 2 has checked out book 1: "<< second_record.getCheckOutHistory(book_1) << std::endl;
    

    std::cout << "\nBook 1 contents: \n";
    first_record.display();


    std::cout<< std::endl;
    std::cout << "\nBook 2 contents: \n";
    second_record.display();
    
    
    first_record += second_record;
    

    std::cout<< "\nAre they Equivalent " << first_record.equivalentRecords(second_record) <<"\n";

    std::cout << "First + Second record contents += \n";
    first_record.display();
    //second_record.removeStock(book_1);

    //std::cout << "Remove book1 from library 2: \n";
    //second_record.display();
    
    
    //std::cout <<"\nTheorotically this should add book_1 twice to the end of my first Record\n";

    //first_record.display();


    /*
    std::cout<< "\n\n";
    first_record.display();
    std::cout<< "\n\n";
    std::cout << "\nDuplication of first Record, Success?: "<<first_record.duplicateStock() << std::endl;
    first_record.display();
    */
/*

    Book book_3("The Hunger Games", "Suzanne Collins", 374, 1);
    Book book_4("Final Book", "Why this Author", 46, 0);
    Book interesting_book("Name Classified","Author Classified",12345, 0);

    //Testing Book class operator functions
    std::cout<<"\n\nTESTING BOOK CLASS OPERATOR AND DISPLAY\n";
    book_1.display();
    book_2.display();
    book_5.display();


    //Testing LibraryRecord class
    std::cout<<"\n\nTESTING LIBRARYRECORD CLASS CHECKIN, CHECKOUT, DISPLAYTITLES, AND DISPLAY\n";
    
    for (int i = 0; i < 5; i++)
    {
        first_record.checkIn(book_1);
        second_record.checkIn(interesting_book);
    }
    //first: 1,1,1,1,1
    //second: ib,ib,ib,ib,ib

    first_record.checkIn(book_2);
    first_record.checkIn(book_2);
    first_record.checkIn(book_3);
    //1,1,1,1,1,2,2,3

    second_record.checkIn(book_2);
    second_record.checkIn(book_5);
    //2,5
    for (int i = 0; i < 3; i++)
    {
        first_record.checkOut(book_1);
        second_record.checkOut(interesting_book);
    }
    //first:: 1,1,1
    first_record.checkOut(book_2);
    //second ib,ib,ib,2

    std::cout<< "\n\nFirst Record: "; 
    first_record.display();
    first_record.displayTitles();
    std::cout<<"book_1 checkout history: "<<first_record.getCheckOutHistory(book_1);
    std::cout<<"\nbook_2 checkout history: "<<first_record.getCheckOutHistory(book_2);
    std::cout<<"\nInteresting book checkout history: "<<second_record.getCheckOutHistory(interesting_book)<<"\n";
    second_record.display();
    second_record.displayTitles();

    std::cout<<"\n\nNOW TESTING DUPLICATESTOCK AND REMOVESTOCK\n";
    first_record.duplicateStock();
    first_record.display();
    first_record.displayTitles();
    std::cout<<"\n";
    first_record.removeStock(book_1);
    first_record.display();
    first_record.displayTitles();
    std::cout<<"\n";
    first_record.removeStock(book_1);
    first_record.display();
    first_record.displayTitles();
    std::cout<<"\n";
    
   
    std::cout<<"\n\nNOW TIME TO TEST EQUIVALENTRECORDS AND OPERATOR FUNCTIONS\n";
    std::cout<< "\nAre they Equivalent " << first_record.equivalentRecords(second_record) <<"\n";
    //first_record += second_record;
    first_record.display();
    first_record.displayTitles();
    //stuff here
    */
    return 0; 
}