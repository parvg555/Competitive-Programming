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
#  FileName:        POSPREFS.cpp
#  Created On:      05/12/2020
=============================================================================*/


void sol(){
    ll n,k;
    cin>>n>>k;
    ll neg = n-k;
    ll check= 0;
    for(ll i=1;i<=n;i++){
        if(i%2==0){
            if(neg>0){
                cout<<i*(-1)<<" ";
                neg--;
            }else{
                if(check >= k){
                    cout<<i*(-1)<<" ";
                }else{
                    cout<<i<<" ";
                    check++;
                }
            }
        }else{
            if(check >= k){
                    cout<<i*(-1)<<" ";
                }else{
                    cout<<i<<" ";
                    check++;
            }
        }
    }
    cout<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}