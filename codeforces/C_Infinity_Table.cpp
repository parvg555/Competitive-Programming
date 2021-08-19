#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long r2 = sqrt(n);
        long long r1 = ceil((double) sqrt(n)); 
        r2*=r2;
        if(n-r2 == 0 ){
            cout<<r1<<" "<<1<<"\n";
        }else if(n-r2<=r1){
            cout<<n-r2<<" "<<r1<<"\n";
        }else{
            cout<<r1<<" "<<(r1*r1) - n + 1<<"\n"; 
        }
    }
}