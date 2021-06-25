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
#  FileName:        College_Life_4.cpp
#  Created On:      09/03/2021
#  Problem Code:    COLFLG4
=============================================================================*/


void sol(){
    ll cost = LONG_LONG_MAX;
    ll count = 0;
    ll n;
    cin>>n;
    ll e,h;
    cin>>e>>h;
    ll a,b,c;
    cin>>a>>b>>c;
    ll m = min(e,h);
    for(ll i=0;i<=m && i<=n;i++){
        ll max_ommlet = (e-i)/2;
        ll max_milkshake = (h-i)/3;
        if(max_ommlet+max_milkshake>=n-i){
            ll req = n-i;
            if(a<b){
                ll ommlet_used = min(max_ommlet,req);
                req-=ommlet_used;
                cost = min(cost,i*c+ommlet_used*a+(req)*b);
                count = n;
            }else{
                ll milkshake_used = min(max_milkshake,req);
                req-=milkshake_used;
                cost=min(cost,i*c+milkshake_used*b+(req)*a);
                count = n;
            }
        }
    }
    if(count!=n){
        cout<<"-1\n";
        return;
    }
    cout<<cost<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}