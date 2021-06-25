#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    vector <int> arr;
    while(t--){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int ans = 0;
    for(int i=1;i<arr.size();i++){
        int left = arr[i];
        int right = arr[i];
        for(int j=0;j<i;j++){
            left=max(left,arr[j]);
        }
        for(int j=i+1;j<arr.size;j++){
            right = max(right,arr[j]);
        }
        ans+=min(left,right)-arr[i];
    }
    cout<<ans<<"\n";
}