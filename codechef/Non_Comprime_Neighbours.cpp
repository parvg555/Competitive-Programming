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
    vi arr(n+1,1);
    fr(i,n) cin>>arr[i];
    bool check = true;
    fr(i,n){
        if(check){
            arr[i] = arr[i+1]*2;
            i++;
        }else{
            arr[i]=arr[i-1]*2;
        }
        check=!check;
    }
    fr(i,n) cout<<arr[i]<<" ";
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}