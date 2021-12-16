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
    bool check[n+1];
    fr(i,n+1) check[i] = false;
    fr(i,n){ 
        ll temp;
        cin>>temp;
        if(temp<=n && check[temp]==false) check[temp] = true;
        else arr.pb(temp);
    }
    vi missing;
    fr(i,n+1) if(i > 0 && check[i] == false) missing.pb(i);
    sort(all(arr));
    sort(all(missing));
    ll ans = 0;
    ll m = missing.size();
    for(ll i=0;i<m;i++){
        if(arr[i] > missing[i] && (arr[i] - missing[i]) > (arr[i]/2)) ans++;
        else{
            cout<<"-1\n";
            return;
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