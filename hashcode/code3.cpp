#include<bits/stdc++.h>
#include<chrono>
#include<string.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define m 1000000007
using namespace std;
using namespace std::chrono;

//aditya ranaut- phoenix_aditya

struct intersection{
    int start;
    int end;
    string streetname;
    int duration;
};

struct cars{
    int noofroads;
    vector<string> roads;
};

void solve()
{
    //input
    // d= duration i=no of intersections s=no of streets  v=no of cars f= bonus point for each car to reach home
    ll d,i,s,v,f;
    cin>>d>>i>>s>>v>>f;
    intersection streets[s];
    f(zz,0,s){
        cin>>streets[zz].start>>streets[zz].end;
        cin>>streets[zz].streetname;
        cin>>streets[zz].duration;
    }
    
    cars car[v];
    
    set<string> visitingstreets;
    string temp;
    f(zz,0,v){
        cin>>car[zz].noofroads;
        f(j,0,car[zz].noofroads){
            cin>>temp;
            car[zz].roads.push_back(temp);
            visitingstreets.insert(temp);
        }
    }
    vector<pair<string,int>> ans[i+1];
    
    for(string sata: visitingstreets){
        for(auto xx: streets){
            if(sata==xx.streetname){
                ans[xx.end].push_back({xx.streetname,ceil(1.0*xx.duration/3)});
            }
        }
    }
    
    vector<pair<int,vector<pair<string,int>>>> finalanswer;
    
    for(int zeta=0;zeta<i;zeta++){
        if(ans[zeta].size()!=0){
            finalanswer.push_back({zeta,ans[zeta]});
        }
    }
    
    cout<<finalanswer.size()<<endl;
    for(auto x:finalanswer){
        cout<<x.first<<endl;
        cout<<x.second.size()<<endl;
        for(auto zozo:x.second){
            cout<<zozo.first<<"  "<<zozo.second<<endl;
        }
    }
}

int main()
{
    //    auto start = high_resolution_clock::now();
     freopen("c.txt","r",stdin);
     freopen("cout.txt","w",stdout);
    
    speed;
    solve();
    
    //    auto stop = high_resolution_clock::now();
    //    auto duration = duration_cast<microseconds>(stop - start);
    //
    //      cout << "Time taken by function: "
    //           << duration.count() << " microseconds" << endl;
    
    return 0;
}
