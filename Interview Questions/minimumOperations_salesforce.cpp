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

int mindis(string s){
    int count[26] = {0};
    int n = s.length();
    for(int i=0;i<n;i++) count[s[i] - 'a']++;
    int biggest = 0;
    int sum = 0;
    for(int i=0;i<26;i++){
        biggest = max(biggest,count[i]);
        sum+=count[i];
    }
    return sum-biggest;
}

int ans2finder(string s1, string s2){
    int ans = INT_MAX;
    int n = s1.length();
    int m = s2.length();
    for(char c = 'b' ; c < 'z' ; c++){
        int temp_ans = 0;
        for(int i=0;i<m;i++){
            if(s2[i] < c) temp_ans++;
        }
        for(int i=0;i<n;i++){
            if(s1[i] >= c) temp_ans++;
        }
        ans = min(temp_ans,ans);
    }
    return ans;
}

int sol(string s1, string s2){
    int ans1 = ans2finder(s1,s2);
    int ans2 = ans2finder(s2,s1);
    int distinct1 = mindis(s1);
    int distinct2 = mindis(s2);
    return min(ans1,min(ans2,distinct1+distinct2));
}

int main(void){
    fast;
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<sol(s1,s2)<<"\n";
}