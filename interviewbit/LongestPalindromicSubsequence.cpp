#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    int n = A.length();
    int dp[n];

    for(int i=n-1;i>=0;i--){
        int temp = 0;
        for(int j=i;j<n;j++){
            if(i==j){
                dp[j] = 1;
            }else if(A[i] == A[j]){
                int temp2 = dp[j];
                dp[j] = temp+2;
                temp = temp2;
            }else{
                temp = dp[j];
                dp[j] = max(dp[j-1],dp[j]);
            }
        }
    }
    return dp[n-1];
}

