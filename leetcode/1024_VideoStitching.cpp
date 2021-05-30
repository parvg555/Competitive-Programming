#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int dp[101][101] = {0};
        for(int i=0;i<clips.size();i++){
            if(clips[i][1]!=0){
                dp[clips[i][0]][clips[i][1]] = 1;
            }
        }
        for(int i=0;i<101;i++){
            for(int j=1;j<101;j++){
                if(dp[i][j] == 1){
                    dp[i][0] = max(dp[i][0],j);
                }
            }
        }
        
        for(int i=1;i<101;i++){
            dp[i][0] = max(dp[i][0],dp[i-1][0]);
        }
        
        if(time>dp[100][0]){
            return -1;
        }
        int ans = 0;
        int i = 0;
        while(i<time){
            if(dp[i][0]<= i ){
                return -1;
            }
            i = dp[i][0];
            ans++;
        }
        return ans;
    }
};