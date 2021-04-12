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

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Tree_Permutations.cpp
#  Created On:      12/04/2021
#  Problem Code:    TREEPERM
=============================================================================*/


const int mxn = 1e6+1;
vi graph[mxn];
vi a(mxn),b(mxn),visited(mxn),parent(mxn),level(mxn),A(mxn),B(mxn),con(mxn);
priority_queue <pii>  LT;
ll temp = 0;
vi sset;

void treedetails(ll a, ll b){
    visited[a]++;
    level[a]=b;
    bool flag = true;
    for(ll x:graph[a]){
        if(!visited[x]){
            parent[x]=a;
            treedetails(x,b+1);
            flag=false;
        }
    }
    if(flag){
        LT.push(mp(b,a));
    }
}

void addEdge(vi adj[], ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void printGraph(vector<ll> adj[], ll V){
    for (ll v = 0; v < V; ++v){
        cout << "\n Adjacency list of vertex "<< v << "\n head ";
        for (auto x : adj[v]){
           cout << "-> " << x;
        }
        cout<<"\n";
    }
}

void condition(ll x){
    if(A[x]==B[x] && con[x]!=0){
        con[x]--;
        temp--;
    }else if(con[x]==0){
        con[x]++;
        temp++;
    }
}

ll solve2(ll x){
    B[b[x]]++;
    A[a[x]]++;
    condition(a[x]);
    condition(b[x]);
    visited[x]++;
    sset.pb(x);
    if(temp==0){
        if(visited[parent[x]]==0 && x!=1){
            LT.push(mp(level[parent[x]],parent[x]));  
        }
        con[a[x]]=0;
        con[b[x]]=0;
        A[a[x]]=0;
        A[b[x]]=0;
        B[a[x]]=0;
        B[b[x]]=0;
        return 1;
    }
    if(x==1){
        con[a[x]]=0;
        con[b[x]]=0;
        A[a[x]]=0;
        A[b[x]]=0;
        B[a[x]]=0;
        B[b[x]]=0;
        return 0;
    }
    if(visited[parent[x]]==0){
        if(solve2(parent[x])==1){
            con[a[x]]=0;
            con[b[x]]=0;
            A[a[x]]=0;
            A[b[x]]=0;
            B[a[x]]=0;
            B[b[x]]=0;
            return 1;
        }
    }
    con[a[x]]=0;
    con[b[x]]=0;
    A[a[x]]=0;
    A[b[x]]=0;
    B[a[x]]=0;
    B[b[x]]=0;
    return 0;
}

void reset(ll n){
    while(!LT.empty()){
        LT.pop();
    }
    temp=0;
    fr(i,n+1){
        graph[i].clear();
        a[i]=0;
        b[i]=0;
        visited[i]=0;
        parent[i]=0;
        level[i]=0;
        A[i]=0;
        B[i]=0;
        con[i]=0;

    }
}

void sol(){
    ll n,k;
    cin>>n>>k;
    fr(i,n-1){
        ll u,v;
        cin>>u>>v;
        addEdge(graph,u,v);
    }
    fr(i,n){
        cin>>a[i+1];
    }
    fr(i,n){
        cin>>b[i+1];
    }
    treedetails(1,1);
    fr(i,n+1){
        visited[i]=0;
    }
    vvi sets;
    bool contains  = true;
    while(!LT.empty()){
        pii leaf = LT.top();
        LT.pop();
        if(visited[leaf.sec]==0){
            temp=0;
            sset.clear();
            if(solve2(leaf.sec)!=0){
                sets.pb(sset);
            }else{
                contains=false;
                break;
            }
        }
    }
    if(k==1){
        if(contains){
            cout<<1<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }else{
        if(contains){
            ll ans = 1;
            fr(i,sets.size()){
                ll count = 0;
                ll u = sets[i][0];ll l = u;
                fr(j,sets[i].size()){
                    if(j>0){
                        if(level[sets[i][j]]<level[u]){
                            u = sets[i][j];
                        }
                        if(level[sets[i][j]]>level[u]){
                            l = sets[i][j];
                        }
                    }
                }
                for(auto c:graph[l]){
                    if(!(c==parent[l])){
                        count++;
                    }
                }
                count++;
                ans = (ans*count)%mod;
            }
            cout<<ans<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
    reset(n);
}

int main(void){
    fast;
    test(t){
        sol();
    }
}