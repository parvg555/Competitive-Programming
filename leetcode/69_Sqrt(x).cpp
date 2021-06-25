#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long end = 2147483647;
        long long mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(mid*mid == x){
                return mid;
            }
            if(mid*mid<x){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return end;
    }
};