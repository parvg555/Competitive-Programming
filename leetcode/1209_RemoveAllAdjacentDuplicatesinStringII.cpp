#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> temp;
        for (int i=0;i<s.length();i++){
            if(temp.size()==0){
                temp.push(make_pair(s[i],1));
            }else{
                if(temp.top().first == s[i]){
                    temp.top().second++;
                }else{
                    temp.push(make_pair(s[i],1));
                }
            }
            if(temp.top().second == k){
                temp.pop();
            }
        }
        string ans = "";
        while(!temp.empty()){
            for(int i=0;i<temp.top().second;i++){
                ans+=temp.top().first;
            }
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};