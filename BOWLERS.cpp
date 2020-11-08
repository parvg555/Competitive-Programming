#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t>0){
        long long n,k,l;
        cin>>n>>k>>l;
        if(k==1&&n==1){
            cout<<"-1"<<endl;
            continue;
        }else if(k==1&&n>1){
            cout<<"-1"<<endl;
            continue;
        }else if(n>(k*l)){
            cout<<"-1"<<endl;
            continue;
        }else{
            long long count = 0;
            for(int i=0;i<=l;i++){
                for(int j=0;j<=k;j++){
                    if (count>=n){
                        break;
                    }else{
                        cout<<j<<" ";
                        count++;
                    }
                }
            }
        }

        cout<<endl;
        t--;
    }
}