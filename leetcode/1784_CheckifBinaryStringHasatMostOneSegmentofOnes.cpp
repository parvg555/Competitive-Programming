#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        int start = false;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                start = true;
            }else{
                if(start == true){
                    start=false;
                    count++;
                }
            }
        }
        if(start == true){
            count++;
        }
        if(count == 1){
            return true;
        }
        return false;
    }
};