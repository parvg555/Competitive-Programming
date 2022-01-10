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
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    bool arr2[n][m];
    ll num[m];
    fr(i,n){
        ll temp;
        cin>>temp;
        for(ll j=m-1;j>=0;j--){
            arr[i][j] = temp%10;
            temp = temp/10;
        }
    }
    ll temp;
    cin>>temp;
    for(ll i=m-1;i>=0;i--){
        num[i] = temp%10;
        temp = temp/10;
    }
    vvi ans;
    ll mn = LONG_LONG_MAX;
    ll mx = 0;
    bool visited[m] = {false};
    fr(i,m) visited[i] = false;
    fr(i,n){
        for(ll j = 0;j<m;j++){
            if(visited[j]){
                continue;
            }
            fr(k,m){
                ll start_num = -1;
                ll start = -1;
                ll size = 0;
                if( visited[j] == false && num[j] == arr[i][k]){
                    start_num = j;
                    start = k;
                    size = 0;
                    while(start_num+size<m && start+size<m && visited[start_num+ size] == false &&num[start_num+size] == arr[i][start+size]) size++;
                }else{
                    continue;
                }
                if(size > 1){
                    mn = min(mn,start_num);
                    mx = max(mx,start_num+size-1);
                    for(ll lo = start_num;lo< start_num + size;lo++){
                        visited[lo] = true;
                    }
                    vi temp;
                    temp.pb(start_num);
                    temp.pb(start_num+size-1);
                    temp.pb(start+1);
                    temp.pb(start+size);
                    temp.pb(i+1);
                    ans.pb(temp);
                }
                j+=size-1;
                if(j>=m){
                    break;
                }
            }   
        }
        // cout<<"\n";
    }
    // cout<<"min: "<<mn<<" max:"<<mx<<"\n";
    sort(all(ans));
    if(mn == 0 && mx == m-1){
        cout<<ans.size()<<"\n";
        for(auto i:ans){
            cout<<i[2]<<" "<<i[3]<<" "<<i[4]<<"\n";
        }
        return;
    }
    cout<<"-1\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}