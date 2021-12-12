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
    ll ans = 0;
    fr(i,n){ 
        ll temp;
        cin>>temp;
        if(i%2!=0) temp*=-1;
        arr[i] = temp;
        ans+=arr[i];
    } 

    vi right(n);
    vi left(n);
    ll sum = 0;

    for(ll i=n-1;i>=0;i--){
        right[i] = sum + arr[i];
        sum+=arr[i];
    }

    fr(i,n){
        if(i==0) left[i] = 0;
        else if(i<3) left[i] = arr[i-1];
        else left[i] = min(arr[i-1],left[i-2] + arr[i-1] + arr[i-2]);
    }

    for(ll i=1;i<n;i++){
        if((n-i)%2==0) remax(ans,sum-(2*right[i]));
        else remax(ans,sum-(2*right[i]) - (2*left[i]));
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}