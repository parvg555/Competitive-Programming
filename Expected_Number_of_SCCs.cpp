#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
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

ll power(ll a, ll b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    if(b%2 == 1){
        return (power(a,b-1)*a)%mod;
    }
    ll q = power(a,b/2);
    return (q*q)%mod;
}

ll dp[100001];

void makedp(){
    for(ll i=0;i<100001;i++){
        if(i==0){
            dp[i]=1;
        }else{
            dp[i] = (dp[i-1]*i)%mod;
        }
    }
    return;
}

ll calcc(ll p, ll q){
    return (((dp[p]/dp[p-q])%mod)/dp[q])%mod;
}

ll calcans (ll p, ll q){
    ll expo = mod - 2;
    while(expo){
        if(expo & 1){
            p = (p*q)%mod;
        }
        q=(q*q)%mod;
        expo>>=1;
    }
    return p;
}

void sol(){
    ll m,n,k;
    cin>>m>>n>>k;
    makedp();
    if(m==1){
        ll p = 0;
        ll product = 1;
        for(ll i=0;i<n;i++){
            ll f = (calcc(n-1,i)*(i+1))%mod;
            if(i==0){
                product*=k;
            }else{
                product*=(k-1);
            }
            p = (p+(f*product)%mod)%mod;
        }
    }else{
        cout<<"0"<<endl;
    }
}

int main(void){
    fast;
    sol();
}