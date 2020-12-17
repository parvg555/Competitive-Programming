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
#  FileName:        Hiring_Workers.cpp
#  Created On:      17/12/2020
#  Problem Code:    HIRINGWO
=============================================================================*/


vector <int> factors(int n){
    vector <int> fa;
    for(int i=2;i<n;i++){
        if(n%i==0){
            int power = 0;
            while(n%i==0){
                power+=1;
                n=n/i;
            }
            fa.pb(pow(i,power));
        }
    }
    if(n!=1){
        fa.pb(n);
    }
    return fa;
}

int brute(vector <int> fa, int k){
    int ans = INT_MAX;
    cout<<endl;
    for(int i=0;i<fa.size();i++){
        for(int j=i+1;j<fa.size();j++){
            vector <int> factors;
            for(int p=0;p<fa.size();p++){
                factors.pb(fa[p]);
            }
            factors[j] *= factors[i];
            factors.erase(factors.begin()+i);
            if(factors.size()==k){
                int sum = 0;
                for(int l=0;l<factors.size();l++){
                    sum +=factors[l];
                }
                if(sum<ans){
                    ans = sum;
                }
            }else{
                int sum = brute(factors,k);
                if(sum<ans){
                    ans = sum;
                }
            }
        }
    }
    return ans;
}

void sol(){
    int k,x;
    cin>>k>>x;
    vector <int> ans = factors(x);
    if(ans.size()<=k){
        int sum = 0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        cout<<sum+(k-ans.size())<<endl;
    }else{
        cout<<brute(ans,k)<<endl;
    }
}

int main(void){
    fast;
    test(t){
        sol();
    }
}