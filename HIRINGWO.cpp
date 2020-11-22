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

vi subarray2;
ll sum = 0;

ll gcd(ll a, ll b){
    if(a==0){
        return b;
    }

    return gcd(b%a,a);
}

void findlcm(vi arr, int n,ll checkmultiple) 
{ 
    //cout<<"n- "<<n<<"check multiple"<<checkmultiple<<endl;
    ll ans = arr[0]; 
    ll suml = arr[0];
    for (int i = 1; i < n; i++){
        suml += arr[i];
        ans = (((arr[i] * ans))/(gcd(arr[i], ans)));
    }
    //cout<<"ans - "<<ans<<"suml - "<<suml<<endl;
    //cout<<"sum - "<<sum<<endl;
    if(sum == 0 && ans==checkmultiple){
        subarray2 = arr;
        sum = suml;
    }else if(suml<sum && ans==checkmultiple){
        //cout<<"least sum found"<<endl;
        subarray2 = arr;
        sum = suml;
    }
    return;
} 


void checkandupdate(vi subarray, ll checkmultiple){
    if(subarray.size()==1){
        //cout<<"returned"<<endl;
        return;
    }else{
        //cout<<"called lmc"<<endl;
        findlcm(subarray,subarray.size(),checkmultiple);
    }
    return;
}

void findsubarray(vi factors,ll start, ll end, ll checkmultiple){
    if(end == factors.size()){
        return;
    }else if(start>end){
        findsubarray(factors,0,end+1,checkmultiple);
    }else{
        vi subarray;
        for(ll i=start;i<=end;i++){
            subarray.pb(factors[i]);
        }
        //cout<<"checking for - ";
        //for(ll i =0 ;i<subarray.size();i++){
        //    cout<<subarray[i]<<",";
        //}
        //cout<<endl;
        checkandupdate(subarray,checkmultiple);
        findsubarray(factors,start+1,end,checkmultiple);
    }
    //cout<<"final reject"<<endl;
    return;
}

void sol(){
    ll k,x;
    cin>>k>>x;
    vi factors;
    for(ll i=1;i<=sqrt(x);i++){
        if(x%i==0){
            if(x/i==i){
                factors.pb(i);
            }else{
                factors.pb(i);
                factors.pb(x/i);
            }
        }
    }
    //cout<<"finding subarray"<<factors.size()<<endl;
    findsubarray(factors,0,0,x);
    //cout<<"no return form final"<<endl;
    //for(ll i;i<subarray2.size();i++){
    //    cout<<subarray2[i]<<",";
    //}
    //cout<<endl;
    cout<<(sum+(k-subarray2.size()))<<endl;
    return;
}

int main(void){
    fast;
    test(t){
        subarray2.clear();
        sum = 0;
        sol();
    }
}