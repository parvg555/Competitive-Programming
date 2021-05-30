#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        vector <int> rem (k,0);
        int sum = 0;
        for(auto x:nums){
            sum+=x;
            while(sum<0){
                sum+=k;
            }
            if(sum%k==0){
                count++;
            }
            count += rem[sum%k];
            rem[sum%k]++;   
        }
        return count;
    }
};