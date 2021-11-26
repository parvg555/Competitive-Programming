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

const long long mxn = 1e6;
vi adj[mxn];
ll ans[mxn];

void reset(ll n){
    fr(i,n+1){
        ans[i] = 0;
        adj[i].clear();
    }
}

void setmin(ll start, ll level){
    ans[start] = level;
    for(auto i:adj[start]){
        setmin(i,level+1);
    }
}

void sol(){
    ll n;
    cin>>n;
    reset(n);
    vi b(n);
    vi p(n);
    ll head = -1;
    fr(i,n){ 
        cin>>b[i];
        if(b[i] == i+1) head = i+1;
        if(b[i]!= i+1) adj[b[i]].pb(i+1);
    }
    fr(i,n) cin>>p[i];
    if(head == -1){
        cout<<"-1\n";
        return;
    }
    setmin(head,0);
    ll current = 0;
    bool an = true;
    for(ll i=0;i<n;i++){
        if(ans[p[i]] <= i){ 
            ans[p[i]] = current;
        }else{
            an = false;
        }
        current = (2*current)+1;
    }
    if(an){
        for(ll i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<"-1\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}