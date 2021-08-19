#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int end = B-1;
    int sum = 0;
    for(int i=0;i<B;i++){
        sum+=A[i];
    }
    int ans = sum;
    for(int i=0;i<B;i++){
        sum-=A[end];
        end--;
        sum+=A[n-i-1];
        ans = max(sum,ans);
    }
    return ans;
}
