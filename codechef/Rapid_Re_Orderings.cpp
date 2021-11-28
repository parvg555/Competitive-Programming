#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
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
    if(n==1){
        ll temp1, temp2;
        cin>>temp1>>temp2;
        if(temp1 == temp2){
            cout<<temp1<<"\n";
            return;
        }
        cout<<"-1\n";
        return;
    }
    bool flag = true;
    map <ll,ll> mp;
    fr(i,2*n){
        ll temp;
        cin>>temp;
        mp[temp]++;
    }
    vi ans;
    ll current = 0;
    for(auto i:mp){
        if(i.second>0){
            if(current == n-1){
                if(i.second == 1){
                    ans.pb(i.first);
                    current++;
                }else{
                    flag = false;
                    break;
                }
            }else if(current == ((n-1)/2)){
                if(i.second==3){
                    ans.pb(i.first);
                    current++;
                }else{
                    flag = false;
                    break;
                }
            }else if(i.second == 2){
                ans.pb(i.first);
                current++;
            }else{
                flag = false;
                break;
            }
        }
    }
    if(current == n){
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
        return;
    }
    cout<<"-1\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}