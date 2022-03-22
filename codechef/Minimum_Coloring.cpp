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
    ll n,m;
    cin>>n>>m;
    bool ans[n][m];
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    fr(i,n) fr(j,m) ans[i][j]=((i+j)%2==0)?true:false;
    ll true_color, false_color;
    if(ans[a-1][b-1] == ans[c-1][d-1]){
       if(ans[a-1][b-1]){
            true_color=1;
            false_color=3;
        }else{
            true_color=3;
            false_color=2;
        }
    }else{
        if(ans[a-1][b-1]){
            true_color=1;
            false_color=2;
        }else{
            true_color=2;
            false_color=1;
        }
    }
    fr(i,n) {
        fr(j,m) {
            if(i==a-1 && j==b-1) cout<<1<<" ";
            else if(i==c-1 && j==d-1) cout<<2<<" ";
            else{
                if(ans[i][j]) cout<<true_color<<" ";
                else cout<<false_color<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}