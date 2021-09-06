#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    return A[0] + A[A.size() - 1];
}
