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
#  FileName:        Consecutive_Adding.cpp
#  Created On:      14/03/2021
#  Problem Code:    CONSADD
=============================================================================*/


bool check1(vvi a, vvi b, ll r, ll c){
    fr(i,r){
        fr(j,c){
            if(a[i][j]!=b[i][j]){
                return false;
            }
        }
    }
    return true;
}

void sol(){
    ll r,c,x;
    cin>>r>>c>>x;
    vvi mat1;
    vvi mat2;
    fr(i,r){
        vi temp;
        fr(j,c){
            ll temp2;
            cin>>temp2;
            temp.pb(temp2);
        }
        mat1.pb(temp);
    }
    fr(i,r){
        vi temp;
        fr(j,c){
            ll temp2;
            cin>>temp2;
            temp.pb(temp2);
        }
        mat2.pb(temp);
    }
    if(check1(mat1,mat2,r,c)){
        cout<<"Yes\n";
    }else if(r<x){
        fr(i,r){
            fr(j,c-x+1){
                if(mat1[i][j]==mat2[i][j]){
                    continue;
                }else{
                    ll diff = mat2[i][j] - mat1[i][j];
                    fr(k,x){
                        mat1[i][j+k]+=diff;
                    }
                }
            }
        }
        if(check1(mat1,mat2,r,c)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else if(c<x){
        fr(i,c){
            fr(j,r-x+1){
                if(mat1[j][i]==mat2[j][i]){
                    continue;
                }else{
                    ll diff = mat2[j][i]-mat1[j][i];
                    fr(k,x){
                        mat1[j+k][i]+=diff;
                    }
                }
            }
        }
        if(check1(mat1,mat2,r,c)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else if(c>=x && r>=x){
        fr(i,r){
            fr(j,c-x+1){
                if(mat1[i][j]==mat2[i][j]){
                    continue;
                }else{
                    ll diff = mat2[i][j]-mat1[i][j];
                    fr(k,x){
                        mat1[i][j+k]+=diff;
                    }
                }
            }
        }
        fr(i,c){
            fr(j,r-x+1){
                if(mat1[j][i]==mat2[j][i]){
                    continue;
                }else{
                    ll diff = mat2[j][i]-mat1[j][i];
                    fr(k,x){
                        mat1[j+k][i]+=diff;
                    }
                }
            }
        }
        if(check1(mat1,mat2,r,c)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }else{
        cout<<"No\n";
    }

}

int main(void){
    fast;
    test(t){
        sol();
    }
}