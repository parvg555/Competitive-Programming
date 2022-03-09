#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void sol(){
    ll n;
    cin>>n;

    vector< ll > arr(n);

    for(ll i=0;i<n;i++) cin>>arr[i];
    
    
    ll j = 0;
    for(ll i=0;i<n;i++){
        if(arr[i] < 0){
            if(i!=j) swap(arr[i],arr[j]);
            j++;
        }
    }

    for(auto i:arr) cout<<arr[i]<<" ";
    cout<<"\n";

    vector<ll> ans;

    for(ll i=1;i<n;i++){
        if(arr[i] - arr[i-1] > 1){
            if(arr[i] < 0 && arr[i-1] < 0){
                ll sum1 = ((abs(arr[i-1]))*(abs(arr[i-1]-1)))/2;
                ll sum2 = ((abs(arr[i]))*(abs(arr[i]+1)))/2;
                ans.push_back(-1*(sum1-sum2));
            }else if(arr[i] > 0 && arr[i-1] > 0){
                ll sum1 = ((arr[i]-1)*arr[i])/2;
                ll sum2 =  (arr[i-1] * (arr[i-1]+1))/2;
                ans.push_back(sum1-sum2);
            }else{
                ll sum1 = ((abs(arr[i-1]))*(abs(arr[i-1]-1)))/2;
                ll sum2 = (arr[i] * (arr[i] - 1))/2;
                ans.push_back((-1*sum1) + sum2);
            }
        }else{
            ans.push_back(0);
        }
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main(void){
    sol();
}