#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
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
    ll n,k;
    cin>>n>>k;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    if(k==1 || k==0 || n==1) {cout<<"0\n";return;}
    ll ugliness = 0;
    for(ll i=1;i<n;i++){
        if(arr[i]!=arr[i-1]) ugliness++;
    }
    map<ll,ll> mp;
    ll right = 0,left =0;
    ll current = arr[0];
    for(ll i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            right = arr[i];
            if(right==left) mp[current]+=2;
            else mp[current]++;
            current = arr[i];
            left = arr[i-1];
        }
    }
    mp[current]++;
    for(ll i=1;i<=k;i++){
        cout<<ugliness-mp[i]<<" ";
    }
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}