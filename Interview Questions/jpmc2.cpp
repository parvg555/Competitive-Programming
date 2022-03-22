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

long countMax(vector <string> upRight){
    for(auto i:upRight) cout<<i<<"\n";
    long n = upRight.size();
    long x = INT_MAX;
    long y = INT_MAX;
    for(long i=0;i<n;i++){
        string temp1 = "";
        string temp2 = "";
        bool flag = false;
        long sz = upRight[i].length();
        for(long j=0;j<sz;j++){
            if(upRight[i][j]!=' '){
                if(flag) temp2+=upRight[i][j];
                else temp1+=upRight[i][j];
            }else{
                flag = true;
            }
        }
        long tempX = stol(temp1);
        long tempY = stol(temp2);
        x = min(tempX,x);
        y = min(tempY,y);
    }
    long ans = x*y;
    return ans;
}

void sol(){
    ll n = 2;
    vector <string> v;
    fr(i,n){
        string temp;
        getline(cin,temp);
        v.pb(temp);
    }
    cout<<countMax(v)<<"\n";
}

int main(void){
    fast;
    sol();
}