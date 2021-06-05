#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string bin(int n){
        string s2 = "";
        while(n>0){
            if(n%2!=0){
                s2+="1";
            }else{
                s2+="0";
            }
            n = n>>1;
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
    
    static bool isSubstring(string s1, string s2)
    {
        int M = s1.length();
        int N = s2.length();
        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++){
                if (s2[i + j] != s1[j]){
                    break;
                }
            }
            if (j == M){
                return true;
            }
        }
        return false;
    }
    
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            if(isSubstring(bin(i),s) == false){
                return false;
            }
        }
        return true;
    }
};