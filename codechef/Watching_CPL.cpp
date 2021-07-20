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
#  FileName:        Watching_CPL.cpp
#  Created On:      02/01/2021
#  Problem Code:    WIPL
=============================================================================*/

ll diff(vi sel,ll sum,ll n){
    bool dp[n+1][sum+1];
    for(ll i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(ll i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(sel[i-1]<=j){
                dp[i][j] |= dp[i-1][j-sel[i-1]];
            }
        }
    }
    int diff = INT_MAX;
    for(ll j = sum/2;j>=0;j--){
        if(dp[n][j]==true){
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

ll findmin(vi box,ll h){
    ll sum = 0;
    vi sel;
    for(int i=0;i<box.size();i++){
        sum+=box[i];
        sel.pb(box[i]);
        if(sum>=2*h){
            ll dif = diff(sel,sum,i+1);
            if(dif>=INT_MAX){
                return -1;
            }
            ll ans = sum - dif;
            if(ans/2 >= h){
                return i+1;
            }
        }
    }
    return -1;
}

void sol(){
    int n,h;
    cin>>n>>h;
    vi box;
    fr(i,n){
        ll temp;
        cin>>temp;
        box.pb(temp);
    }
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    
    sort(box.begin(),box.end(),greater<ll>());
    ll ans = findmin(box,h);
    cout<<ans<<endl;
    return;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}