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

const int N = 2e5 + 10;
ll dp[2][N]; int A[2][N], n; vector<int> adj[N];
 
void DFS(int v, int p = -1) {
    dp[0][v] = dp[1][v] = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        DFS(u, v);
        dp[0][v] += max(abs(A[0][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[0][v] - A[0][u]));
        dp[1][v] += max(abs(A[1][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[1][v] - A[0][u]));
    }
}
 
void Solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[0][i], &A[1][i]);
    fill(adj + 1, adj + n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    printf("%lld\n", max(dp[0][1], dp[1][1]));
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) Solve();
    return 0;
}