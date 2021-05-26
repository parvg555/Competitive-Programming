#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
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
#  FileName:        Binary_String_MEX.cpp
#  Created On:      10/04/2021
#  Problem Code:    MEXSTR
=============================================================================*/

const int mxn = 1e6+6;
ll dp[mxn];
ll dp1[mxn];
ll next0[mxn];
ll next1[mxn];

void makenext0(string s,ll n){
    ll pos = -1;
    ll size = s.length();
    fr(i,size){
        if(n==0){
            if(s[i]=='0'){
                rep(j,pos+1,i){
                    next0[j]=i;
                    pos=i;
                }
            }
        }else{
            if(s[i]=='1'){
                rep(j,pos+1,i){
                    next1[j]=i;
                    pos=i;
                }
            }
        }
    }
    for(ll i=pos+1;i<size;i++){
        if(n==0){
            next0[i]=size;
        }else{
            next1[i]=size;
        }
    }
}

void dpmaker(string s){
    ll n = s.length();
    for(ll i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        dp1[i]=dp1[i+1];
        if(s[i]=='1' && next0[i]<n){
            remax(dp[i],dp[next0[i]+1]+1);
        }
        if(s[i]=='0'  && next1[i]<n){
            remax(dp[i],dp[next1[i]+1]+1);
        }
        if(next1[i]<n){
            remax(dp1[i],dp[next1[i]+1]+1);
        }
    }
}

void sol(){
    vi ans;
    string s;
    cin>>s;
    dp[s.length()] = 0;
    dp[s.length()+1] = 0;
    dp1[s.length()] = 0;
    dp1[s.length()+1] = 0;
    makenext0(s,0);
    makenext0(s,1);
    if(next0[0]!=s.length()){
        ll n = s.length();
        dpmaker(s);
        ans.pb(1);
        ll current = next1[0]+1;
        for(ll i= 1;i<=dp1[0];i++){
            if(current >= n){
                ans.pb(0);
            }else if(next0[current]>=n){
                ans.pb(0);
                current = next0[current]+1;
            }else if(dp[next0[current]+1]<dp1[0]-i){
                ans.pb(0);
                current = next0[current]+1;
            }else{
                ans.pb(1);
                current = next1[current]+1;
            }
        }
    }else{
        ans.pb(0);
    }
    fr(i,ans.size()){
        cout<<ans[i];
    }
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}