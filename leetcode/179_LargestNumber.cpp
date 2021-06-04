#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparison(string a, string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector <string> temp;
        for(auto x:nums){
            temp.push_back(to_string(x));   
        }
        sort(temp.begin(),temp.end(),comparison);
        string ans = "";
        for(auto x:temp){
            ans+=x;
        }
        if(temp[0] == "0"){
            return "0";
        }
        return ans;
    }
};