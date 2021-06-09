#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int start = -1;
        int end = -1;
        for(int i=0;i<n;i++){
            if(start == -1 && end == -1){
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                if(intervals[i][0]<=end){
                    if(intervals[i][1]>end){
                        end = intervals[i][1];
                    }
                }else{
                    vector <int> temp;
                    temp.push_back(start);
                    temp.push_back(end);
                    ans.push_back(temp);
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
        }
        vector <int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};