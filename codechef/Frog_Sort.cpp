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
#define inn freopen("output.txt", "r", stdin)
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
#  FileName:        FROGS
#  Created On:      07/02/2021
=============================================================================*/

void sol(){
    ll n;
    cin>>n;
    vi pos;
    vi weight;
    fr(i,n){
        ll temp;
        cin>>temp;
        weight.pb(temp);
    }
    fr(i,n){
        ll temp;
        cin>>temp;
        pos.pb(temp);
    }
    vector <tuple<ll,ll,ll>> arr;
    fr(i,n){
        arr.pb(make_tuple(weight[i],pos[i],i));
    }
    sort(all(arr));
    ll ans = 0;
    ll last = get<2>(arr[0]);
    for(ll i = 1;i<n;i++){
        ll pos = get<2>(arr[i]);
        ll jump = get<1>(arr[i]);
        while(pos<=last){
            pos +=jump;
            ans++;
        }
        last = pos;
    }
    cout<<ans<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}
