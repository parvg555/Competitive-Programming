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

ll primeFactors(ll n) 
{ 
    set <ll> primecount;
    while (n % 2 == 0) 
    { 
        primecount.insert(2);
        n = n/2; 
    } 
    for (ll i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            primecount.insert(i);
            n = n/i; 
        } 
    } 
    if (n > 2) 
        primecount.insert(n);
    return primecount.size();
}

ll findmax(ll n,ll k){
    ll ans;
    ll maxi = 1;
    for(ll i=1;i<=k;i++){
        if(n%i==0){
            maxi = max(maxi,i);
        }
    }
    ans = n/maxi;
    return ans;
}

void sol(){
    ll n,m;
    cin>>n>>m;
    ll mxn = primeFactors(m);
    if(mxn == 0){
        cout<<"0\n";
        return;
    }
    ll ans = findmax(n,mxn);
    cout<<n/ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}