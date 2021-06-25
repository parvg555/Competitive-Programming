// #include<bits/stdc++.h>
// using namespace std;

// int main(void){
//     int t;
//     cin>>t;
//     vector <int> r;
//     while(t--){
//         int temp;
//         cin>>temp;
//         r.push_back(temp);
//     }
//     int sz = r.size();
//     int ans = 0;
//     int size = 0;
//     for(int i=0;i<sz;i++){
//         if(r[i]<r[i+1]){
//             size++;
//         }else{
//             if(ans<size){
//                 ans=size;
//             }
//             size=0;
//         }
//     }
//     cout<<ans<<"\n";
// }

#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main(void){
    int arr[100];
    memset(arr,0,sizeof(arr));
    arr[1] = 0;
    arr[2] = 12;
    for(int i=3;i<100;i++){
        arr[i]= ((4*arr[i-1])%mod - (3*arr[i-2])%mod)%mod;
        cout<<(arr[i]/12)<<" ";
    }
}

