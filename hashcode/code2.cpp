#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define max 10010
#define mod 999999999989
ll dp[max][max]={0};
ll ways(ll arr[],ll n,ll sum)
{
    if(sum<0)
        return 0;
    if(sum>0 && n<=0)
        return 0;
    if(sum==0 && n>=0)
        return 1;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    dp[n][sum]=(ways(arr,n-1,sum)%mod+ways(arr,n,sum-arr[n-1])%mod)%mod;
    return dp[n][sum];
}
int main()
{
    int i,n=10000;
    ll arr[max]={0};
    for(i=0;i<n;i++)
    arr[i]=i+1;
    memset(dp,-1,sizeof(dp));
    cout<<ways(arr,n,n)-1;
    return 0;
}