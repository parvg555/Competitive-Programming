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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Valid_Paths.cpp
#  Created On:      15/05/2021
#  Problem Code:    VPATH
=============================================================================*/


const int mxn = 1e5 + 10;
ll temp1[mxn];
ll temp2[mxn];
vi graph[mxn];

void crawler(ll c, ll p){
    ll count = 0;
    temp1[c] = 1;
    temp2[c] = 1;
    for(auto i: graph[c]){
        if(i!=p && i!=c){
            crawler(i,c);
            temp1[c] = (temp1[c] + temp1[i] + temp1[i])%mod;
            temp2[c] = (temp2[c] + temp2[i] + temp1[i])%mod;
            count = (count + temp1[i])%mod;
        }
    }
    for(auto i: graph[c]){
        if(i!=p && i!=c){
            ll temp = (count - temp1[i] + mod)%mod;
            temp = (temp1[i] * temp)%mod;
            temp2[c] = (temp2[c] + temp)%mod;
        }
    }
}

void clean(ll n){
    fr(i,n+1){
        graph[i].clear();
        temp1[i] = 0;
        temp2[i] = 0;
    }
}

void sol(){
    ll n;
    cin>>n;
    fr(i,n-1){
        ll p,c;
        cin>>p>>c;
        graph[p].pb(c);
        graph[c].pb(p);
    }
    crawler(1,0);
    cout<<temp2[1]%mod<<"\n";
    clean(n);
}

int main(void){
    mem(temp1,0);
    mem(temp2,0);
    fast;
    test(t){
        sol();
    }
}