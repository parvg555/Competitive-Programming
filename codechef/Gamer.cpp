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
    ll n,p;
    cin>>n>>p;
    vi x,y,v;
    set <ll> distinctx;
    set <ll> distincty;
    fr(i,n){
        ll start, end, value;
        cin>>start>>end>>value;
        distinctx.insert(start);
        distincty.insert(end);
        x.pb(start);
        y.pb(end);
        v.pb(value);
    }
    ll ans = LONG_LONG_MIN;
    for(auto i: distinctx){
        for(auto j: distincty){
            if(i<=j){
                cout<<"i: "<<i<<" j: "<<j<<"\n";
                ll sum = 0;
                for(ll k=0;k<n;k++){
                    if(x[k]>=i && y[k]<=j && x[k]<=y[k]){
                        cout<<x[k]<<" "<<y[k]<<" "<<v[k]<<" "<<sum<<"\n";
                        sum+=v[k];
                    }
                }
                //cout<<sum<<"\n";
                remax(ans,sum-(p*(j-i)));
            }
        }
    }
    cout<<ans;
}

int main(void){
    fast;
    sol();
}