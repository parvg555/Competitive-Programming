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
    ll w,h;
    cin>>w>>h;
    ll k;
    cin>>k;
    vi side1(k);
    fr(i,k) cin>>side1[i];
    ll l;
    cin>>l;
    vi side2(l);
    fr(i,l) cin>>side2[i];
    ll m;
    cin>>m;
    vi side3(m);
    fr(i,m) cin>>side3[i];
    ll n;
    cin>>n;
    vi side4(n);
    fr(i,n) cin>>side4[i];
    sort(all(side1));
    sort(all(side2));
    sort(all(side3));
    sort(all(side4));
    ll area1 = (side1[k-1] - side1[0]) * h;
    ll area2 = (side2[l-1] - side2[0]) * h;
    ll area3 = (side3[m-1] - side3[0]) * w;
    ll area4 = (side4[n-1] - side4[0]) * w;
    cout<<max(area1,max(area2,max(area3,area4)))<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}