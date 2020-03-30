#include<iostream>
using namespace std;

void go(int &x){
//    x=x+1;
    x++;
}
int main(){
    int map[9][9],count=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            cin>>map[i][j];
            if(map[i][j]==0) count++;
        }
    cout <<count<<endl;
    return 0;
}
