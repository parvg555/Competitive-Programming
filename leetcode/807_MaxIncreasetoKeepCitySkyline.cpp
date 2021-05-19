#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector <int> horizontal, vertical;
        int ans = 0;
        int size = grid.size();
        for(int i=0;i<size;i++){
            int maxh = 0;
            int maxv = 0;
            for(int j= 0;j<size;j++){
                maxh = max(maxh,grid[i][j]);
                maxv = max(maxv, grid[j][i]);
            }
            //cout<<maxh<<" "<<maxv<<"\n";
            horizontal.push_back(maxh);
            vertical.push_back(maxv);
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                ans+=(abs(grid[i][j] - min(horizontal[i],vertical[j])));
            }
        }
        return ans;
    }
};