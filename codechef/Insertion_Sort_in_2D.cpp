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
    ll arr[n][n];
    fr(i,n) fr(j,n) cin>>arr[i][j];
    if(n==1){cout<<arr[0][0]<<"\n"<<arr[0][0]<<"\n";return;}
    // rows iteration = (n+1)/2;
    // cout<<"INSERTION ITERATIONS: "<<(2*n) - 3<<"\n";
    // cout<<"RINGS: "<<(n+1)/2<<"\n";
    for(ll i=0;i<((2*n) - 3);i++){
        // cout<<"INSERTION NUMBER: "<<i+1<<"\n";
        for(ll j=0;j<((n+1)/2);j++){
            // cout<<"RING NUMBER: "<<j<<"\n";
            vi arr1;
            vi arr2;
            ll corner1_x = j;
            ll corner1_y = j;
            ll corner2_x = j + (n - (2*j)) - 1;
            ll corner2_y = j;
            ll corner3_x = j + (n - (2*j)) - 1;
            ll corner3_y = j + (n - (2*j)) - 1;
            ll corner4_x = j;
            ll corner4_y = j + (n - (2*j)) - 1;
            // cout<<"CORNERS: \n";
            // cout<<"("<<corner1_x<<","<<corner1_y<<")\n";
            // cout<<"("<<corner2_x<<","<<corner2_y<<")\n";
            // cout<<"("<<corner3_x<<","<<corner3_y<<")\n";
            // cout<<"("<<corner4_x<<","<<corner4_y<<")\n";
            for(ll k = corner1_x;k<corner2_x;k++){
                arr1.pb(arr[k][corner1_y]);
                // cout<<arr[k][corner1_y]<<",";
            }
            for(ll k= corner2_y;k<corner3_y;k++){
                arr1.pb(arr[corner2_x][k]);
                // cout<<arr[corner2_x][k]<<",";
            }
            for(ll k=corner3_x;k>corner4_x;k--){
                arr2.pb(arr[k][corner3_y]);
                // cout<<arr[k][corner3_y]<<",";
            }
            for(ll k=corner4_y;k>corner1_y;k--){
                arr2.pb(arr[corner4_x][k]);
                // cout<<arr[corner4_x][k]<<",";
            }
            ll index = i + 1;
            if(index < arr1.size() && index > 0){
                for(ll k = index - 1; k>=0;k--){
                    if(arr1[k+1] < arr1[k]){
                        ll temp = arr1[k+1];
                        arr1[k+1] = arr1[k];
                        arr1[k] = temp;
                    }
                }
            }
            index = i + 1;
            if(index < arr2.size() && index > 0){
                for(ll k = index - 1; k>=0;k--){
                    if(arr2[k+1] < arr2[k]){
                        ll temp = arr2[k+1];
                        arr2[k+1] = arr2[k];
                        arr2[k] = temp;
                    }
                }
            }
            // for(auto k:arr1) cout<<k<<",";
            // cout<<"\n";
            // for(auto k:arr2) cout<<k<<",";
            // cout<<"\n";
            ll pos = 0;
            for(ll k = corner1_x;k<corner2_x;k++){
                arr[k][corner1_y] = arr1[pos];
                pos++;
            }
            for(ll k= corner2_y;k<corner3_y;k++){
                arr[corner2_x][k] = arr1[pos];
                pos++;
            }
            pos = 0;
            for(ll k=corner3_x;k>corner4_x;k--){
                arr[k][corner3_y] = arr2[pos];
                pos++;
            }
            for(ll k=corner4_y;k>corner1_y;k--){
                arr[corner4_x][k] = arr2[pos];
                pos++;
            }
        }
        fr(p,n) fr(t,n) cout<<arr[p][t]<<" ";
        cout<<"\n";
    }

    // cout<<"NUMBER OF MERGES: "<<(2*n) - 2<<"\n";
    for(ll i=0;i<((2*n) - 2);i++){
        // cout<<"MERGE NUMBER:"<<i<<"\n";
        for(ll j=0;j<((n+1)/2);j++){
            // cout<<"RING NUMBER: "<<j<<"\n";
            vi arr1;
            ll corner1_x = j;
            ll corner1_y = j;
            ll corner2_x = j + (n - (2*j)) - 1;
            ll corner2_y = j;
            ll corner3_x = j + (n - (2*j)) - 1;
            ll corner3_y = j + (n - (2*j)) - 1;
            ll corner4_x = j;
            ll corner4_y = j + (n - (2*j)) - 1;
            // cout<<"CORNERS: \n";
            // cout<<"("<<corner1_x<<","<<corner1_y<<")\n";
            // cout<<"("<<corner2_x<<","<<corner2_y<<")\n";
            // cout<<"("<<corner3_x<<","<<corner3_y<<")\n";
            // cout<<"("<<corner4_x<<","<<corner4_y<<")\n";
            for(ll k = corner1_x;k<corner2_x;k++){
                arr1.pb(arr[k][corner1_y]);
                // cout<<arr[k][corner1_y]<<",";
            }
            for(ll k= corner2_y;k<corner3_y;k++){
                arr1.pb(arr[corner2_x][k]);
                // cout<<arr[corner2_x][k]<<",";
            }
            for(ll k=corner3_x;k>corner4_x;k--){
                arr1.pb(arr[k][corner3_y]);
                // cout<<arr[k][corner3_y]<<",";
            }
            for(ll k=corner4_y;k>corner1_y;k--){
                arr1.pb(arr[corner4_x][k]);
                // cout<<arr[corner4_x][k]<<",";
            }
            ll num = (arr1.size()/2);
            ll index = num + i;
            if(index < arr1.size() && index > 0){
                for(ll k = index - 1; k>=0;k--){
                    if(arr1[k+1] < arr1[k]){
                        ll temp = arr1[k+1];
                        arr1[k+1] = arr1[k];
                        arr1[k] = temp;
                    }
                }
            }
            // for(auto k:arr1) cout<<k<<",";
            // cout<<"\n";
            // for(auto k:arr2) cout<<k<<",";
            // cout<<"\n";
            ll pos = 0;
            for(ll k = corner1_x;k<corner2_x;k++){
                arr[k][corner1_y] = arr1[pos];
                pos++;
            }
            for(ll k= corner2_y;k<corner3_y;k++){
                arr[corner2_x][k] = arr1[pos];
                pos++;
            }
            for(ll k=corner3_x;k>corner4_x;k--){
                arr[k][corner3_y] = arr1[pos];
                pos++;
            }
            for(ll k=corner4_y;k>corner1_y;k--){
                arr[corner4_x][k] = arr1[pos];
                pos++;
            }
        }
        fr(p,n) fr(t,n) cout<<arr[p][t]<<" ";
        cout<<"\n";
    }
}

int main(void){
    fast;
    // test(t){
        sol();
    // }
}
