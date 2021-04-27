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
    vi arr;
    ll grid[n][n];
    mem(grid,0);
    fr(i,n){
        ll temp;
        cin>>temp;
        arr.pb(temp);
    }
    ll count[n];
    fr(i,n){
        count[i]=i;
    }

    fr(i,n){
        fr(j,n){
            if(i==j){
                grid[i][i]=arr[i];
            }
        }
    }
    fr(i,n){
        ll current_x = i;
        ll current_y = i;
        ll num = grid[i][i];
        while(count[grid[i][i]-1]>0){
            if( current_y>0 && grid[current_x][current_y-1] == 0){
                current_y--;
                grid[current_x][current_y]=num;
                count[grid[i][i]-1]--;
            }else if(current_x<n-1 && grid[current_x+1][current_y]==0){
                current_x++;
                grid[current_x][current_y]=num;
                count[grid[i][i]-1]--;
            }
        }
    }
    fr(i,n){
        fr(j,n){
            if(grid[i][j]!=0){
                cout<<grid[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

}

int main(void){
    fast;
    sol();
}