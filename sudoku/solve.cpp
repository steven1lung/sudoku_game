#include"sudoku.h"
#include<iostream>
using namespace std;

int main() {
    // finish your solve code...
    Sudoku sudoku;
    int count=81;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            cin>>sudoku.map[i][j];
            if(sudoku.map[i][j]!=0)
                count--;
        }
    //cout<<sudoku.solve();
    int answer=sudoku.solve();
    if(count>64) {
        cout<<"2\n";
        return 0;
    }
    if(answer==1) {
        cout<<"1"<<endl;
        sudoku.print();
    } else cout<<"0\n";

    if(sudoku.canSolve==1) sudoku.print();
    return 0;
}
