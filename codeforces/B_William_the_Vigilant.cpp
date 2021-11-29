#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    unordered_map <ll,ll> mp;
    ll count = 0;
    for(ll i=0;i<n-2;i++){
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] =='c'){
            count++;
            mp[i]++;
            mp[i+1]++;
            mp[i+2]++;
            i+=2;
        }
    }
    fr(i,m){
        ll pos;
        //ll ans = count;
        char c;
        cin>>pos>>c;
        pos--;
        if(pos<0){
            s[pos] = c;
            cout<<count<<"\n";
            continue;
        }
        if(s[pos]==c){
            s[pos] =c;
            cout<<count<<"\n";
            continue;
        }
        if(mp[pos]>0){
            count--;
            if(s[pos] == 'a'){
                mp[pos]--;
                mp[pos+1]--;
                mp[pos+2]--;
            }else if(s[pos] =='b'){
                mp[pos]--;
                mp[pos-1]--;
                mp[pos+1]--;
            }else if(s[pos] =='c'){
                mp[pos]--;
                mp[pos-1]--;
                mp[pos-2]--;
            }

            if(s[pos] == 'a' && c =='c' && pos-1>=0 && pos-2>=0 && s[pos-1] =='b' && s[pos-2] == 'a'){
                count++;
                mp[pos]++;
                mp[pos-1]++;
                mp[pos-2]++;
            }else if(s[pos] =='c' && c=='a' && pos+1<n && pos+2<n && s[pos+1] == 'b' && s[pos+2] == 'c'){
                count++;
                mp[pos]++;
                mp[pos+1]++;
                mp[pos+2]++;
            }
        }else{
            if((c=='a' && pos+1<n && pos+2<n && s[pos+1]=='b' && s[pos+2]=='c')){
                count++;
                mp[pos]++;
                mp[pos+1]++;
                mp[pos+2]++;
            }if((c=='b' && pos+1<n && pos-1>=0 && s[pos-1]=='a' && s[pos+1]=='c')){
                count++;
                mp[pos]++;
                mp[pos-1]++;
                mp[pos+1]++;
            }else if((c=='c' && pos-1>=0 && pos-2>=0 && s[pos-1]=='b' && s[pos-2] =='a')){
                count++;
                mp[pos]++;
                mp[pos-1]++;
                mp[pos-2]++;
            }
        }
        s[pos] = c;
        cout<<count<<"\n";
    }
}

int main(void){
    fast;
    // test(t){
        sol();
    // }
}