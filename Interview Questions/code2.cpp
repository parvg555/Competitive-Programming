#include<bits/stdc++.h>
using namespace std;

string decrypt(string str){
    string res = "";
    long long n = str.length();
    for(int i=0;i<n;i+=2){
        long long repeat = str[i+1] - '0';
        for(int j=0;j<repeat;j++){
            res+=str[i];
        }
    }
    return res;
}

int main(){
    string str;
    getline(cin,str);
    cout<<decrypt(str);
    return 0;
}