#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
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

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        XOR_Sums.cpp
#  Created On:      14/02/2021
#  Problem Code:    SUMXOR2
=============================================================================*/

ll C(ll n, ll k)
{
    if (k > n){
        return 0;
    }
    if (k == 0 || k == n){
        return 1;
    }
    return C(n - 1, k - 1) + C(n - 1, k);
}




void sol(){
    ll n;
    cin>>n;
    ll arr [n][32];
    ll sum = 0;
    fr(i,n){
        ll temp;
        cin>>temp;
        sum = (sum+temp)%mod;
        for(int j=31;j>=0;j--){
            int k = temp>>j;
            if(k&1){
                arr[i][j] = 1;
            }else{
                arr[i][j] = 0;
            }
        }
    }
    ll ones[32];
    ll zero[32];
    fr(i,32){
        ll one = 0;
        ll zeros = 0;
        fr(j,n){
            if(arr[j][i]==1){
                one++;
            }else{
                zeros++;
            }
        }
        ones[i]=one;
        zero[i]=zeros;
    }
    ll ans[n+1];
    mem(ans,0);
    ll q;
    cin>>q;
    fr(i,q){
        ll temp;
        cin>>temp;
        if(ans[temp]==0){
            for(ll k=1;k<=temp;k++){
                ll total = 0;
                for(ll j=1;j<=k;j+=2){
                    for(ll i=0;i<32;i++){
                        ll pass1 = C(ones[i],j);
                        ll pass2 = C(zero[i],k-j);
                        total += ((pass1*pass2)*powerof2[i])%mod;
                    }
                }
                ans[k]=(ans[k-1]+total)%mod;
            }
        }
        cout<<ans[temp]<<"\n";
    }
}

int main(void){
    fast;
    sol();
}
