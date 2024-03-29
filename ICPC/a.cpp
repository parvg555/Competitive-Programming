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
#define pq priority_queue<int,vector<int>, greater <int>>
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
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void sol(){
    int n;
    cin>>n;
    ll ans = 0;
    pq q;
    fr(i,n){
        int s;
        cin>>s;
        int arr[s];
        fr(i,s){
            int temp;
            cin>>temp;
            arr[i] = temp;
        }
        int lst =1;
        vi temp;
        for(int j=1;j<s;j++){
            if(arr[j]<arr[j-1]){
                q.push(lst);
                temp.pb(lst);
                lst = 1;
            }else{
                lst++;
            }
        }
        temp.pb(lst);
        q.push(lst);
        if(temp.size()==1){
            continue;
        }
        int nax = *max_element(all(temp));
        ans+=s-nax;
    }
    while(q.size()>1){
        int sm2 = q.top();
        q.pop();
        sm2+=q.top();
        q.pop();
        ans+=sm2;
        q.push(sm2);
    }
    cout<<ans<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}