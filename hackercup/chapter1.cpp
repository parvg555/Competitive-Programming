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
#define inn freopen("chapter1.txt", "r", stdin)
#define outt freopen("chapter1_output3.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

int sol(){
    string s;
    cin>>s;
    ll fre[26];
    for(int i=0;i<26;i++){
        fre[i] = 0;
    }
    fr(i,s.length()){
        fre[s[i] - 'A']++;
    }
    ll ans = LONG_LONG_MAX;
    ll frequency_of_vowels = fre[0] + fre[4] + fre[8] + fre[14] + fre[20];
    ll frequency_of_consonants = s.length() - frequency_of_vowels;
    for(int i=0;i<26;i++){
        ll temp;
        if(i==0 || i==4 || i==8 || i==14 || i==20){
            temp = (frequency_of_vowels - fre[i])*2 + frequency_of_consonants;
        }else{
            temp = (frequency_of_consonants - fre[i])*2 + frequency_of_vowels;
        }
        ans = min(ans,temp);  
    }
    return ans;
}

int main(void){
    inn;
    outt;
    fast;
    ll count = 1;
    test(t){
        cout<<"Case #"<<count<<": "<<sol()<<"\n";
        count++;
    }
}