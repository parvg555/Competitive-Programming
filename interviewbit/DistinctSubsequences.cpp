#include<bits/stdc++.h>
using namespace std;

int numDistinct(string A, string B) {
    int m = A.length();
    int n = B.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<=m;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[m][n];
}