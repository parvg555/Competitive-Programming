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
#define vi vector< int >
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


int power(long long x, unsigned int y, int p=1000000007)
{
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

vector <int>  solution(int n, int q, vector <int> arr, vector <int> left, vector <int>  right){
    vector <int> ans(q);
    vector <int> sums(n+1),squares(n+1), cubes(n+1);
    int MOD = 1000000007;
    for(int i=0;i<n;i++){
        sums[i+1] = arr[i];
        squares[i+1] = power(arr[i],2);
        cubes[i+1] = power(arr[i],3);
    }
    sums[0] = 0;
    squares[0] = 0;
    cubes[0] = 0;
    for(int i=1;i<=n;i++){
        sums[i] = (sums[i] + sums[i-1])%MOD;
        squares[i] = (squares[i] + squares[i-1])%MOD;
        cubes[i] = (cubes[i] + cubes[i-1])%MOD;
    }
    for(int i=0;i<q;i++){
        int start = left[i];
        int end = right[i];
        int sigma1 = sums[end] - sums[start-1];
        int sigma2 = squares[end] - squares[start-1];
        int sigma3 = cubes[end] - cubes[start-1];
        int tempAns = (power(sigma1,3) - (3*sigma1*sigma2)%MOD + (2*sigma3)%MOD)%MOD;
        ans[i] = tempAns/6;
    }
    return ans;
}

void sol(){
    ll n,q;
    cin>>n>>q;
    vi arr(n),left(q),right(q);
    fr(i,n) cin>>arr[i];
    fr(i,q) cin>>left[i];
    fr(i,q) cin>>right[i];
    vi ans = solution(n,q,arr,left,right);
    fr(i,q) cout<<ans[i]<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}