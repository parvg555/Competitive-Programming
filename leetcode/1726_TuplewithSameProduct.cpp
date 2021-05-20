#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k)
            k = n - k;
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map <int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto i:mp){
            if(i.second > 1){
                ans+= binomialCoeff(i.second,2);
            }
        }
        return 8*ans;
    }
};