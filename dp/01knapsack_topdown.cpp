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
const int w = 7;
const int n = 4;
int wt[4]={1,3,4,5};
int val[4]={1,4,5,7};
int dp[n+1][w+1];

void sol(){
    mem(dp,-1);    
    fr(i,n+1){
        fr(j,w+1){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else{
                if(wt[i-1]<=j){
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"ans: "<<dp[n][w]<<"\n";

}

int main(void){
    fast;
    sol();
}