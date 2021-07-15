#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> dist (n+1, INT_MAX);
        vector <pair<int,int>> adjlist[n+1];
        for(auto i:flights){
            adjlist[i[0]].push_back(make_pair(i[1],i[2]));
        }
        priority_queue <array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        dist[src] = {0};
        pq.push({0,src,0});
        while(!pq.empty()){
            int u = pq.top()[1];
            int stops = pq.top()[2];
            int cost = pq.top()[0];
            pq.pop();
            if (u==dst){
                return cost;
            }
            if(stops > k){
                continue;
            }
            dist[u] = stops;
            for(auto x:adjlist[u]){
                if(dist[x.first] == INT_MAX || dist[x.first] > stops){
                    pq.push({cost+x.second,x.first,stops+1});
                }
            }   
        }
        return -1;
    }
};