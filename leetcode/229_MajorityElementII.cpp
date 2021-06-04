#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums;
        }
        vector <int> ans;
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }else{
                if (count>floor(n/3)){
                    ans.push_back(nums[i-1]);
                }
                count = 1;
            }
        }
        if(count>floor(n/3)){
            ans.push_back(nums[n-1]);
        }
        return ans;
    }
};