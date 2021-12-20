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
    ll a,s;
    cin>>a>>s;
    vi A,S;
    while(a>0){
        A.pb(a%10);
        a/=10;
    }
    while(s>0){
        S.pb(s%10);
        s/=10;
    }
    ll b = 0;
    ll n = A.size();
    ll m = S.size();
    ll pos = 0;
    vi B;
    for(ll i=0;i<n;i++){
        if(pos>=m) {
            cout<<"-1\n";
            return;
        }
        if(A[i] > S[pos]){
            ll temp = S[pos];
            pos++;
            if(pos>=m || S[pos] != 1) {
                cout<<"-1\n";
                return;
            }
            temp = (S[pos]*10) + temp;
            B.pb(temp-A[i]);
        }else{
            ll temp = S[pos];
            B.pb(temp - A[i]);
        }
        pos++;
    }
    while(pos<m){
        B.pb(S[pos]);
        pos++;
    }
    n = B.size();
    for(ll i = n-1;i>=0;i--){
        b = (b*10) + B[i];
    }
    cout<<b<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}