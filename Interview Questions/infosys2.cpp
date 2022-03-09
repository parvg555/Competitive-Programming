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


int Solution(int n, vi arr){
    int ans = 0;
    for(int i=0;i<n;i++){
        long long temp = ceil((double)sqrt(arr[i]));
        for(long long j=1;j<temp;j++){
            ll Asq = pow(j,2);
            ll Bsq = arr[i] - Asq;
            ll B = sqrt(Bsq);
            if(B*B == Bsq && Asq > 0){
                ans++;
                break;
            } 
        }
    }
    return ans;
}

void sol(){
    ll n;
    cin>>n;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    cout<<Solution(n,arr)<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}