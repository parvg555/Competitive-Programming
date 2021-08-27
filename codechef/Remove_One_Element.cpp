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
    vi arr;
    vi arr2;
    ll sum1 = 0;
    ll sum2 = 0;
    fr(i,n){
        ll temp;
        cin>>temp;
        sum1+=temp;
        arr.pb(temp);
    }
    fr(i,n-1){
        ll temp;
        cin>>temp;
        sum2+=temp;
        arr2.pb(temp);
    }
    sort(all(arr));
    sort(all(arr2));
    if(n==2){
        ll ans1 = arr2[0] - arr[0];
        ll ans2 = arr2[0] - arr[1];
        if(min(ans1,ans2) > 0){
            cout<<min(ans1,ans2)<<"\n";
        }else{
            cout<<max(ans1,ans2)<<"\n";
        }
    }else{
        ll ans = LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr2[0] - arr[1] == arr2[1] - arr[2]){
                    if(arr2[0] - arr[1] > 0){
                        ans = min(ans,arr2[0] - arr[1]);
                    }
                }
            }else if(i==n-1){
                if(arr2[n-2] - arr[n-2] == arr2[n-3] - arr[n-3]){
                    if(arr2[n-2] - arr[n-2] > 0){
                        ans = min(ans,arr2[n-2] - arr[n-2]);
                    }
                }
            }else{
                if(arr2[0] - arr[0] == arr2[n-2] - arr[n-1]){
                    if(arr2[0] - arr[0]  > 0){
                        ans = min(ans, arr2[0] - arr[0]);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}