#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    int count = 0;
    vector <int> arr;
    for(int i=0;count<1001;i++){
        if(i%3!=0 && i%10!=3){
            arr.push_back(i);
            count++;
        }
    }
    while(t--){
        int k;
        cin>>k;
        cout<<arr[k-1]<<"\n";
    }
}