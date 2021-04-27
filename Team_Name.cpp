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
#  FileName:        Team_Name.cpp
#  Created On:      09/02/2021
#  Problem Code:    TEAMNAME
=============================================================================*/

void sol(){
    ll n;
    cin>>n;
    ll ans = 0;
    set<char> checking;
    map<string,vector<char>> mp;
    map<string,vector<char>>::iterator it1;
    map<string,vector<char>>::iterator it2;
    fr(i,n){
        string s;
        cin>>s;
        char a = s[0];
        s.erase(s.begin());
        if(mp.find(s)!=mp.end()){
            mp[s].pb(a);
        }else{
            vector <char> temp;
            temp.pb(a);
            mp.insert({s,temp});
        }
    }

    for(it1 = mp.begin();it1!=mp.end();it1++){
        it2 = it1;
        ++it2;
        for(;it2!=mp.end();it2++){
            vector <char> noob1 = it1->sec;
            vector <char> noob2 = it2->sec;
            ll noob1_size = noob1.size();
            ll noob2_size = noob2.size();
            fr(i,noob1_size){
                checking.insert(noob1[i]);
            }
            fr(i,noob2_size){
                checking.insert(noob2[i]);
            }
            ll set_size = checking.size();
            ans += (set_size-noob1_size)*(set_size-noob2_size);
            checking.clear();
        }
    }
    cout<<2*ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}
