#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map <ll, int> mp;
        int maximum = 0;
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            mp[temp]++;
            maximum = max(maximum,mp[temp]);
        }
        int ans = 0;
        if(n<=2){
            ans = 0;
        }else{
            ans = min(n-maximum, n-2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}