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
    set <pair <string, char>> arr;
    set <pair <string, char>>::iterator itr;
    set <char> firsts;
    set <string> seconds;
    fr(i,n){
        string s;
        cin>>s;
        char first = s[0];
        s.erase(s.begin());
        firsts.insert(first);
        seconds.insert(s);
        arr.insert(mp(s,first));
    }
    ll ans = 0;
    itr = arr.begin();
    pair <string, char> temp = *itr;
    string s = temp.fi;
    ll total = firsts.size();
    ll total2 = seconds.size();
    ll count = 1;
    itr++;
    for(;itr!=arr.end();itr++){
        temp = *itr;
        cout<<"string: "<<temp.fi<<endl;
        if(s!=temp.fi){
            ans+=count*(total-count);
            count=0;
        }
        count++;
        s = temp.fi;
        cout<<"count: "<<count<<" ans:"<<ans<<endl;
    }
    ans +=count*(total-count);
    cout<<ans<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}