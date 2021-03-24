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
const int mxn = 2*1e6;
bool prime[mxn];

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Coprime_Range.cpp
#  Created On:      27/02/2021
#  Problem Code:    COPRIMEX
=============================================================================*/


void sieve(){
    for(int p=2;p*p<=mxn;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=mxn;i+=p){
                prime[i]=false;
            }
        }
    }
}

void sol(){
    ll l,r;
    cin>>l>>r;
    for(ll i=r+1;i<=mxn;i++){
        if(prime[i]==true){
            cout<<i<<"\n";
            break;
        }
    }
}  

int main(void){
    mem(prime,true);
    sieve();
    fast;
    test(t){
        sol();
    }
}