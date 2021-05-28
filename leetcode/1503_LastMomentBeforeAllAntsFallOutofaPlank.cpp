#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(),left.end());
        reverse(left.begin(),left.end());
        sort(right.begin(),right.end());
        if(left.size()>0 && right.size()>0){
            return max(left[0],n-right[0]);
        }else if(left.size()==0){
            return n-right[0];    
        }
        return left[0];
    }
};