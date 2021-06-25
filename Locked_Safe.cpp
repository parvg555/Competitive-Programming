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
#  FileName:        Locked_Safe.cpp
#  Created On:      15/03/2021
#  Problem Code:    LCKDSAFE
=============================================================================*/


void sol(){
    ll n;
    cin>>n;
    vi arr1;
    vi arr2;
    ll ans = (n*(n-1))/2;
    ll count = 1;
    fr(i,n){
        ll temp;
        cin>>temp;
        arr1.pb(temp);
        if(i==0){
            continue;
        }
        if(arr1[i]==arr1[i-1]){
            count++;
        }else{
            if(count>1){
                arr2.pb(count);
            }
            count = 1;
        }
    }
    if(count>1){
        arr2.pb(count);
    }
    fr(i,arr2.size()){
        ans-=(arr2[i]*(arr2[i]-1))/2;
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}