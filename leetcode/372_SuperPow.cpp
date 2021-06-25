#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int PowerFunction(int a, int b){
        if(a==0){
            return 0;
        }
        int ans = 1;
        for(int i=0;i<b;i++){
            ans = ((long)ans*a)%1337;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0){
            return 0;
        }
        if(b.size() == 1){
            return PowerFunction(a,b[0])%1337;
        }
        int temp = b.back();
        b.pop_back();
        return ((long)PowerFunction(superPow(a,b),10)*(long)PowerFunction(a,temp))%1337;
    }
};