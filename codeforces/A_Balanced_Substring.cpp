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
    string s;
    cin>>s;
    if(n==1){
        cout<<"-1 -1"<<"\n";
        return;
    }
    ll l = 0;
    ll r = n-1;
    ll a = 0;
    ll b = 0;
    fr(i,n){
        if(s[i] == 'a'){
            a++;
        }else{
            b++;
        }
    }
    while(a!=b && l!=r && l<r){
        if(s[l] == 'a' && a>b){
            l++;
            a--;
        }else if(s[l] == 'b' && b>a){
            l++;
            b--;
        }else if(s[r] == 'a' && a>b){
            r--;
            a--;
        }else if(s[r] == 'b' && b>a){
            r--;
            b--;
        }else if(s[l] == 'a'){
            l++;
            a--;
        }else{
            l++;
            b--;
        }
    }
    if(l!=r && l<r){
        cout<<l+1<<" "<<r+1<<"\n";
    }else{
        cout<<"-1 -1\n";
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}