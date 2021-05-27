#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set <int> s;
        set <int> ans;
        s.insert(0);
        for(int i=0;i<arr.size();i++){
            set <int> temp;
            temp.insert(arr[i]);
            for(auto x:s){
                temp.insert(arr[i]|x);
            }
            s = temp;
            ans.insert(s.begin(),s.end());
        }
        return ans.size();
    }
};