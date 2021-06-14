#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int ll;
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
#  FileName:        Boolean_Game.cpp
#  Created On:      11/04/2021
#  Problem Code:    BOOLGAME
=============================================================================*/


void sol(){
    ll n,m,k;
    cin>>n>>m>>k;
    vi g(n+1);
    vvpi arr(n+1),dp(n+1);
    dp[0].pb(mp(0,0));
    fr(i,n){
        ll temp;
        cin>>temp;
        g[i+1]=temp;
    }
    fr(i,m){
        ll u,v,d;
        cin>>u>>v>>d;
        arr[u].pb(mp(i,d));
        arr[v].pb(mp(i,d));
    }
    rep(i,1,n){
        vpi temp;
        set <ll> open;
        set <ll> sel;
        ll filled = 0,curr = 0,mask = 0;
        temp.insert(temp.end(),dp[i-1].begin(),dp[i-1].end());
        for(ll j =i;j>=1;--j){
            curr+=g[j];mask^=1LL<<j;
            for(auto x: arr[j]){
                if(open.count(x.fi)){
                    curr+=x.sec;
                }else{
                    open.insert(x.fi);
                }
            }
            if(j<2){
                temp.pb(mp(curr,mask));
            }else{
                for(auto x:dp[j-2]){
                    temp.pb(mp(x.fi+curr,mask^x.sec));
                }
            }
        }
        sort(temp.rbegin(),temp.rend());
        for(ll j=0;j<temp.size();j++){
            if(!(filled<k)){
                break;
            }
            if(!sel.count(temp[j].sec)){
                dp[i].pb(temp[j]);
                sel.insert(temp[j].sec);
                filled++;
                
            }
        }
    }
    fr(i,k){
        cout<<dp[n][i].fi<<" ";
    }
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}