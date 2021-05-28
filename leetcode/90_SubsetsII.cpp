#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& nums, set<vector<int>>& s, vector <int>& arr, int start){
        s.insert(arr);
        for(int i=start;i<nums.size();i++){
            arr.push_back(nums[i]);
            backtracking(nums,s,arr,i+1);
            arr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set <vector<int>> s;
        set <vector<int>> s2;
        vector <int> arr;
        s.insert(arr);
        backtracking(nums,s,arr,0);
        for(auto x:s){
            sort(x.begin(),x.end());
            s2.insert(x);
        }
        vector<vector<int>> ans;
        for(auto x: s2){
            ans.push_back(x);
        }
        return ans;
    }
};