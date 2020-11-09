#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 4000000

vector <ll> primenum;

void primenumbers(){
    bool prime[N+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=N;p++){
        if(prime[p]==true){
            for(int i=p*p;i<N;i+=p){
                prime[i]=false;
            }
        }
    }

    for(int p=2;p<=N;p++){
        if(prime[p]){
            primenum.push_back(p);
        }
    }
}

int main(void){
    primenumbers();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int number;
            cin>>number;
            cout<<primenum[number]<<" ";
        }
        cout<<endl;
    }
}