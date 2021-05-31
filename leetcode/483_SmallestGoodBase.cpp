#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unsigned long long mxn = 1e18;
    string smallestGoodBase(string n) {
        unsigned long long num = stoull(n);
        for(int i=60;i>=2;i--){
            unsigned long long mn = 2;
            unsigned long long mx = num-1;
            while(mn<=mx){
                unsigned long long mid = (mx+mn)/2;
                unsigned long long val = 1;
                unsigned long long j = 1;
                unsigned long long res = 1;
                bool flag = false;
                while(j<i){
                    if(val>(num-res)/mid){
                        flag = true;
                        break;
                    }
                    j++;
                    val*=mid;
                    res+=val;
                }
                if(flag || res>num){
                    mx  = mid-1;
                }else if(res<num){
                    mn = mid+1;
                }else{
                    return to_string(mid);
                }
            }
        }
        return to_string(num-1);
    }
};

//"2251799813685247"