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
    ll n,a,b;
    cin>>n>>a>>b;
    if((a+b) <= (n-2) && (abs(a-b) == 1 || abs(a-b) == 0)){
        ll start = 1;
        ll end = n;
        vi ans;
        bool current  = 1;
        if(a>b) current=0;
        for(ll i=1;i<=n;i++){
            if(i==a+b+2){
                if(current) for(ll j=start;j<=end;j++) ans.pb(j);
                else for(ll j=end;j>=start;j--) ans.pb(j);
                break;
            }
            if(!current) ans.pb(start);
            else ans.pb(end);
            if(!current){
                current = 1;
                start++;
            }else{
                current = 0;
                end--;
            }
        }
        fr(i,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }else{
        cout<<"-1\n";
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}