#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int ans = 0;
    int i = 0;
    bool flag = false;
    while(i<A.size()){
        flag = false;
        for(int j=i+B-1;j>i-B && i>=0; j--){
            if(A[j]==1){
                i=j+B;
                ans++;
                flag = true;
            }
        }
        if(flag==false){
            return -1;
        }
    }
    return ans;
}
