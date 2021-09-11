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

ll sol(){
    ll d,n,k;
    cin>>d>>n>>k;
    vvi arr;
    fr(i,n){
        vi temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        arr.pb(temp);
    }
    sort(arr.rbegin(),arr.rend());
    ll ans = 0;
    for(ll i=1;i<=d;i++){
        ll tempans = 0;
        ll count = 0;
        for(ll j=0;j<n;j++){
            if(arr[j][1] <= i && arr[j][2] >= i && count< k){
                tempans+=arr[j][0];
                count++;
            }
        }
        ans = max(ans,tempans);
    }
    return ans;
}

int main(void){
    fast;
    ll count = 1;
    test(t){
        cout<<"Case #"<<count<<": "<<sol()<<"\n";
        count++;
    }
}