#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                ans = min(ans,i-pos+1);
                sum-=nums[pos];
                pos++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};