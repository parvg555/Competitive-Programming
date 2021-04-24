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

void sol(){
    ll n,x;
    cin>>n>>x;
    vi arr;
    fr(i,n){
        ll temp;
        cin>>temp;
        arr.pb(temp);
    }
    bool dp[n+1][x+1];
    fr(i,n+1){
        fr(j,x+1){
            dp[i][j]=0;
        }
    }
    fr(i,n+1){
        fr(j,x+1){
            if(i==0&&j==0){
                dp[i][j]=1;
            }else if(i==0){
                dp[i][j]=0;
            }else if(j==0){
                dp[i][j]=1;
            }else{
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]]==1 || dp[i-1][j]==1) ;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    if(dp[n][x]){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }

}

int main(void){
    fast;
    sol();
}