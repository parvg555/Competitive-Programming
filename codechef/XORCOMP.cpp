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

int myXOR(int x, int y)
{
    int res = 0; // Initialize result
     
    // Assuming 32-bit Integer 
    for (int i = 31; i >= 0; i--)                     
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
        
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}

void sol(){
    int x,y,n;
    cin>>x>>y>>n;
    ll count = 0;
    for(int i=0;i<=n;i++){
        if(myXOR(x,i)<myXOR(y,i)){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}