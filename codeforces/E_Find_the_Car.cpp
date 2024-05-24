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

ll findTime(vi a, vi b, ll p){
    int len = a.size();
    ll min = 0;
    ll max = len-1;

    while(min <= max){
        ll mid = (max+min)/2;
        if(a[mid] > p){
            max = mid -1;
        }else{
            min = mid + 1;
        }
    }
    max++;
    double speed = ((double)(a[max] - a[max-1])/ (double)(b[max] - b[max-1]));
    double time = (double)(p-a[max-1])/(double)speed;
    ll ans = floor(time) + b[max-1];
    return ans;
}

void sol(){
    ll n,k,q;
    cin>>n>>k>>q;
    vi a(k+1),b(k+1);
    fr(i,k) cin>>a[i+1];
    fr(i,k) cin>>b[i+1];
    fr(i,q){
        ll p;
        cin>>p;
        cout<<findTime(a,b,p)<<" ";
    }
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}