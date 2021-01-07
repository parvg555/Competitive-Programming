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
#  FileName:        And_Or_Game.cpp
#  Created On:      08/01/2021
#  Problem Code:    ORAND
=============================================================================*/
ll orfunct(ll x, ll y){
    return (x|y);
}

ll andfunct(ll x, ll y){
    return (x&y);
}

vi a,b;
set <ll> diff;
stack <ll> same;

ll retandpop(){
    ll temp = same.top();
    same.pop();
    return temp; 
}

void emptystack(){
    while(!same.empty()){
        same.pop();
    }
    return;
}

void sol(){
    diff.clear();
    emptystack();
    a.clear();
    b.clear();
    diff.insert(0);
    same.push(0);
    ll n,m;
    cin>>n>>m;
    fr(i,n){
        ll temp;
        cin>>temp;
        a.pb(temp);
    }
    fr(i,m){
        ll temp;
        cin>>temp;
        b.pb(temp);
    }
    while(!same.empty()){
        ll x = retandpop();
        for(ll i=0;i<n;i++){
            ll y = a[i];
            if(diff.count(orfunct(x,y))<1){
                diff.insert(orfunct(x,y));
                same.push(orfunct(x,y));

            }
        }
        for(ll i=0;i<m;i++){
            ll y = b[i];
            if(diff.count(andfunct(x,y))<1){
                diff.insert(andfunct(x,y));
                same.push(andfunct(x,y));
            }
        }
    }
    cout<<diff.size()<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}