#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector <string> ans;
        if(s.length()<10){
            return ans;
        }
        map <string,int> mp;
        for(int i=0;i<s.length()-9;i++){
            string s2 = "";
            for(int j = 0;j<10;j++){
                s2+=s[i+j];
            }
            mp[s2]++;
        }
        for(auto i:mp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};