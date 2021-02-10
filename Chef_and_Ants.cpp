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

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Chef_and_Ants.cpp
#  Created On:      04/01/2021
#  Problem Code:    ANTSCHEF
=============================================================================*/

void sol(){
    ll n;
    cin>>n;
    ll ans = 0;
    unordered_map <ll,ll> mp;
    vvi mt;
    for(ll i=0;i<n;i++){
        ll m;
        cin>>m;
        vi t;
        ll neg = 0,pos=0;
        for(ll j=0;j<m;j++){
            ll temp;
            cin>>temp;
            mp[abs(temp)]++;
            if(temp>0){
                pos++;
            }else{
                neg++;
            }
            t.pb(temp);
        }
        sort(t.begin(),t.end());
        mt.pb(t);
        ans+=(neg*pos);
    }
    if(n==1){
        cout<<ans<<endl;
    }else{
        ans = 0;
        for(ll i=0;i<n;i++){
            vector<ll> negg;
            vector<ll> poss;
            for(ll j=0;j<mt[i].size();j++){
                if(mt[i][j]>0){
                    poss.pb(mt[i][j]);
                }else{
                    negg.pb(mt[i][j]);
                }
            }
            sort(negg.rbegin(),negg.rend());
            sort(poss.begin(),poss.end());
            queue<ll> neg;
            queue<ll> pos;
            for(auto x:negg)
                neg.push(x);
            for(auto x:poss)
                pos.push(x);
            while(neg.empty() == false || pos.empty() == false){
                //cout<<ans<<endl;

                if(neg.empty()==false && pos.empty() == false){
                    if(abs(neg.front())<abs(pos.front())){
                        if(mp[abs(neg.front())]>1){
                            ans+=neg.size()-1;
                        }else{
                            ans+=pos.size();
                        }
                        neg.pop();
                    }else{
                        if(mp[abs(pos.front())]>1){
                            ans+=pos.size()-1;
                        }else{
                            ans+=neg.size();
                        }
                        pos.pop();
                    }
                }else{
                    if(neg.empty()==false){
                        if(mp[abs(neg.front())]>1){
                            ans+=neg.size()-1;
                        }else{
                            ans+=pos.size();
                        }
                        neg.pop();
                    }else{
                        if(mp[abs(pos.front())]>1){
                            ans+=pos.size()-1;
                        }else{
                            ans+=neg.size();
                        }
                        pos.pop();
                    }
                }
            }
        }
        for(auto x:mp){
            if(x.second>1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}