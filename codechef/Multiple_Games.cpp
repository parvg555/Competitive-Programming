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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
const int mxn = 1e6+1;

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Multiple_Games.cpp
#  Created On:      14/02/2021
#  Problem Code:    MULGAME
=============================================================================*/


void sol(){
    ll  n,q,m;
    map<pair<ll,ll>,ll> mp;
    ll mx = 0;
    cin>>n>>q>>m;
    ll sec[mxn]={};
    ll ans[m+1] = {};
    vi a;
    fr(i,n){
        ll temp;
        cin>>temp;
        a.pb(temp);
    }
    fr(i,q){
        ll l,r;
        cin>>l>>r;
        if(a[l-1]>m){
            continue;
        }else{ 
            sec[a[l-1]]++;
            sec[m+1]--;
            if(a[l-1]<=m && a[r-1]>m){
                continue;    
            }else{
                mp[{a[l-1],a[r-1]}]++;
            }
        }
    }
    for(auto x: mp){
        sec[x.fi.fi+x.fi.sec]-=x.sec;
        sec[x.fi.sec+2*x.fi.fi]+=x.sec;
        ll temp = x.fi.sec+2*x.fi.fi;
        while(temp+x.fi.sec<=m){
            temp+=x.fi.sec;
            sec[temp] -= x.sec;
            sec[temp+x.fi.fi]+=x.sec;
            temp+=x.fi.fi;
        }
    }
    rep(i,1,m){
        sec[i]+=sec[i-1];
        remax(mx,sec[i]);
    }
    cout<<mx<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}