#include<bits/stdc++.h>
using namespace std;


int main(void){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x>y){
            //cout<<abs(x-y)<<endl;
            //int a,b;
            if(abs(x-y)%2==0){
                cout<<"1"<<endl;
            }else{
                cout<<"2"<<endl;
            }
        }else if(x<y){
            //cout<<abs(x-y)<<endl;
            if(abs(x-y)%2){
                cout<<"1"<<endl;
            }else if(abs(x-y)%2==0 && (abs(x-y) / 2) % 2){
                cout<<"2"<<endl;
            }else{
                cout<<"3"<<endl;
            }
        }else{
            cout<<"0"<<endl;
        }
    }
}