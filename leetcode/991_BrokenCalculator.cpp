#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int x, int y) {
        int ans = 0;
        if(x!=y){
            if(y<x){
                return abs(x-y);
            }else{
                while(x!=y){
                    if(y<x){
                        ans+=abs(x-y);
                        x=y;
                    }else if(y%2==0){
                        y=y/2;
                        ans++;
                    }else{
                        y=y+1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};