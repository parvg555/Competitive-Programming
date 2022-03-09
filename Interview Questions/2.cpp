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
    vi arr(n);
    fr(i,n) cin>>arr[i];
    ll key, j;
    for (ll i = 1; i < n; i++) {
        key = arr[i];
        if (key > 0)
            continue;
        j = i - 1;
        while (j >= 0 && arr[j] > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    vector<ll> ans;
    for(ll i=1;i<n;i++){
        if(arr[i] - arr[i-1] > 1){
            cout<<arr[i-1]<<" "<<arr[i]<<"\n";

            if(arr[i] < 0 && arr[i-1] < 0){
                ll sum1 = ((abs(arr[i-1]))*(abs(arr[i-1])-1))/2;
                ll sum2 = ((abs(arr[i]))*(abs(arr[i])+1))/2;
                ans.push_back(-1*(sum1-sum2));
            }else if(arr[i] > 0 && arr[i-1] > 0){
                ll sum1 = ((arr[i]-1)*arr[i])/2;
                ll sum2 =  (arr[i-1] * (arr[i-1]+1))/2;
                ans.push_back(sum1-sum2);
            }else{
                ll sum1 = ((abs(arr[i-1]))*(abs(arr[i-1])-1))/2;
                ll sum2 = (arr[i] * (arr[i] - 1))/2;
                ans.push_back((-1*sum1) + sum2);
            }

        }else{
            ans.push_back(0);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main(void){
    fast;
        sol();
}