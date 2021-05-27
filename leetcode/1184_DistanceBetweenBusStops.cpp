#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int d1 = 0;
        for(int i=start;i!=destination;i = (i+1)%n){
            cout<<i<<" ";
            d1+=distance[i];
        }
        cout<<"\n";
        int d2 = 0;
        for(int i=start;i!=destination;){
            i--;
            if(i<0){
                i=n-1;
            }
            cout<<i<<" ";
            d2+=distance[i];
        }
        return min(d1,d2);
    }
};