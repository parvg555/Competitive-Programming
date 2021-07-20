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
#  FileName:        Worthy_Matrix.cpp
#  Created On:      05/04/2021
#  Problem Code:    KAVGMAT
=============================================================================*/


void sol(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll sum[n][m];
    ll ans = 0;
    fr(i,n){
        fr(j,m){
            ll temp;
            cin>>temp;
            sum[i][j] = temp-k;
            if(sum[i][j]>=0){
                ans++;
            }
        }
    }
    //making cumilative matrix
    fr(i,m){
        if(i!=0){
            sum[0][i] += sum[0][i-1];
        }
    }
    fr(i,n){
        if(i!=0){
            sum[i][0] += sum[i-1][0];
        }
    }
    for(ll i=1;i<n;i++){
        for(ll j=1;j<m;j++){
            sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    ll size = 2;
    while(size<=n){
        fr(i,n-size+1){
            fr(j,m-size+1){
                ll res = sum[i+size-1][j+size-1];
                if(i>0){
                    res -= sum[i-1][j+size-1];
                }
                if(j>0){
                    res -= sum[i+size-1][j-1];
                }
                if(i>0&&j>0){
                    res+=sum[i-1][j-1];
                }
                if(res>=0){
                    ans++;
                }
            }
        }
        size++;
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}