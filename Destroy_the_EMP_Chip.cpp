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

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Destroy_the_EMP_Chip.cpp
#  Created On:      12/04/2021
#  Problem Code:    CHAOSEMP
=============================================================================*/



void sol(){
    ll t,q,d;
    cin>>t>>q>>d;
    fr(i,t){
        ll low = -1LL*2e18;
        ll high = 2e18;
        ll mx = 2e18;
        ll mn = -1LL*2e18;
        bool flag = false;
        while(low<=high){
            ll mid = (low+high)/2;
            if(!flag){
               cout<<1LL<<" "<<mid<<" "<<mn<<endl;
            }else{
               cout<<2LL<<" "<<mid<<" "<<mn<<" "<<mid<<" "<<mx<<endl;
            }
            // "O"  if X=A and Y=B
            // "PY" if X>A and Y=B
            // "NY" if X<A and Y=B
            // "XP" if X=A and Y>B
            // "XN" if X=A and Y<B
            // "PP" if X>A and Y>B
            // "PN" if X>A and Y<B
            // "NP" if X<A and Y>B
            // "NN" if X<A and Y<B
            string s;
            cin>>s;
            if(s=="FAILED"){
                return;
            }else if(s=="O"){
                break;
            }else if(s=="PY"){
                high=mid-1LL;
            }else if(s=="NY"){
                low=mid+1LL;
            }else if(s=="XP"){
                flag=true;
            }else if(s=="XN"){
                flag=true;
            }else if(s=="PP"){
                high=mid-1LL;
            }else if(s=="PN"){
                high=mid-1LL;
            }else if(s=="NP"){
                low=mid+1LL;
            }else if(s=="NN"){
                low=mid+1LL;
            }
        }
    }
}

int main(void){
    sol();
}