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
    string s;
    cin>>s;
    ll size = s.length();
    for(ll i = size-1;i>=0;i--){
        ll num1 = s[i] - '0';
        ll num2 = s[i+1] - '0';
        ll sum = num1+num2;
        if(sum>9){
            ll temp1 = sum%10;
            ll temp2 = sum/10;
            s[i+1] = temp1 + '0';
            s[i] = temp2 + '0'; 
            cout<<s<<"\n";
            return;
        }
    }
    ll sum = s[0]-'0' + s[1] - '0';
    s[1] = (sum+'0');
    cout<<s.substr(1,s.size() -1)<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}