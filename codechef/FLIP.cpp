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
#  FileName:        FLIP.cpp
#  Created On:      22/11/2020
=============================================================================*/


bool check(char a, char b){
    if (a==b){
        return true;
    }
    return false;
}

void sol(){
    string a,b;
    cin>>a>>b;
    ll count = 0;
    bool var = false;
    ll change = a.size();
    for(ll i = 0;i<a.size();i++){
        if(!check(a[i],b[i])){
            change = i;
            break;
        }
    }
    for(ll i=change;i<a.size();i+=2){
        if(var && check(a[i],b[i])){
            var = false;
        }else if(!check(a[i],b[i]) && !var){
            count++;
            var = true;
        }
    }
    var  = false;
    for(ll i=(change+1);i<a.size();i+=2){
        if(var && check(a[i],b[i])){
            var = false;
        }else if(!check(a[i],b[i]) && !var){
            count++;
            var = true;
        }
    }
    cout<<count<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}