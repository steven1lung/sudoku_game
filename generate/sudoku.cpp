#include"sudoku.h"
#include<iostream>
void Sudoku::print() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            std::cout<<map[i][j];
            if(j<8) std::cout<<' ';
            else std::cout<<'\n';
        }
    }
}
void Sudoku::swapNum(int x,int y) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j]==x)map[i][j]=y;
            else if(map[i][j]==y) map[i][j]=x;
        }
    }
}
void Sudoku::swapRow(int x,int y) {
    int temp[3][9]= {0};
    int m=0;
    for(int i=x*3; i<x*3+3; i++) {
        for(int j=0; j<9; j++)
            temp[m][j]=map[i][j];
        m++;
    }

    m=y*3;
    for(int i=x*3; i<x*3+3; i++) {
        for(int j=0; j<9; j++)
            map[i][j]=map[m][j];
        m++;
    }
    m=0;
    for(int i=y*3; i<y*3+3; i++) {
        for(int j=0; j<9; j++)
            map[i][j]=temp[m][j];
        m++;
    }
}
void Sudoku::swapCol(int x,int y) {
    int temp[9][3]= {0};
    for(int i=0; i<9; i++) {
        int m=0;
        for(int j=x*3; j<x*3+3; j++) {
            temp[i][m]=map[i][j];
            m++;
        }

    }
    for(int i=0; i<9; i++) {
        int m=y*3;
        for(int j=x*3; j<x*3+3; j++) {
            map[i][j]=map[i][m];
            m++;
        }
    }
    for(int i=0; i<9; i++) {
        int m=0;
        for(int j=y*3; j<y*3+3; j++) {
            map[i][j]=temp[i][m];
            m++;
        }
    }
}
void Sudoku::rotate(int x) {
    int temp[9][9];
    x%=4;
    for(int count=0; count<x; count++) {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                temp[i][j]=map[i][j];
        int n=0;
        for(int i=0; i<9; i++) {
            int m=8;
            for(int j=0; j<9; j++) {
                map[i][j]=temp[m][n];
                m--;
            }
            n++;
        }
    }
}
void Sudoku::flip(int x) {
    if(x==0) {
        //up down
        int temp;
        for(int i=0; i<4; i++)
            for(int j=0; j<9; j++) {
                temp=map[i][j];
                map[i][j]=map[8-i][j];
                map[8-i][j]=temp;
            }
    } else if(x==1) {
        //left right
        int temp;
        for(int i=0; i<9; i++)
            for(int j=0; j<4; j++) {
                temp=map[i][j];
                map[i][j]=map[i][8-j];
                map[i][8-j]=temp;
            }
    }
}
bool Sudoku::unassigned(int &row,int &col) {
    for(row=0; row<9; row++)
        for(col=0; col<9; col++)
            if(map[row][col]==0)
                return 1;
    return 0;
}
bool Sudoku::usedROW(int row,int col,int num) {
    for(int i=0; i<9; i++)
        if(map[row][i]==num) {
            return 1;
        }
    return 0;
}
bool Sudoku::usedCOL(int row,int col,int num) {
    for(int i=0; i<9; i++)
        if(map[i][col]==num) {
            return 1;
        }
    return 0;
}
bool Sudoku::usedBOX(int row,int col,int num) {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(map[i+row][j+col]==num) {
                return 1;
            }
    return 0;
}
bool Sudoku::ok(int row,int col,int num) {
    return !usedROW(row,col,num)&&!usedCOL(row,col,num)&&!usedBOX(row-row%3,col-col%3,num)&&map[row][col]==0;
}
int Sudoku::solve() {
    int row,col;
    int count=0;
    if(!unassigned(row,col)) return 1;
    for(int num=1; num<=9; num++) {
        if(ok(row,col,num)) {
            map[row][col]=num;
            if(solve()) return 1;
            map[row][col]=0;
        }
    }
    return 0;
}

