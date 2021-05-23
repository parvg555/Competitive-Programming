#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int ll;
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
#  FileName:        An_Interesting_Sequence.cpp
#  Created On:      14/05/2021
#  Problem Code:    ISS
=============================================================================*/


const int mxn = 4e6 + 10;
ll dp1[mxn];
ll dp2[mxn];

ll m2(ll i){
    return i+i;
}

void dp1creator(){
    fr(i,mxn){
        if(i>1 && dp1[i]==i){
            dp1[i] = i-1;
            ll temp = i-1;
            for(ll j=m2(i);j<mxn;j = j+i){
                dp1[j] = temp*(dp1[j]/i);
            }
        }
    }
}

void dp2creator(){
    fr(i,mxn){
        if(i>0){
            dp2[i]= dp2[i] + (i-1);
            for(ll j=m2(i);j<mxn;j=j+i){
                dp2[j] = dp2[j] + i*((1+dp1[j/i])/2);
            }
        }
    }
}

void sol(){
    ll n;
    cin>>n;
    n = 4*n;
    n += 1;
    cout<<dp2[n]<<"\n";
}

int main(void){
    fast;
    fr(i,mxn){
        dp1[i] = i;
        dp2[i] = 0;
    }
    dp1creator();
    dp2creator();
    test(t){
        sol();
    }
}