#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map <string,int> mp;
    static bool comparison(pair<string,int>& i, pair<string,int>& j){
        if(i.second>j.second){
            return true;
        }else if(i.second == j.second){
            vector <string> temp;
            temp.push_back(i.first);
            temp.push_back(j.first);
            sort(temp.begin(),temp.end());
            if(temp[0] == i.first){
                return true;
            }
            return false;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector <pair<string,int>> arr;
        for(auto x:mp){
            arr.push_back(make_pair(x.first,x.second));
        }
        sort(arr.begin(),arr.end(),comparison);
        vector <string> ans;
        int count = 0;
        for(auto x:arr){
            if(count>=k){
                break;
            }
            ans.push_back(x.first);
            count++;
        }
        return ans;
    }
};