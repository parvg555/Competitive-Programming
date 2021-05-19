#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> temp;
        vector <int> temp2;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(temp.size()>0 && s[i] == ')' && s[temp.top()] == '('){
                temp2.push_back(temp.top());
                temp.pop();
                temp2.push_back(i);
            }else{
                temp.push(i);
            }
        }
        sort(temp2.begin(),temp2.end());
        int count = 1;
        for(int i=1;i<temp2.size();i++){
            cout<<temp2[i]<<" ";
            if(temp2[i-1] == temp2[i] - 1){
                count++;
            }else{
                ans = max(ans,count);
                count = 1;
            }
        }
        ans = max(count,ans);
        if(ans%2!=0){
            return 0;
        }
        return ans;
    }
};