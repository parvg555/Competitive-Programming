#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkmagicsquare(vector<vector<int>>& grid, int n, int m){
        int sum = 0;
        int arr[10] = {0};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[n+i][m+j]>9){
                    return false;
                }
                arr[grid[n+i][m+j]]++;
            }
        }
        for(int i=1;i<10;i++){
            if(arr[i]!=1){
                return false;
            }
        }
        for(int i=0;i<3;i++){
            sum+=grid[n][m+i];
        }
        for(int i=0;i<3;i++){
            int temp = 0;
            for(int j=0;j<3;j++){
                temp+=grid[n+i][m+j];
            }
            if(temp!=sum){
                return false;
            }
        }
        for(int i=0;i<3;i++){
            int temp = 0;
            for(int j=0;j<3;j++){
                temp+=grid[n+j][m+i];
            }
            if(temp!=sum){
                return false;
            }
        }
        if (sum!=grid[n+0][m+0] + grid[n+1][m+1] + grid[n+2][m+2]){
            return false;
        }
        if (sum!=grid[n+0][m+2] + grid[n+1][m+1] + grid[n+2][m+0]){
            return false;
        }
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n<3 || m<3){
            return 0;
        }
        int ans = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(checkmagicsquare(grid,i,j) == true){
                    ans++;
                }
            }
        }
        return ans;
    }
};