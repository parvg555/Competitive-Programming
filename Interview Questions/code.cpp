#include<bits/stdc++.h>
using namespace std;

int recurPosition(int i, int j, int n, int **arr){
    if(i==n-1 && j==n-1) return arr[i][j];
    if(i<n-1 && j < n-1){
        return arr[i][j] + max(recurPosition(i,j+1,n,arr),recurPosition(i+1,j,n,arr));
    }else if(i==n-1){
        return arr[i][j] + recurPosition(i,j+1,n,arr);
    }
     return arr[i][j] + recurPosition(i+1,j,n,arr);
}

int maxSum(int n, int **arr){
    int sum = recurPosition(0,0,n,arr);
    return sum;
}

int main(){
    int n;
    cin>>n;
    int **arr = new int *[n];
    for(int i=0;i<n;i++){
        arr[i] = new int [n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxSum(n,arr)<<"\n";
    return 0;
}