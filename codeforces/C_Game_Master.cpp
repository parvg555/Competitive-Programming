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
    vi map1(n);
    vi map2(n);
    fr(i,n) cin>>map1[i];
    fr(i,n) cin>>map2[i];
    priority_queue <pii> g;
    fr(i,n){
        g.push(mp(map1[i],i));
        g.push(mp(map2[i],i));
    }
 
    ll b1 = -1;
    ll b2 = -1;
    ll temp1 = -1;
    ll temp2 = -1;
 
    fr(i,n){
        if(map1[i] > b1){
            b1 = map1[i];
            temp2 = map2[i];
        }
        if(map2[i] > b2){
            b2 = map2[i];
            temp1 = map1[i];
        }
    }
 
    string ans = "";
    fr(i,n) ans+='0';
 
 
    while(!g.empty()){
        pii temp = g.top();
        ll pos = temp.sec;
        if(map1[pos] >= temp1 || map2[pos] >= temp2){
            ans[pos] = '1';
            remin(temp1,map1[pos]);
            remin(temp2,map2[pos]);
        }
        g.pop();
    }
    cout<<ans<<"\n";
}
 
int main(void){
    fast;
    test(t){
        sol();
    }
}




