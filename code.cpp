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
#define remax(a,b) (a=max((a),(b)));

const ll mxn = 1e5+1;

vi longestPath;
vi currentPath;
vi adj[mxn];

void dfs(int node, int parent, int depth){
    currentPath.pb(node);
    for(auto i: adj[node]){
        // cout<<parent<<" "<<i<<"\n";
        if(i!=parent){
            dfs(i,node,depth+1);
        }
    }
    if(adj[node].size() == 1){
        if(currentPath.size()>longestPath.size()){
            longestPath.clear();
            for(auto item: currentPath) longestPath.pb(item);
        }
    }
    currentPath.pop_back();
}

void deleteElements(){
    for(ll i=1;i<longestPath.size();i++){
        adj[i-1].clear();
        adj[i].clear();
    }
}

void reset(){
    fr(i,mxn) adj[i].clear();
    longestPath.clear();
    currentPath.clear();
}

void sol(){
    ll n;
    cin>>n;
    reset();
    fr(i,n){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0,0);
    cout<<"LONGEST PATH: "<<"\n";
    fr(i,longestPath.size()) cout<<longestPath[i]<<",";
    cout<<"\n";
    deleteElements();
    cout<<"Remaining Tree: \n";
    for(ll i=1;i<=n+1;i++){
        cout<<i<<":";
        for(auto elem: adj[i]) cout<<elem<<",";
        cout<<"\n";
    }
    

}

int main(void){
    fast;
    test(t){
        sol();
    }
}