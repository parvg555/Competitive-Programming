#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int sum = 0;
    int sum2 = INT_MIN;
    for(int i =0;i<A.size();i++){
        sum += A[i];
        sum2 = max(sum,sum2);
        if(sum<0) sum=0;
    }
    return sum2;
}
