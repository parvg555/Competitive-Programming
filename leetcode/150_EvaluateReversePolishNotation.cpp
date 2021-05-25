#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack <int> s;
        for(int i=0;i<token.size();i++){
            if(token[i] == "*" || token[i] == "+" || token[i] == "/" || token[i] == "-"){
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                if(token[i] == "*"){
                    s.push(temp1*temp2);
                }else if(token[i] == "+"){
                    s.push(temp1+temp2);
                }else if(token[i] == "/"){
                    s.push(temp2/temp1);
                }else if(token[i]=="-"){
                    s.push(temp2-temp1);
                }
            }else{
                int num = 0;
                bool flag = true;
                for(int j = 0;j<token[i].length();j++){
                    if(token[i][j] == '-'){
                        flag = false;
                        continue;
                    }
                    num = num*10;
                    int temp = token[i][j]-48;
                    num+=temp;
                }
                cout<<num<<"\n";
                if(flag == false){
                    num = num*-1;
                }
                s.push(num);
            }
        }
        return s.top();
    }
};