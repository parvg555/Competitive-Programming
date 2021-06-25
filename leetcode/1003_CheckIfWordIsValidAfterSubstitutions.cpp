#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> temp;
        for(int i = 0;i<s.length();i++){
            temp.push(s[i]);
            if(temp.size()<3){
                continue;
            }
            if(temp.top() == 'c'){
                temp.pop();
                if(temp.top() == 'b'){
                    temp.pop();
                    if(temp.top() == 'a'){
                        temp.pop();
                    }else{
                        temp.push('b');
                        temp.push('c');
                    }
                }else{
                    temp.push('c');
                }
            }
        }
        if(temp.size()>0){
            return false;
        }
        return true;
    }
};