#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        sort(nums.rbegin(),nums.rend());
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                ans+=i;
            }
        }
        return ans;
    }
};