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
#  FileName:        Blackjack.cpp
#  Created On:      11/01/2021
#  Problem Code:    BLKJK
=============================================================================*/


bool solvezero(vi arr, ll x, ll y, ll n){
    ll sum = 0;
    fr(i,n){
        sum+=arr[i];
        if(sum>=x&&sum<=y){
            return true;
        }
    }
    return false;
}

bool solveone(vi arr, ll x, ll y, ll n){
    ll sum = 0;
    fr(it,n-1){
        sum+=arr[it];
        fr(i,it+1){
            rep(j,it,n){
                if(arr[j]>=arr[i]+(x-sum) && arr[j]<=arr[i]+(y-sum)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool solvetwo(vi arr, ll x, ll y, ll n){
    ll sum = 0;
    fr(it,n-2){
        sum+=arr[it];
        fr(i,it+1){
            rep(j,i+1,it){
                ll z = arr[i]+arr[j];
                rep(k,j+1,n-1){
                    rep(l,k+1,n-1){
                        if(arr[k]+arr[l]>=z+(x-sum) && arr[k]+arr[l]<=z+(y-sum)){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void sol(){
    ll n,x,y;
    cin>>n>>x>>y;
    vi arr;
    fr(i,n){
        ll temp;
        cin>>temp;
        arr.pb(temp);
    }
    if(solvezero(arr,x,y,n)==true){
        cout<<0<<endl;
    }else if(solveone(arr,x,y,n)==true){
        cout<<1<<endl;
    }else if(solvetwo(arr,x,y,n)==true){
        cout<<2<<endl;
    }else{
        cout<<-1<<endl;
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}