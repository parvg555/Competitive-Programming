#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef unsigned long long ll;
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
#  FileName:        Chef_and_Dice.cpp
#  Created On:      04/04/2021
#  Problem Code:    SDICE
=============================================================================*/


void sol(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"20\n";
        return;
    }else if(n==2){
        cout<<"36\n";
        return;
    }else if(n==3){
        cout<<"51\n";
        return;
    }else if(n==4){
        cout<<"60\n";
        return;
    }else{
        ll t = n%4;
        ll b = n-t;
        b = floor(b/4);
        ll total = b*44;
        if(t==0){
            cout<<total+16<<"\n";
            return;
        }else if(t==1){
            cout<<total+32<<"\n";
            return;
        }else if(t==2){
            cout<<total+44<<"\n";
            return;
        }else if(t==3){
            cout<<total+55<<"\n";
            return;
        }
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}