#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int32_t ll;
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
const int W = 7;
const int N = 4;
ll wt[N]={1,3,4,5};
ll value[N]={1,4,5,7};
ll dp[N+1][W+1];

ll maxprofit(ll pos, ll weight, ll profit){
    if(dp[pos][weight]!=-1){
        return dp[pos][weight];
    }
    if(pos>=N){
        return profit;
    } 
    ll included = 0;
    if(weight+wt[pos]<=W){
        included = maxprofit(pos+1,weight+wt[pos],profit+value[pos]);
    }
    dp[pos][weight]=max(included,maxprofit(pos+1,weight,profit));
    return dp[pos][weight];
}

void sol(){
    mem(dp,-1);
    cout<<maxprofit(0,0,0)<<"\n";
    fr(i,N+1){
        fr(j,W+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(void){
    fast;
    sol();
}