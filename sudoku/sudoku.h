#ifndef SUDOKU_H
#define SUDOKU_H
/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:

    void print();
    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve();
    bool unassigned(int &row,int &col);
    bool ok(int row,int col,int num);
    bool usedROW(int row,int col,int num);
    bool usedCOL(int row,int col,int num);
    bool usedBOX(int row,int col,int num);

    //member
    int map[9][9];
    bool canSolve=0;
};

#endif // SUDOKU_H
