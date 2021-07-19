#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long n = s.size();
        long long ans = 0;
        long long one = 0,zero = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                zero=i+1;
            }
            if(s[i] == '1'){
                one=i+1;
            }
            ans += i - min(one,zero) + 1;
            swap(zero,one);
        }
        cout<<ans<<"\n";
    }
}