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
    ll n,m;
    cin>>n>>m;

    map <ll,ll> m1;
    fr(i,n){
        ll temp;
        cin>>temp;
        m1[temp%m]++;
    }
    ll ans = 0;
    if(m1[0]>0){
        ans++;
    }
    for(ll i=1;i<=m/2;i++){
        if(i==(m-i)){
            //cout<<"i: "<<i<<"\n";
            if(m1[i]!=0){
                m1[i]=0;
                ans++;
            }
        }else{
            ll min1 = min(m1[i],m1[m-i]);
            //cout<<"min1: "<<min1<<"\n";
            m1[i]-=min1;
            m1[m-i]-=min1;
            if(m1[i]>0 && min1>0){
                m1[i]--;
            }else if(m1[m-i]>0 && min1>0){
                m1[m-i]--;
            }

            if(min1>0){
                ans++;
            }
        }
    }
    //cout<<"ans: "<<ans<<"\n";
    for(auto x:m1){
        //cout<<x.fi<<" "<<x.sec<<"\n";
        if(x.fi!=0){
            ans+=x.sec;
        }
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}