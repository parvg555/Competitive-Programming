#include<bits/stdc++.h>
using namespace std;

int minDistance(string A, string B) {
    int n = A.length();
    int m = B.length();
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i==0){
                dp[i][j] = j;
            }else if(j==0){
                dp[i][j] = i;
            }else{
                if(A[i-1] == B[j-1]){
                    dp[i][j] = min(dp[i-1][j] + 1 , min(dp[i][j-1] + 1, dp[i-1][j-1]));
                }else{
                    dp[i][j] = min(dp[i-1][j] + 1 , min(dp[i][j-1] + 1, dp[i-1][j-1] + 2));
                }
            }
            if(dp[i][j]<10){
                cout<<"0"<<dp[i][j]<<" ";
            }else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    return dp[n][m];
}

int main(void){
    string b = "brief";
    string a = "drive";
    cout<<minDistance(a,b)<<"\n";
}
