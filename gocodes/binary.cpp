#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009

long long powerof2 [] ={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};


int powmod(int n,int m){
    int pro = 1;
    for(int i= 0;i<m;i++){
        pro = (pro*n)%mod;
    }
    return pro;
}

int ncr(int n, int k) 
{ 
    int res = 1; 
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) { 
        res =(res*(n - i))%mod; 
        res /= (i + 1); 
    } 
    return res; 
} 

int main(void){
    //generating sieve
    bool prime[1e6+6];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    //counting non prime values
    int nonprime[1e6+6];
    int count = 0;
    for(int i=1;i<1000006;i++){
        if(!prime[i]){
            count++;
        }
        nonprime[i]=count;
    }
    //taking input
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int jars = nonprime[m];
        int sols = 0;
        for(int i=1;i<n;i++){
            sols = (sols+ncr(jars,i))%mod;
        }
        cout<<sols<<"\n";
    }
}