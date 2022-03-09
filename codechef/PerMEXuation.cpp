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
    string s;
    cin>>s;
    
    if(s[0]!='1'||s[1]!='1'|| s[n]!='1'){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";

    vi ans(n);
    ans[0] = 0;

    vi temp1;
    vi temp2;

    for(ll i=1;i<n;i++){
        if(s[i] == '0'){
            temp1.pb(i);
        }else{
            temp2.pb(i);
        }
    }

    ll start = 1;
    for(auto i:temp1){
        ans[start] = i;
        start++;
    }
    for(auto i:temp2){
        ans[start]=i;
        start++;
    }  

    fr(i,n) cout<<ans[i]<<" ";
    cout<<"\n";

}

int main(void){
    fast;
    test(t){
        sol();
    }
}