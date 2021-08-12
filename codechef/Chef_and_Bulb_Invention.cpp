#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(void){
    int t;
    cin>>t;
    while(t--){
        ll n,p,k;
        cin>>n>>p>>k;
        ll temp1 = n/k;
        ll temp2 = p%k;
        ll ans = temp1*temp2;
        ll rem = n%k;
        if(rem>=(p%k)){
            ans+=p%k;
        }else{
            ans+=rem;
        }
        ans += (p/k) + 1;
        cout<<ans<<"\n";
    }
}