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

ll multiplyby(ll n, ll m){
    while(m--){
        n*=2;
    }
    return n;
}

void sol(){
    ll count = 0;
    ll n;
    cin>>n;
    vi arr(n);
    vi arrcopy(n);
    fr(i,n) {cin>>arr[i];arrcopy[i] = arr[i];}
    if(n==1){
        cout<<arr[0]<<"\n";
        return;
    }
    vi arr2(n);
    ll sum = 0; 
    ll total = 0;
    fr(i,n){
        ll count = 0;
        while(arrcopy[i]%2==0){
            count++;
            arrcopy[i]/=2;
        }
        sum+=arrcopy[i];
        arr2[i] = count;
        total+=count;
    }
    ll ans = LONG_LONG_MIN;
    fr(i,n){
        ll tempans = (sum-arrcopy[i]) + multiplyby(arr[i],(total-arr2[i]));
        remax(ans,tempans);
    }   
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}