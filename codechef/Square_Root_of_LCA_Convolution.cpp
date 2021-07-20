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
#define sz 101

vector <int> adj[sz];
vector <int> euler;
vector <int> depthArr;

int FAI[sz];
int level[sz];
int ptr;
int dp[sz][18];
int logn[sz];
int p2[20];

void buildSparseTable(int n){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n;i++){
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;
    }
    for(int l=1;l<15;l++){
        for(int i=0;i<n;i++){
            if(dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1){
                dp[i][l] =(depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?dp[i+p2[l-1]][l-1] : dp[i][l-1];
            }else{
                break;
            }
        }
    }
}

int query(int l,int r){
    int d = r-l;
    int dx = logn[d];
    if(l==r){
        return l;
    }
    if(depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]){
        return dp[r-p2[dx]][dx];
    }else{
        return dp[l][dx];
    }
}

void preprocess()
{
    p2[0] = 1;
    for (int i=1; i<18; i++)
        p2[i] = p2[i-1]*2;
    int val = 1,ptr=0;
    for (int i=1; i<sz; i++)
    {
        logn[i] = ptr-1;
        if (val==i)
        {
            val*=2;
            logn[i] = ptr;
            ptr++;
        }
    }
}

void dfs(int cur,int prev,int dep)
{
    if (FAI[cur]==-1){
        FAI[cur] = ptr;
    }
    level[cur] = dep;
    euler.push_back(cur);
    ptr++;
 
    for (auto x:adj[cur]){
        if (x != prev){
            dfs(x,cur,dep+1);
            euler.push_back(cur);
            ptr++;
        }
    }
}

void makeArr(){
    for (auto x : euler)
        depthArr.push_back(level[x]);
}

int LCA(int u,int v)
{
    if (u==v){
       return u;
    }
    if (FAI[u] > FAI[v]){
       swap(u,v);
    }
    return euler[query(FAI[u], FAI[v])];
}

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

struct Lset{
    vector <int> U;
};

void sol(){
    int n,P;
    cin>>n>>P;
    for(int i=1;i<n;i++){
        int t;
        cin>>t;
        addEdge(i+1,t);
    }
    preprocess();
    ptr = 0;
    memset(FAI,-1,sizeof(FAI));
    dfs(1,0,0);
    makeArr();
    buildSparseTable(depthArr.size());
    Lset L[n+1][n+1];
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            L[v][LCA(u,v)].U.pb(u);
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<"v- "<<i<<" s- "<<j<<endl;
            cout<<"U - ";
            for(int k=0;k<L[i][j].U.size();k++){
                cout<<L[i][j].U[k]<<" ";
            }
            cout<<endl;
        }
    }

}

int main(void){
    fast;
    test(t){
        sol();
    }
}