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
    ll p,a,b,c;
    cin>>p>>a>>b>>c;
    if(a<p){
        a= a+a*(p/a);
    }
    if(b<p){
        b=b+b*(p/b);
    }
    if(c<p){
        c=c+c*(p/c);
    }
    
    ll ans = LONG_LONG_MAX;

    if(a-p < ans){
        ans = a-p;
    }
    if(b-p < ans ){
        ans = b-p;
    }
    if(c-p < ans ){
        ans = c-p;
    }
    cout<<ans<<"\n";

}

int main(void){
    fast;
    test(t){
        sol();
    }
}