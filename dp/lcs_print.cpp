#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1] = {0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    }
    string ans = "";
    int i = n;
    int j = m;

    while(i!=0 && j!=0){
        if(s1[i-1] == s2[j-1]){
            ans+= s1[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"Length: "<<dp[n][m]<<"\n";
    cout<<"String: "<<ans<<"\n";

}