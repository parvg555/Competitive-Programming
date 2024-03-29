#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Prime_Game.cpp
#  Created On:      11/02/2021
#  Problem Code:    PRIGAME
=============================================================================*/
const int mxn = 1e6+6;

bool prime[mxn];
int prime_before[mxn];

void sieve(){
    for(ll p=2;p*p<=mxn;p++){
        if(prime[p]==false){
            for(ll i=p*p;i<=mxn;i+=p){
                prime[i]=true;
            }
        }
    }
}

void primes(){
    int count = 0;
    for(int i=2;i<=mxn;i++){
        if(prime[i]==false){
            count++;
        }
        prime_before[i]=count;
    }
}

void sol(){
    ll x,y;
    cin>>x>>y;
    if(y==1){
        if(x>2){
            cout<<"Divyam\n";
            return;
        }else{
            cout<<"Chef\n";
            return;
        }
    }else{
        //cout<<"prime counter: "<<prime_counter[x]<<endl;
        if(prime_before[x]>y){
            cout<<"Divyam\n";
            return;
        }else{
            cout<<"Chef\n";
            return;
        }
    }
    return;
}

int main(void){
    //auto start = high_resolution_clock::now();
    fast;
    sieve();
    primes();
    prime_before[0] = 0;
    prime_before[1] = 0;
    test(t){
        sol();
    }
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}