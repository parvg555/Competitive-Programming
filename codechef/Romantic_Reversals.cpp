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
    string s;
    cin>>s;
    string temp = "";
    fr(i,k) temp+=s[i];
    string ans2 = "";
    for(ll i=k;i<n;i++) ans2+=s[i];
    // cout<<temp<<"\n"<<ans2<<"\n";
    string ans1 = "";
    ll pos1 = 0;
    ll pos2 = temp.size()-1;
    ll sz = temp.size();
    fr(i,sz/2){
        ans1 += temp[pos1];
        ans1 += temp[pos2];
        pos1++;
        pos2--;
    }
    if(sz%2!=0){
        ans1 += temp[sz/2];
    }
    reverse(all(ans1));
    cout<<ans1+ans2<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}