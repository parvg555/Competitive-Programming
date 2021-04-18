#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        BookShop.cpp
#  Created On:      17/04/2021
#  Problem Code:    bookshop
=============================================================================*/


void sol(){
    ll n,x;
    cin>>n>>x;
    vi h,s;
    fr(i,n){
        ll temp;
        cin>>temp;
        h.pb(temp);
    }
    fr(i,n){
        ll temp;
        cin>>temp;
        s.pb(temp);
    }
    ll dp[n+1][x+1];
    fr(i,n+1){
        fr(j,x+1){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else {
                if(h[i-1]<=j){
                    dp[i][j] = max(s[i-1]+dp[i-1][j-h[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][x];
}

int main(void){
    fast;
    sol();
}