#include<bits/stdc++.h>
using namespace std;

int visited[100001];
vector <int> adj[100001];

void dfs(int node){
    visited[node] = 1;
    for(auto x:adj[node]){
        if(visited[x] == 0){
            dfs(x);
        }
    }
}

int solve(int A, vector<vector<int> > &B) {
    for(int i=1;i<=A;i++){
        visited[i] = 0;
        adj[i].clear();
    }
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    dfs(1);
    return visited[A];
}
