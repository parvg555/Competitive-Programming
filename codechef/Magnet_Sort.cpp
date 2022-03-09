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
    vi arr(n);
    vi arr_temp(n);
    ll N = 0;
    ll S = 0;
    fr(i,n){ 
        cin>>arr[i];
        arr_temp[i] = arr[i];
    }
    string s;
    cin>>s;
    fr(i,n){
        if(s[i]=='N'){
            N++;
        }else{
            S++;
        }
    }
    sort(all(arr_temp));
    ll changes = 0;
    ll start = -1;
    ll end = -1;
    fr(i,n){
        if(arr[i]!=arr_temp[i]){
            if(start == -1){ 
                start=i;
                end = i;
            }else end=i;
            changes++;
        }
    }

    if(changes>0){
        if(N>0 && S>0){
            ll flag = false;
            for(ll i=0;i<=start;i++) if(s[i]!=s[0]) flag=true;
            for(ll i=end;i<n;i++) if(s[i]!=s[0]) flag=true;
            if(flag){
                cout<<1<<"\n";
            }else{
                cout<<2<<"\n";
            }
        }else{
            cout<<"-1\n";
        }
        return;
    }
    cout<<"0\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}