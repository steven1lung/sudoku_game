#include"sudoku.h"
#include<iostream>
#include<ctime>
using namespace std;

int main() {
    int question_1[9][9]= {{0,9,0,0,0,2,0,0,5},{0,8,0,1,7,0,4,0,0},{0,0,0,9,0,3,0,2,0},{2,1,0,0,3,0,9,0,0},{0,0,7,0,0,0,2,8,6},{8,0,9,0,2,0,7,3,0},{3,4,0,7,0,9,0,0,2},{0,0,5,2,4,8,0,1,0},{7,0,0,0,5,0,8,4,0}};
    int question_2[9][9]= {{0,6,0,3,0,0,8,0,4},{5,3,7,0,9,0,0,0,0},{0,4,0,0,0,6,3,0,7},{0,9,0,0,5,1,2,3,8},{0,0,0,0,0,0,0,0,0},{7,1,3,6,2,0,0,4,0},{3,0,6,4,0,0,0,1,0},{0,0,0,0,6,0,5,2,3},{1,0,2,0,0,9,0,8,0}};
    int question_3[9][9]= {{2,0,0,8,0,4,0,0,6},{0,0,6,0,0,0,5,0,0},{0,7,4,0,0,0,9,2,0},{3,0,0,0,4,0,0,0,7},{0,0,0,3,0,5,0,0,0},{4,0,0,0,6,0,0,0,9},{0,1,9,0,0,0,7,4,0},{0,0,8,0,0,0,2,0,0},{5,0,0,6,0,8,0,0,1}};


    Sudoku sudoku;
    srand(time(NULL));
    int select=rand()%3+1;
    if(select==1) {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                sudoku.map[i][j]=question_1[i][j];
    } else if(select==2) {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                sudoku.map[i][j]=question_2[i][j];
    } else if(select==3) {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                sudoku.map[i][j]=question_3[i][j];
    }
    sudoku.rotate(rand()%4);
    if(rand()%1==1)
        sudoku.flip(rand()%1);
    sudoku.swapRow(rand()%3,rand()%3);
    sudoku.swapCol(rand()%3,rand()%3);
    for(int i=0; i<5; i++)
        sudoku.swapNum(rand()%9+1,rand()%9+1);
    sudoku.print();

    return 0;
}
