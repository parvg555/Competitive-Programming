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

void sol(){
    ll n;
    cin>>n;
    vi arr(n);
    vi arr_copy(n);
    fr(i,n){ 
        cin>>arr[i];
        arr_copy[i] = arr[i];
    }
    sort(all(arr_copy));
    ll ans = 0;
    for(ll start = n-1;start > 0;){
        if(arr[start] != arr_copy[start]){
            ll mx = arr_copy[start];
            ll mn = arr[start];
            ll i;
            for(i = start;i>0;){
                if(arr[i] != arr_copy[start]) i--;
                else break;
                remin(mn,arr[i]);
            }
            ll pos = lower_bound(all(arr_copy),mn) - arr_copy.begin();
            for(ll j = pos;j<i;j++) remin(mn,arr[j]);
            while(arr_copy[pos] != mn){
                pos = lower_bound(all(arr_copy),mn)-arr_copy.begin();
                for(ll j = pos;j<i;j++) remin(mn,arr[j]);
            }
            ans+=mx-mn;
            start = pos - 1;

        }else{
            start--;
        }
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}