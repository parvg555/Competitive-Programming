#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int num = 0;
        for(int i=0;i<n.length();i++){
            if(n[i]-48>num){
                num = n[i] - 48;
            }
            if(num==9){
                return num;
            }
        }
        return num;
    }
};