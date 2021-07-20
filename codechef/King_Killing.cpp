#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int ll;
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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        King_Killing.cpp
#  Created On:      16/05/2021
#  Problem Code:    KKLING
=============================================================================*/


const int mxn = 2e4 + 10;
vi graph[mxn];
ll level[mxn];
vi leaf;
vpi ans;


void dfs1(ll n, ll p, ll l){
    for(auto i: graph[n]){
        if(i!=p){
            level[i] = l+1;
            dfs1(i,n,l+1);
        }
    }
}

void leaves(ll n, ll p){
    if(graph[n].size() == 1 && n!= 1){
        leaf.pb(n);
    }
    for(auto i: graph[n]){
        if(i!=p){
            leaves(i,n);
        }
    }
}

bool comparison(ll n, ll m){
    if(level[n]<=level[m]){
        return true;
    }
    return false;
}

void answer(){
    for(ll k = 0;k<graph[1].size();k++){
        ll i = graph[1][k];
        //finding leaf nodes
        leaf.clear();
        leaves(i,1);
        // variable for temp ans
        ll flag = false;
        vpi temp2;
        //saving leaf nodes and their levels
        //sort leaf nodes
        sort(all(leaf),comparison);
        // setting score equal to the smallest node
        ll score = level[leaf[0]];
        //starting with the smallest node
        pii current = mp(score,leaf[0]);
        temp2.pb(current);
        // interating from next node
        for(ll start = 1;start<leaf.size();){

            for(;start<leaf.size() && level[leaf[start]] == score;){
                if(flag){
                    temp2.pb(mp(current.fi+1,leaf[start]));
                }else{
                    temp2.pb(mp(level[leaf[start]],leaf[start]));
                }
                start++;
            }
            if(start<leaf.size()){
                temp2.clear();
                flag = true;
                current.sec = leaf[start];
                temp2.pb(mp(current.fi+1,leaf[start]));
                score = level[leaf[start]];
                start++;
            }
        }
        for(ll j=0;j<temp2.size();j++){
            ans.pb(temp2[j]);
        }
    }
}



void printdata(ll n){
    cout<<"LEVEL:"<<"\n";
    fr(i,n+1){
        cout<<level[i]<<" ";
    }
    cout<<"\n";
    cout<<"ANSWER: "<<"\n";
    for(auto i:ans){
        cout<<i.fi<<" "<<i.sec<<"\n";
    }
    cout<<"\n";
}

void clean(ll n){
    fr(i,n+1){
        graph[i].clear();
        level[i] = 0;
    }
    leaf.clear();
    ans.clear();
}

void sol(){
    ll n;
    cin>>n;
    fr(i,n-1){
        ll p,c;
        cin>>p>>c;
        if(p!=c){
            graph[p].pb(c);
            graph[c].pb(p);
        }
    }
    dfs1(1,0,0);
    answer();
    //printdata(n);
    sort(all(ans));
    ll start = ans[0].fi;
    vi answer;
    ll count = 0;
    for(auto i:ans){
        if(i.fi == start){
            count++;
            answer.pb(i.sec);
        }
    }
    cout<<count<<" "<<start<<"\n";
    sort(all(answer));
    for(auto i:answer){
        cout<<i<<" ";
    }
    answer.clear();
    cout<<"\n";
    clean(n);
}

int main(void){
    mem(level,0);
    fast;
    test(t){
        sol();
    }
}