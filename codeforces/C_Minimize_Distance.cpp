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
    ll n,k;
    cin>>n>>k;
    vi negative;
    vi positive;
    fr(i,n){
        ll temp;
        cin>>temp;
        if(temp>0) positive.pb(temp);
        else negative.pb(abs(temp));
    }
    sort(all(positive));
    sort(all(negative));
    reverse(all(positive));
    reverse(all(negative));
    priority_queue <ll,vi,greater<ll>> q;
    ll step = 0;
    ll possize = positive.size();
    ll negsize = negative.size();
    for(ll i=0;i<possize;i++){
        if(step ==0) q.push(positive[i]);
        step++;
        if(step == k) step=0;
    }
    step = 0;
    for(ll i=0;i<negsize;i++){
        if(step ==0) q.push(negative[i]);
        step++;
        if(step == k) step=0;
    }
    ll last_Step = 0;
    ll ans = 0;
    while(!q.empty()){
        ans+=2 * q.top();
        last_Step = q.top();
        q.pop();
    }
    cout<<ans - last_Step<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}