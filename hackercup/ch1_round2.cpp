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
#define inn freopen("weak_typing_chapter_1_input.txt", "r", stdin)
#define outt freopen("output_ch1_round2.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

ll sol(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1) return 0;
    ll ans = 0;
    char last = 'P';
    fr(i,n){
        if(s[i] != 'F'){
            if(last == 'P'){
                last = s[i];
            }else if(last != s[i]){
                last = s[i];
                ans++;
            }
        }
    }
    return ans;
}

int main(void){
    inn;
    outt;
    fast;
    ll count = 1;
    test(t){
        cout<<"Case #"<<count<<": "<<sol()<<"\n";
        count++;
    }
}