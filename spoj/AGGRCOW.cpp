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
    ll n,c;
    cin>>n>>c;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    sort(all(arr));
    ll low = 0;
    ll high = arr[n-1];
    ll ans = LONG_LONG_MIN;
    while(high>=low){
        ll mid = (high+low)/2;
        bool flag = false;
        ll cows = 1;
        ll pos = arr[0];
        rep(i,1,n-1) if(arr[i] - pos >= mid){
            pos = arr[i];
            cows++;
            if(cows == c){
                flag = true;
                break;
            }
        }
        if(flag == true){
            low = mid+1;
            ans = max(ans,mid);
        }else{
            high = mid-1;
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