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

void sol(){
    ll n,k;
    cin>>n>>k;
    if(n==1){
        vi ans(n);
        ans[0] = 1;
        fr(i,n) cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }
    vi ans(n+1);
    fr(i,n+1) if(i>0) ans[i]=i;
    ll swaps = ((n-k)/2);
    if((n-k)%2!=0) swap(ans[1],ans[2]);
    ll start = n;
    while(swaps--){
        swap(ans[start],ans[start-1]);
        start-=2;
    }
    fr(i,n+1) if(i>0) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}