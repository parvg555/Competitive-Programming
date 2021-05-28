#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> ans;
        int var = 0;
        for(int i=0;i<nums.size();i++){
            var+=nums[i];
            ans.push_back(var);
        }
        return ans;
    }
};