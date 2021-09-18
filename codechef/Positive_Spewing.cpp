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
    ll n,k;
    ll sum = 0;
    cin>>n>>k;
    ll arr[n];
    ll negative = -1;
    fr(i,n){
        cin>>arr[i];
        //cout<<arr[i]<<" ";
        if(arr[i] > 0 && negative == -1){ negative = i; }
        sum+=arr[i];
    } 
    if(negative == -1){
        cout<<sum<<"\n";
        return;
    }
    //cout<<negative<<"\n";

    ll left[n] = {0};
    ll right[n] = {0};

    ll start = 0;
    //ll pos = negative + 1;

    for(int i=0;i<n;i++){
        ll pos = (i+negative)%n;
        //cout<<pos<<" ";
        if(arr[pos] > 0){
            start = 0;
            left[pos] = 0;
        }else{
            start++;
            left[pos] = start;
        }
    }
    //cout<<"\n";
    start = 0;
    for(int i=0;i<n;i++){
        ll pos = (negative - i);
        if(pos<0){
            pos = n+pos;
        }
        //cout<<pos<<" ";
        if(arr[pos] > 0 ){
            start=0;
            right[pos] = 0;
        }else{
            start++;
            right[pos] = start;
        }
    }
    //cout<<"\n";
   
    map <ll,ll> mp;
    ll mxn = 0;
    for(int i=0;i<n;i++){
        //cout<<min(left[i],right[i])<<" ";
        mxn = max(mxn,min(left[i],right[i]));
        mp[min(left[i],right[i])]++;
    }
    ll init = 0;
    for(int i=0;i<=mxn && i<k;i++){
        init += mp[i];
        sum += 2*init;
    }
    if(k>mxn){
        sum += ((k-mxn-1)*n)*2;
    }
    cout<<sum<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}