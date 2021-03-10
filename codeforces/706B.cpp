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

ll maxcfind(set<ll> arr){
    return *s.rbegin();
}
ll mexfind(set<ll> arr){
    int i=0;
    for(auto x:arr){
        if(x!=i)
            return i;
        i++;
    }
    return find(arr)+1;
}

void sol(){
    ll n,k;
    cin>>n>>k;
    set<ll> arr;
    fr(i,n){
        ll temp;
        cin>>temp;
        arr.insert(temp);
    }
    ll sz=arr.size();
    if(k==0){
        cout<<sz<<endl;
        return;
    }
    
    ll max=maxfind(arr);
    ll mex=mexfind(arr);
    arr.insert(ceil(1.0*(mex+max)/2));
    if(sz!=arr.size()){
        --k;
    }
    sz = arr.size();
    if(sz==maxfind(arr)+1){
        cout<<sz+k<<endl;
        return;
    }
    cout<<sz<<endl;
}
}

int main(void){
    fast;
    test(t){
        sol();
    }
}