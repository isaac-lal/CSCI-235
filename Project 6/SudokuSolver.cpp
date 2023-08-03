/*
Isaac Lal
isaac.lal46@myhunter.cuny.edu
Tiziana Ligorio
Project 6
*/

#include "SudokuSolver.hpp"


//default constructor
SudokuSolver::SudokuSolver() {
  solvability_ = false;

  board_ = new int * [9];
  for (int i = 0; i < 9; i++) {
    // Declare a memory block
    // of size n
    board_[i] = new int[9];
  }
  // assign values to the allocated memory
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board_[i][j] = 0;
    }
  }
}

//param constructor that reads file and checks if it is solvable and solves it
SudokuSolver::SudokuSolver(std::string input_file_name) {
  solvability_ = false;

  board_ = new int * [9];
  for (int i = 0; i < 9; i++) {
    // Declare a memory block for each new row 
    board_[i] = new int[9]; // add 9 to each row to make 9X9 dynamic array
  }

  std::ifstream fin(input_file_name);
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading. \n";
    exit(1); // exit if failed to open the file
  }

  std::string temp_string;
  int temp_int;

  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 8; col++) {
      //reads the row's colum value
      getline(fin, temp_string, ',');
      std::istringstream(temp_string) >> temp_int;
      board_[row][col] = temp_int;
    }
    //last colum is always going to be 8 and you need to read until the \n which is defualt in get line
    getline(fin, temp_string);
    std::istringstream(temp_string) >> temp_int;
    board_[row][8] = temp_int;

  }

  if (solveSudoku())
    solvability_ = true;
  else
    solvability_ = false;

}

/**
 @post: prints out board of Sudoku
*/
void SudokuSolver::display() {
  for (int i = 0; i < 9; i++) {

    for (int j = 0; j < 9; j++) {

      if (j == 2 || j == 5) {
        if (board_[i][j] != 0)
          std::cout << board_[i][j];
        else
          std::cout << "X";

        std::cout << "  | ";
      } else {
        if (board_[i][j] != 0)
          std::cout << board_[i][j];
        else
          std::cout << "X";

      }

    }

    std::cout << "\n";

    if (i == 2 || i == 5) {
      for (int k = 0; k < 12; k++)
        std::cout << "- ";

      std::cout << "\n";
    }
  }
}

/**
 @post: helper function that solves the Sudoku if possible
*/
bool SudokuSolver::solveSudoku() {
  //checks if there are any empty spaces on board 
  Sudoku::Location location = returnNextEmpty();

  if (isPuzzleSolvable()) {
    setSolvable();
    return true; //breaks out of recurssion if solved
  }

  //else continue to fill in the board

  for (int num = 1; num <= 9; num++) {
    if (checkLegalValue(num, location)) //if legal
    {
      board_[location.row][location.col] = num;

      if (solveSudoku()) //if false proceed;
        return true;

      // sets it to 0 and continues test other values
      board_[location.row][location.col] = 0;
    }
  }

  //if not solvable returns false;
  return false;

}

/**
@post:  returns true if the value parameter (which can take on values 1-9) can 
legally be placed at the given location in the 2D array without breaking the rules of sudoku. 
It returns false if placing value at location is not a legal move.
*/
Sudoku::Location SudokuSolver::returnNextEmpty() {
  Sudoku::Location empty_space;
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board_[row][col] == 0) {
        empty_space.row = row;
        empty_space.col = col;

        return empty_space;
      }
    }
  }

  //if no empty boxes
  empty_space.row = -1;
  empty_space.col = -1;

  solvability_ = true;

  return empty_space;
}

/**
  @param: an int named value that represents value being checked for legality 
  Location named location that represents the row and col that the value is being
  checked in
  @post: checks if the value in that coordinate is legal in Sudoku game returns true if it is legal
  false otherwise
 */

bool SudokuSolver::checkLegalValue(int value, Sudoku::Location loc) {

  //check sub box 3x3 using sub box fucntion
  if (!subBoxesCheck(value, loc.row, loc.col)) // if false return false otherwise continue on
    return false;

  //check whole l.row which represents row of number we checking 
  for (int col = 0; col < 9; col++) {
    //skip if it is the placement
    if (board_[loc.row][loc.col] == value)
      continue;

    if (board_[loc.row][col] == value) {
      return false;
    }
  }

  //now do the same but for l.col coloum 
  for (int row = 0; row < 9; row++) {
    //skip if it is the placement
    if (board_[loc.row][loc.col] == value)
      continue;

    if (board_[row][loc.col] == value) {
      return false;
    }
  }

  //if all good 
  return true;
}

/**
  @param: one integer 'value' representing the value being checked,
  another integer rNum represents row number and integer named
  cNum representing colom the '
  @post: helper function that checks the subboxes of Sudoku board and checks if its a legal
  move within that box
 */
bool SudokuSolver::subBoxesCheck(int value, int rNum, int cNum) {

  if (rNum < 3) {
    //box 1(top left)
    if (cNum < 3) {
      for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
          if (rNum == row && cNum == col) //skip if it is location of value we are testing
          {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }

      // box 2(top mid)
    } else if (cNum < 6) {

      for (int row = 0; row < 3; row++) {
        for (int col = 3; col < 6; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }

      // box 3(top right)
    } else {
      for (int row = 0; row < 3; row++) {
        for (int col = 6; col < 9; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }
    }

  } else if (rNum < 6) {

    //box 4 (mid left)
    if (cNum < 3) {
      for (int row = 3; row < 6; row++) {
        for (int col = 0; col < 3; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }

      //box 5 (mid mid)
    } else if (cNum < 6) {
      for (int row = 3; row < 6; row++) {
        for (int col = 3; col < 6; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }

      //box 6 (mid right)
    } else {
      for (int row = 3; row < 6; row++) {
        for (int col = 6; col < 9; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }
    }
  } else {

    //box 7 (bottom left)
    if (cNum < 3) {
      for (int row = 6; row < 9; row++) {
        for (int col = 0; col < 3; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }
      //box 8 (bottom mid)
    } else if (cNum < 6) {
      for (int row = 6; row < 9; row++) {
        for (int col = 3; col < 6; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }

      //box 9 (bottom right)
    } else {
      for (int row = 6; row < 9; row++) {
        for (int col = 6; col < 9; col++) {
          if (rNum == row && cNum == col) {
            continue;
          }

          if (board_[row][col] == value) {
            return false;
          }
        }
      }
    }
  }

  //if all is good then
  return true;
}

/**
@post: records boolean if the puzzle as being solvable true otherwise false
*/
void SudokuSolver::setSolvable() {
  solvability_ = true;
}

/**
@post: returns true if the puzzle is solvable, false otherwise. 
*/
bool SudokuSolver::isPuzzleSolvable() {
  return solvability_;
}

/**
@post: returns the  2D pointer array representing the puzzle
*/
int ** SudokuSolver::getPuzzleNumbers() {
  return board_;
}

/**
@post: sets the  2D pointer array representing the puzzle to the value of the parameter

*/
void SudokuSolver::setPuzzleNumbers(int ** puzzle) {
  //honestly confused why this exists
}