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
#define inn freopen("traffic_control_input.txt", "r", stdin)
#define outt freopen("traffic_control_output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

void sol(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll ans[n][m];
    fr(i,n){
        fr(j,m){
            ans[i][j] = 1;
        }
    }
    if(m+n-1 > a || m+n-1 > b){
        cout<<"Impossible\n";
        return;
    }else{
        cout<<"Possible\n";
        a-= m+n-1;
        b-= m+n-1;
        ans[0][0]+=a;
        ans[0][m-1]+=b;
    }
    fr(i,n){
        fr(j,m){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

int main(void){
    inn;
    outt;
    fast;
    ll count = 1;
    test(t){
        cout<<"Case #"<<count<<": ";
        sol();
        count++;
    }
}