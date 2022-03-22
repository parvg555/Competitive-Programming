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

int solve(int N, int K, vector<int> arr){
    vector<pair<int,int>> students(N);
    for(int i=0;i<N;i++){
        students[i] = make_pair(arr[i],i+1);
    }
    sort(students.begin(),students.end());
    int groups = N;
    int time  = 0;
    bool chairs[N] = {false};
    for(int i=0;i<N;i++){
        time = students[i].first;
        if((students[i].second-2 >= 0 && chairs[students[i].second-2] ) && (students[i].second < N && chairs[students[i].second])){
            groups-=2;
        }else if((students[i].second-2 >= 0 && chairs[students[i].second-2] ) || (students[i].second < N && chairs[students[i].second])){
            groups--;
        }
        chairs[students[i].second-1] = true;
        if(groups<=K){
            return time;
        }
    }
    return -1;
}

void sol(){
    ll n,k;
    cin>>n>>k;
    vi arr(n);
    fr(i,n) cin>>arr[i];
    cout<<solve(n,k,arr)<<"\n";
}

int main(void){
    fast;
    test(t){
        sol();
    }
}