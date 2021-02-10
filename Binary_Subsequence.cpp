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
#  FileName:        Binary_Subsequence.cpp
#  Created On:      30/01/2021
#  Problem Code:    BINSUBS
=============================================================================*/


void sol(){
    ll n;
    cin>>n;
    ll zero = 0;
    ll one = 0;
    string s;
    cin>>s;
    fr(i,n){
        if(s[i]=='0'){
            zero++;
        }else{
            one++;
        }
    }
    if(zero==0||one==0){
        cout<<"0"<<endl;
        return;
    }
    ll o = 0;
    ll z = 0;
    ll ans = LLONG_MAX;
    fr(i,n){
        if(s[i]=='0'&& s[i+1]=='1'){
            //cout<<"ans at - "<<i<<endl;
            if(o+(zero-z)-1<ans){
                ans = o+(zero-z)-1;
            }
        }
        if(s[i]=='0'){
            z++;
        }else{
            o++;
        }
    }
    if(one<ans){
        ans=one;
    }
    if(zero<ans){
        ans=zero;
    }
    cout<<ans<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}