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
#define inn freopen("chapter2.txt", "r", stdin)
#define outt freopen("chapter2_output2.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

vector<int> adj[26];

void addEdge(int u, int v)
{
    
    adj[u].push_back(v);
}


bool BFS(int src, int dest, int v,int pred[], int dist[])
{
    
    list<int> queue;
 
    
    bool visited[v];
 
    
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
 
                
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}

int printShortestDistance(int s,int dest, int v = 26)
{
    
    int pred[v], dist[v];
 
    if (BFS(s, dest, 26, pred, dist) == false) {
        return -1;
    }
 
    
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    return dist[dest];
}

ll sol(){
    fr(i,26){
        adj[i].clear();
    }
    string s;
    cin>>s;
    //set <int> check;
    ll fre[26];
    for(int i=0;i<26;i++){
        fre[i] = 0;
    }
    fr(i,s.length()){
        fre[s[i] - 'A']++;
    }
    ll n;
    cin>>n;
    fr(i,n){
        string temp;
        cin>>temp;
        addEdge(temp[0] - 'A', temp[1] - 'A');
    }
    ll ans = LONG_LONG_MAX;
    ll fails = 0;
    for(int i=0;i<26;i++){
        ll temp_ans = 0;
        bool flag = true;
        for(int j=0;j<26;j++){
            if(i!=j && fre[j] > 0){
                int shortest_distance = printShortestDistance(j,i);
                if(shortest_distance == -1){
                    fails++;
                    flag = false;
                    break;
                }
                temp_ans += fre[j] * shortest_distance;
            }
        }
        if(flag){ans = min(ans,temp_ans);}
    }
    
    if(ans == LONG_LONG_MAX){
        return -1;
    }
    return ans;
}

int main(void){
    inn;
    outt;
    fast;
    ll count = 1;
    test(t){
        cout<<"Case #"<<count<<": "<<sol()<<"\n";
        count++;
    }
}