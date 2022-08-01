#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void ans(){
    ll n;
    cin>>n;
    multiset <int> fre;
    long long num1 = 0;
    long long num2 = 0;
    while(n>0){
        fre.insert(n%10);
        n/=10;
    }
    cout<<"\n";
    bool flag = true;
    for(auto i:fre){
        if(flag) num1 = (num1*10)+i;
        else num2 = (num2*10)+i;
        flag=!flag;
    }
    cout<<num1+num2<<"\n";
}

int main(void) {
    ll t;
    cin>>t;
    while(t--) ans();
}