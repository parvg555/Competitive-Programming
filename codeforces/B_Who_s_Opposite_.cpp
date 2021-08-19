#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(abs(a-b) == 1 && max(a,b) != 2){
            cout<<"-1\n";
            continue;
        }
        int size = abs(a-b)*2;
        
        if(c>size){
            cout<<"-1\n";
        }else if(b>size || a>size){
            cout<<"-1\n";
        }else if(c>abs(b-a)){
            cout<<c-abs(b-a)<<"\n";
        }else{
            cout<<c+abs(b-a)<<"\n";
        }
    }
}