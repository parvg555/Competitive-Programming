#include<bits/stdc++.h>
using namespace std;

int numberofbox(int n,int k,int s){
    int remaining_chocolates = 0;
    int bought = 0;
    if(n<k){
        return -1;
    }
    for(int i=0;i<s;i++){
        if(i%7 == 6 && remaining_chocolates < k){
            return -1;
        }

        if(remaining_chocolates < k){
            remaining_chocolates +=n;
            bought +=1;
        }
        remaining_chocolates -=k;

        if(remaining_chocolates<k && i%7==5 && i+1!=s && bought<=i){
            remaining_chocolates+=n;
            bought++;
        }

    }

    return bought;
}


int main(void){
    int t;
    cin>>t;
    while(t--){
        int n,k,s;
        cin>>n>>k>>s;
        int ans = numberofbox(n,k,s);
        cout<<ans<<endl;
    }
}