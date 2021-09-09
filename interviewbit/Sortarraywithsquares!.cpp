#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    int n = A.size();
    multiset <int> s;
    for(int i=0;i<n;i++){
        s.insert(A[i]*A[i]);
    }
    vector <int> ans;
    for(auto i:s){
        ans.push_back(i);
    }
    return ans;
}

