#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<target || (sum+target)%2!=0){
            return 0;
        }
        int t = (sum+target)/2;
        int dp[nums.size()+1][t+1];
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<t+1;j++){
                if(j==0){
                    dp[i][j] = 1;
                }else if(i==0){
                    dp[i][j] = 0;
                }
                if(i>0){
                    if(j-nums[i-1]<0){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                    }
                }
            }
        }
        return dp[nums.size()][t];
    }
};