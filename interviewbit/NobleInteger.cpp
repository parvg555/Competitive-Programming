#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    map <int,int> mp;
    int n = A.size();
    for(int i =0;i<n;i++){
        mp[A[i]]++;
    }
    int sum = n;
    for(auto i:mp){
        sum = sum - i.second;
        mp[i.first] = sum;
    }
    for(auto i:mp){
        //cout<<i.first<<" "<<i.second<<"\n";
        if(i.first == i.second){
            return 1;
        }
    }
    return -1;
}

