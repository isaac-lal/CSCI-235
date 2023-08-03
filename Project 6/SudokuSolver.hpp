/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 6
*/

#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_

#include <iostream>

#include <vector>

#include <string>

#include <fstream>

#include <sstream>


//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku {
  struct Location {
    int row;
    int col;
  };
}

class SudokuSolver {
  public:

    //default constructor
    SudokuSolver();

  //param constructor
  SudokuSolver(std::string input_file_name);

  /**
   @post: helper function that solves the Sudoku if possible
  */
  void display();
  //Add your public members here

  /**
  @post: solves recursively the Sudoku board if possible 
  */
  bool solveSudoku();

  /**
  @post:  returns true if the value parameter (which can take on values 1-9) can 
  legally be placed at the given location in the 2D array without breaking the rules of sudoku. 
  It returns false if placing value at location is not a legal move.
  */
  Sudoku::Location returnNextEmpty();

  /**
  @param: an int named value that represents value being checked for legality 
  Location named location that represents the row and col that the value is being
  checked in
  @post: checks if the value in that coordinate is legal in Sudoku game returns true if it is legal
  false otherwise
 */
  bool checkLegalValue(int value, Sudoku::Location location);

  /**
   @param: one integer 'value' representing the value being checked,
   another integer rNum represents row number and integer named
   cNum representing colom the '
   @post: helper function that checks the subboxes of Sudoku board and checks if its a legal
   move within that box
  */
  bool subBoxesCheck(int value, int rNum, int cNum);

  /**
  @post: returns true if the puzzle is solvable, false otherwise. 
  */
  bool isPuzzleSolvable();
  // We suggest you keep track of this when solving the problem at construction, 
  //rather than solving the puzzle again each time this function is called

  /**
  @post: records boolean if the puzzle as being solvable true otherwise false
  */
  void setSolvable();

  /**
  @post: returns the  2D pointer array representing the puzzle
  */
  int ** getPuzzleNumbers();

  /**
  @post: sets the  2D pointer array representing the puzzle to the value of the parameter
  */
  void setPuzzleNumbers(int ** puzzle);

  private:
    //Add your private members here
    int ** board_; //board   

  bool solvability_; //boolean that keeps track if it is solvable or not 

};

#endif // ends SudokuSolver