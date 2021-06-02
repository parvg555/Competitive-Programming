#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        vector <int> ans(1000,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.length();i++){
            int carry = 0;
            int j = 0;
            for(;j<num2.length();j++){
                int x = num1[i] - 48;
                int y = num2[j] - 48;
                int res = ans[i+j] + x*y + carry;
                if(res>9){
                    ans[i+j] = res%10;
                    carry = res/10;
                }else{
                    ans[i+j] = res;
                    carry = 0;
                }
            }
            if(carry>0){
                ans[i+j]+=carry;
            }
        }
        reverse(ans.begin(),ans.end());
        int start = 0;
        for(int i=0;i<1000;i++){
            if(ans[i]!=0){
                start = i;
                break;
            }
        }
        string answer = "";
        for(int i=start;i<1000;i++){
            answer+=ans[i]+48;
        }
        return answer;     
    }
};