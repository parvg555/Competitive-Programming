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
vector<pair<ll,vector<ll>>> cars;// time path
vector<pair<ll,vector<pair<string,ll>>>> ans;

ll find_function(string s){
    for(ll i=0;i<intr.size();i++){
        if(intr[i].fi == s){
            return i;
        }
    }
    return 0;
}

ll find_streetname(ll e){
    for(ll i=0;i<intr.size();i++){
        if(get<1>(intr[i].sec) == e ){
            return i;
        }
    }
    return 0;
}

void sol(){
    ll d; //duration of simulation
    ll i; //number of instersection
    ll s; // number of streets
    ll v; //number of cars
    ll f; //bonus for each car that reaches its destination before time d
    cin>>d>>i>>s>>v>>f;
    fr(i,s){
        ll B,E;//begin and end of intersection
        cin>>B>>E;
        string s;
        cin>>s;
        ll time;
        cin>>time;
        intr.pb(mp(s,make_tuple(B,E,time)));
    }
    cout<<"input 1 ok\n";
    fr(i,v){
        ll p;
        cin>>p;
        vector <ll> path;
        ll time = 0;
        fr(j,p){
            string temp;
            cin>>temp;
            ll st = find_function(temp);
            cout<<get<1>(intr[st].sec)<<"->";/////////////////////////////////////////////////////////////
            path.pb(get<1>(intr[st].sec));
            if(j!=0){
                time+=get<2>(intr[st].sec);
            }
        }
        //cout<<"\n";
        cout<<"\t Journey time: "<<time<<"\n";/////////////////////////////////////////////////////////// 
        cars.pb(mp(time,path));
    }
    sort(all(cars));
    ll ans_int=0; //number of intersections in ans
    fr(i,v){
        fr(j,cars[i].sec.size()){
            if(j==0){
                ll loc = cars[i].sec[j];
                string street_name = intr[find_streetname(loc)].fi;
                cout<<street_name<<"\n";
            }else{
                ll loc = cars[i].sec[j];
                string street_name = intr[find_streetname(loc)].fi;
                cout<<street_name<<"\n";
            }
        }
        cout<<"\n";
    }
}

int main(void){
    inn;
    outt;
    fast;
    sol();
}