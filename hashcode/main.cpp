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
#define inn freopen("a.txt", "r", stdin)
#define outt freopen("oa.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

vector < pair<string, tuple<ll,ll,ll>> > intr;// name start end time
vector<pair<ll,vector<ll>>> cars;// number of streets name of streets

ll find_function(string s){
    for(ll i=0;i<intr.size();i++){
        if(intr[i].fi == s){
            return i;
        }
    }
}

void sol(){
    ll d; //duration of simulation
    ll i; //number of instersection
    ll s; // number of streets
    ll v; //number of cars
    ll f; //bonus for each car that reaches its destination before time d
    fr(i,s){
        ll B,E;//begin and end of intersection
        cin>>B>>E;
        string s;
        cin>>s;
        ll time;
        cin>>time;
        intr.pb(mp(s,make_tuple(B,E,time)));
    }
    fr(i,v){
        ll p;
        cin>>p;
        vector <ll> path;
        fr(j,p){
            string temp;
            cin>>temp;
            ll st = find_function(temp);
            path.pb(get<1>(intr[st].sec));
        }
        cars.pb(mp(p,path));
    }

}

int main(void){
    inn;
    outt;
    fast;
    sol();
}