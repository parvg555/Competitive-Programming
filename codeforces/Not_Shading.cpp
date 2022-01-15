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
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    char arr[n][m];
    ll whites = 0;
    fr(i,n){
        string temp; 
        cin>>temp;
        fr(j,m){
        arr[i][j] = temp[j];
        // cout<<arr[i][j]<<" ";
        if(arr[i][j] == 'W') whites++;
    }
    // cout<<"\n";
    }
    if(arr[r-1][c-1] == 'B'){
        cout<<"0\n";
        return;
    }
    if(whites == n*m){
        cout<<"-1\n";
        return;
    }
    ll blacks = 0;
    fr(i,n){ 
        if(arr[i][c-1] == 'B') blacks++;
    }
    fr(i,m){ if(arr[r-1][i] == 'B') blacks++;}
    // cout<<"BLACKS:" <<blacks<<"\n";
    if(blacks > 0){
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}