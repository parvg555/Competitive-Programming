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

const ll mxn = 1000000;
bool prime[mxn];

void sieve(){
    ll n = mxn;
    for(ll p=2;p*p<=n;p++){
        if(prime[p]){
            for(ll i=p*p;i<=n;i+=p) prime[i] = false;
        }
    }
}

void sol(){
    ll n,e;
    cin>>n>>e;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    ll ans = 0;
    fr(i,n){
        if(arr[i] == 1){
            bool flag = false;
            ll pos = i;
            while(pos+e<n){
                if(arr[pos+e] == 1){
                    if(flag) ans++;
                    pos = pos + e;
                }else if(flag==false && prime[arr[pos+e]]){
                    pos = pos + e;
                    ans++;
                    flag = true;
                }else{
                    break;
                }
            }
        }else if(prime[arr[i]]){
            ll pos = i;
            while(pos+e < n && arr[pos+e] == 1) {ans++;pos=pos+e;}
        }
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    memset(prime,true,sizeof(prime));
    sieve();
    test(t){
        sol();
    }
}