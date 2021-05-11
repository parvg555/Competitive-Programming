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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        Tic_Tac_Toe.cpp
#  Created On:      11/05/2021
#  Problem Code:    TCTCTOE
=============================================================================*/


void sol(){
    char arr[3][3];
    ll x = 0, o = 0, dash = 0; 
    fr(i,3){
        fr(j,3){
            cin>>arr[i][j];
            if(arr[i][j] == 'X'){
                x++;
            }else if(arr[i][j]=='O'){
                o++;
            }else{
                dash++;
            }
        }
    }

    ll player1 = 0;
    ll player2 = 0;
    
    fr(i,3){
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
            if(arr[i][0] == 'X'){
                player1++;
            }else if(arr[i][0] == 'O'){
                player2++;
            }
        }

        if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
            if(arr[0][i] == 'X'){
                player1++;
            }else if(arr[0][i] == 'O'){
                player2++;
            }
        }
    }

    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
        if(arr[0][0] == 'X'){
            player1++;
        }else if(arr[0][0] == 'O'){
            player2++;
        }
    }

    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
        if(arr[0][2] == 'X'){
            player1++;
        }else if(arr[0][2] == 'O'){
            player2++;
        }
    }

    if(o>x || abs(x-o)>1){
        cout<<"3\n";
        return;
    }
    if((x>o && player1 == 1 && player2 == 0) || (x==o && player1==0 && player2 ==1) || (dash==0 && player1 ==0 && player2 == 0 ) || (dash==0 && player1==2)){
        cout<<"1\n";
        return;
    }
    if(dash>0 && player1 ==0 && player2 ==0 ){
        cout<<"2\n";
        return;
    }
    cout<<"3\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}