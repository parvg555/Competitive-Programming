#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d+1][target+1];
        for(int i=0;i<d+1;i++){
            for(int j = 0;j<target+1;j++){
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<d+1;i++){
            for(int j = 0;j<target+1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 1){
                    if(j>0 && j<=f){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }else{
                    if(i>j){
                        dp[i][j] = 0;
                    }else{
                        for(int k=1;k<=f;k++){
                            if(j-k>0){
                                dp[i][j]= (dp[i][j] + dp[i-1][j-k])%1000000007;
                            }
                        }
                    }
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[d][target];
    }
};