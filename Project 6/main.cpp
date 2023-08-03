#include "SudokuSolver.hpp"


int main() {
  SudokuSolver a("puzzle3.csv");

  a.display();

  // SudokuSolver b;

  // // Sudoku::Location loc; 

  // // loc.col= 4;
  // // loc.row =4;
  // // if (a.checkLegalValue(9,loc))
  // //     std::cout << "\nis legal\n";
  // // else
  // //     std::cout << "\nis not legal\n";

  // b.print();

  std::cout << "\nIs it solvable? " << a.isPuzzleSolvable();

}