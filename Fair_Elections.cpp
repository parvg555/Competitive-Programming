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
#  FileName:        Fair_Elections.cpp
#  Created On:      01/01/2021
#  Problem Code:    FAIRELECT
=============================================================================*/


void sol(){
    ll n,m;
    cin>>n>>m;
    vi a;
    vi b;
    ll sum1 = 0, sum2 = 0;
    fr(i,n){
        ll temp;
        cin>>temp;
        sum1 += temp;
        a.pb(temp);
    }
    fr(i,m){
        ll temp;
        cin>>temp;
        sum2 += temp;
        b.pb(temp);
    }
    if(sum1 > sum2){
        cout<<"0"<<endl;
        return;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ll>());
    ll diff = sum2 - sum1;
    ll step = 0;
    while(diff>=0){
        if(b[step]<=a[step] || step == a.size()){
            cout<<"-1"<<endl;
            return;
        }else{
            diff = diff - 2*(b[step] - a[step]);
            step++;
        }
    }    
    cout<<step<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}