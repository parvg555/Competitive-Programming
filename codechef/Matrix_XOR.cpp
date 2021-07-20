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
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans = 0;
    ll small = min(n,m);
    ll num1 = 0;
    ll num2 = n+m+2;
    for(ll i=0;i<small;i+=2){
        num1+=2;
        //cout<<num1<<" ";
        ans = ans^(k+num1);
    }

    for(ll i = 0;i<small;i+=2){
        num2-=2;
        //cout<<num2<<" ";
        if(num2>num1){
            ans = ans^(k+num2);
        }
        
    }
    //cout<<"num1: "<<num1<<"\n";
    //cout<<"num2: "<<num2<<"\n";
    if(n!=m && small%2!=0){
        for(ll i=num1+1;i<num2;i++){
            //cout<<i<<" ";
            ans = ans^(k+i);
        }
    }
    //cout<<"\n";
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}