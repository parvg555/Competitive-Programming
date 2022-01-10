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

ll checkingforA(ll a,ll b, ll c){
    ll d = c-b;
    if(b-d == c-2*d){
        ll A = b-d;
        ll m = A/a;
        if(A == m*a){
            return m;
        }
    }
    return -1;
}

ll checkingforB(ll a, ll b, ll c){
    ll d2 = c-a; 
    ll d = (c-a)/2;
    if(d2%2==0){
        ll B = a + d;
        ll m = B/b;
        if(B == b*m){
            return m;
        }
    }
    return -1;
}

ll checkingforC(ll a, ll b, ll c){
    ll d = b-a;
    if(a == (b-d)){
        ll C = a+2*d;
        ll m = C/c;
        if(C == c*m){
            return m;
        }
    }
    return -1;
}

void sol(){
    ll a,b,c;
    cin>>a>>b>>c;
    //checking for a
    if(checkingforA(a,b,c) > 0){
        // cout<<"multiply a by: "<<checkingforA(a,b,c)<<"\n";
        // cout<<a*checkingforA(a,b,c)<<","<<b<<","<<c<<"\n";
        cout<<"YES\n";
        return;
    }else if(checkingforB(a,b,c) > 0){
        // cout<<"multiply b by: "<<checkingforB(a,b,c)<<"\n";
        // cout<<a<<","<<b*checkingforB(a,b,c)<<","<<c<<"\n";
        cout<<"YES\n";
        return;
    }else if(checkingforC(a,b,c) > 0){
        // cout<<"multiply c by: "<<checkingforC(a,b,c)<<"\n";
        // cout<<a<<","<<b<<","<<c*checkingforC(a,b,c)<<"\n";
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}