#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int ll;
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

string returnNumberString(string ZeroString,int n){
    ZeroString[n] = '1';
    return ZeroString;
}

vector <int> solve(int n, int q, vector<int> arr, vector<vector<int>> queries){
    vector <int> ans;
    string ZeroString = "";
    for(int i=0;i<=1001;i++) ZeroString+='0';
    vector <bitset<1001>> pre(n);
    for(int i=0;i<n;i++){
        bitset<1001> temp(returnNumberString(ZeroString,arr[i]));
        if(i==0){
            pre[i] = temp;
        }else{
            pre[i] = pre[i-1];
            pre[i] = pre[i]^temp;
        }
    }
    for(int i=0;i<q;i++){
        if(queries[i][0]==1){
            int start = queries[i][1]-1;
            bitset<1001> beforeNum(returnNumberString(ZeroString,arr[start]));
            bitset<1001> aftereNum(returnNumberString(ZeroString,queries[i][2]));
            for(int j=start;j<n;j++){
                pre[j] = pre[j]^beforeNum;
                pre[j] = pre[j]^aftereNum;
            }
        }else{
            int l = queries[i][1]-1;
            int r = queries[i][2]-1;
            if (l == 0) {
                ans.push_back(pre[r].count());
            }else {
                bitset<1001> xorval = pre[r]^ pre[l - 1];
                ans.push_back(xorval.count());
            }
        }
    }
    return ans;
}

void sol(){
    int n;
    cin>>n;
    vi arr(n);
    ll q;
    cin>>q;
    fr(i,n) cin>>arr[i];
    vvi queries(q);
    fr(i,q){
        ll temp1, temp2,temp3;
        cin>>temp1>>temp2>>temp3;
        queries[i].pb(temp1);
        queries[i].pb(temp2);
        queries[i].pb(temp3);
    }
    vi ans = solve(n,q,arr,queries);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}

// 1
// 4
// 4
// 2 4 2 1
// 1 4 2
// 2 1 4
// 1 1 4
// 2 2 3