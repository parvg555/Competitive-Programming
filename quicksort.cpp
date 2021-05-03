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
#  FileName:        quicksort.cpp
#  Created On:      12/03/2021
#  Problem Code:    quicksort
=============================================================================*/


ll partition(ll arr[], ll s, ll e){
    ll index = s;
    ll pivot = arr[e];
    for(ll i=s;i<e;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[index]);
            index++;
        }
    }
    swap(arr[index],arr[e]);
    return index;
}


void quicksort(ll arr[], ll s, ll e){
    if(s<e){
        ll bp = partition(arr,s,e);
        quicksort(arr,s,bp-1);
        quicksort(arr,bp+1,e);
    }
}

void sol(){
    ll n;
    cin>>n;
    ll arr[n];
    fr(i,n){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    fr(i,n){
        cout<<arr[i]<<",";
    }
    cout<<"\n";
}

int main(void){
    fast;
    sol();
}