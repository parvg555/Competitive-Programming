#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Interesting_XOR_.cpp
#  Created On:      08/03/2021
#  Problem Code:    IRSTXOR
=============================================================================*/


ll powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

vi decToBinary(int n) 
{   
    vi binary;
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            binary.pb(1); 
        else
            binary.pb(0); 
    } 
    return binary;
} 

void sol(){
    ll c;
    cin>>c;
    vi bin = decToBinary(c);
    vi num1;
    vi num2;
    ll start;
    fr(i,bin.size()){
        if(bin[i]==1){
            start = i;
            break;
        }
    }
    //cout<<"Start: ";
    //cout<<start<<"\n";
    bool flag = false;
    for(int i=start;i<32;i++){
        if(bin[i]==1){
            if(flag==false){
                flag=true;
                num1.pb(1);
                num2.pb(0);
            }else{
                num1.pb(0);
                num2.pb(1);
            }
        }else{
            num1.pb(1);
            num2.pb(1);
        }
    }
    ll n1 = 0,n2 = 0;
    ll count=0;
    //cout<<"binary 1: ";
    for(ll i=num1.size()-1;i>=0;i--){
        //cout<<num1[i];
        n1+=num1[i]*powerof2[count];
        count++;
    }
    //cout<<"\nbinary 2: ";
    count=0;
    for(ll i=num2.size()-1;i>=0;i--){
        //cout<<num2[i];
        n2+=num2[i]*powerof2[count];
        count++;
    }
    //cout<<"\n";
    //cout<<"num1: "<<n1<<" num2: "<<n2<<"\n";
    cout<<n1*n2<<"\n";

}

int main(void){
    fast;
    test(t){
        sol();
    }
}