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

map <char,vi> data;

ll mxwdt(string t, ll m, ll pos, ll lastpos){
    auto itr = data.find(t[pos]);
    ll ans = LONG_LONG_MIN;
    for(auto i=0;i<itr->sec.size();i++){
        if(itr->sec[i]>lastpos){
            ll val = mxwdt(t,m,pos+1,itr->sec[i]);
            if(val!=0){
                ans = max(val,ans);
            }
        }else{
            return 0;
        }
    }
    return ans;
}

void sol(){
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t; 
    map <char,vi>::iterator itr;
    fr(i,n){
        data[s[i]].pb(i);
    }
    ll ans = mxwdt(t,m,1,-1);
    cout<<ans<<"\n";
    
}

int main(void){
    fast;
    sol();
}