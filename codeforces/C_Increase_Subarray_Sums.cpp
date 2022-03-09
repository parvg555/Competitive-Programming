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

ll maxSum(vi &arr, ll n, ll k){
    ll res = 0;
    for (ll i=0; i<k; i++)
       res += arr[i];
 
    ll curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}

void sol(){
    ll n,x;
    cin>>n>>x;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    ll sums[n+1];
    fr(i,n+1) sums[i] = maxSum(arr,n,i);
    ll last_ans = 0;
    fr(i,n+1){
        ll ans = LONG_LONG_MIN;
        fr(j,n+1){
            ll temp = sums[j] + min(j,i)*x;
            ans = max(ans,temp);
        }
        cout<<max(ans,last_ans)<<" ";
        last_ans = ans;
    }
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}