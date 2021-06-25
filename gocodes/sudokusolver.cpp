#include<bits/stdc++.h>
using namespace std;

bool checksafe(int grid[9][9], int row, int col, int num){
    for(int i=0;i<9;i++){
        if(grid[row][i]==num){
            return false;
        }
        if(grid[i][col]==num){
            return false;
        }
    }
    int start_row = row - (row%3);
    int start_col = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[start_row+i][start_col+j]==num){
                return false;
            }
        }
    }
    return true;
}

bool sudokusolver(int grid[9][9], int row, int col){
    if(row==8 && col==9){
        return true;
    }
    if(col>=9){
        row++;
        col=0;
    }
    if(grid[row][col]!=0){
        return sudokusolver(grid,row,col+1);
    }
    for(int num = 1;num<=9;num++){
        if(checksafe(grid,row,col,num)==true){
            grid[row][col]=num;
            if(sudokusolver(grid,row,col+1)){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}


int main(void){
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(sudokusolver(grid,0,0)==true){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }else{
        cout<<"NO SOLUTION\n";
    }
}