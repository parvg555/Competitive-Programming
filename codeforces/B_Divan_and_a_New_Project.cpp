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

bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.first > b.first;
}

void sol(){
    ll n;
    cin>>n;
    vpi mp;
    for(ll i=0;i<n;i++){
        ll temp;
        cin>>temp;
        mp.pb(pair<ll,ll>(temp,i+1));
    }
    sort(all(mp),cmp);
    ll ans[n+1];
    ans[0] = 0;
    ll time = 0;
    ll current = 1;
    for(auto i:mp){
        //cout<<itr.fi<<" "<<itr.sec<<"\n";
        ans[i.second] = current;
        time += (i.first*2*abs(current));
        if(current >0 ){
            current *=-1;
        }else{
            current *=-1;
            current++;
        }
    }
    cout<<time<<"\n";
    fr(i,n+1){
        cout<<ans[i]<<" ";
    }  
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}