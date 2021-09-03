#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef int ll;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll count = 1;
    ll t;
    cin>>t;
    while(t--){
        cout<<"Case #"<<count<<": ";
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll res[n];
    for(int i=0;i<n;i++){
        res[i] = 0;
    }
    ll x = -1, o = -1, ans = 0;
    for(ll i=0;i<n;i++){
        if(s[i] == 'X'){
            if(o!=-1) res[i] = (res[o-1] + o)%mod;
            x = i+1;
        }else if(s[i] == 'O'){
            if(x!=-1) res[i] = (res[x-1] + x)%mod;
            o = i+1;
        }else{
            if(i) res[i] = res[i-1];
        }
    }
    for(ll i=0;i<n;i++){
        ans=(ans+res[i])%mod;
    }
    cout<<ans%mod<<"\n";
        count++;
    }
}