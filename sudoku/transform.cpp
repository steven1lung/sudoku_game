#include<iostream>
#include"sudoku.h"
using namespace std;

int main() {
    // finish your transform code...
    /*
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);
       */
    Sudoku sudoku;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>sudoku.map[i][j];

    int select;

    //debug
//    sudoku.print();

    while(1) {
        cin>>select;
        if(select==0) {
            sudoku.print();
            exit(1);
        } else if(select==1) {
            int x,y;
            cin>>x>>y;
            // debug
//            cout<<"num swap "<<x<<" and "<<y<<endl;
            sudoku.swapNum(x,y);
            //          sudoku.print();
        } else if(select==2) {
            int x,y;
            cin>>x>>y;
            //debug
            //        cout<<"row swap "<<x<<" and "<<y<<endl;
            sudoku.swapRow(x,y);
            //    sudoku.print();
        } else if(select==3) {
            int x,y;
            cin>>x>>y;
            //debug
            //      cout<<"col swap "<<x<<" and "<<y<<endl;
            sudoku.swapCol(x,y);
            //sudoku.print();
        } else if(select==4) {
            int x;
            cin>>x;

            //debug
            //    cout<<"rotate "<<x<<endl;
            sudoku.rotate(x);
            //    sudoku.print();
        } else if(select==5) {
            int x;
            cin>>x;
            //debug
            //  cout<<"flip "<<x<<endl;
            sudoku.flip(x);
            // sudoku.print();
        }
    }
    return 0;
}
