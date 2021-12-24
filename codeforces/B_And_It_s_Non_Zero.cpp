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

long long getcount(long long n, int k)
{
    // Store count till nearest
    // power of 2 less than N
    long long res = (n >> (k + 1)) << k;
 
    // If K-th bit is set in N
    if ((n >> k) & 1)
 
        // Add to result the nearest
        // power of 2 less than N
        res += n & ((1ll << k) - 1);
 
    // Return result
    return res;
}

void sol(){
    ll a,b;
    cin>>a>>b;
    ll n = (b-a)+1;
    ll ans = LONG_LONG_MAX;
    for(ll i=0;i<=31;i++){
        ll count1 = getcount(b+1,i);
        ll count2 = getcount(a,i);
        ll ones = count1 - count2;
        ll zeros = n - ones;
        if(ones > 0){
            ans = min(ans,zeros);
        }
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}