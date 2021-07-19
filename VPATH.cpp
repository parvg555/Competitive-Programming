#include<iostream>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        long long ans = 0;
        int arr[n+1];
        for(int i=0;i<=n;i++){
            arr[i] = 1;
        }
        int i = 2;
        while(i<=n){
            int j = m%i;
            ans  += arr[j];
            while(j<=n){
                arr[j]++;
                j+=i;
            }
            i++;
        }
        cout<<ans<<"\n";
    }
}