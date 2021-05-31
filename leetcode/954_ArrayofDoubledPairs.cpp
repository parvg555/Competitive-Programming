#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static comparison(int a, int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        map <int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        sort(arr.begin(),arr.end(),comparison);
        for(auto i:arr){
            if(mp[i]!=0){
                if(mp[2*i]<1){
                    return false;
                }
                mp[i]--;
                mp[2*i]--;   
            }
        }
        return true;
    }
};