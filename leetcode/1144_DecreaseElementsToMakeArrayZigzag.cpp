#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& arr) {
        int even = 0;
        int odd = 0;
        int n = arr.size();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(i==0){
                    if(arr[i]>=arr[i+1] && i+1<n){
                        even+=abs(arr[i]-arr[i+1])+1;
                    }
                }else if(i==n-1){
                    if(arr[i]>=arr[i-1]){
                        even+=abs(arr[i]-arr[i-1])+1;
                    }
                }else{
                    if(arr[i]>=arr[i-1] || arr[i]>=arr[i+1]){
                        even+=abs(arr[i]-min(arr[i-1],arr[i+1]))+1;
                    }
                }
            }else{
                if(i==n-1){
                    if(arr[i]>=arr[i-1]){
                        odd+=abs(arr[i]-arr[i-1])+1;
                    }
                }else{
                    if(arr[i]>=arr[i-1] || arr[i]>=arr[i+1]){
                        odd+=abs(arr[i]-min(arr[i-1],arr[i+1]))+1;
                    }
                }
            }
        }
        return min(odd,even);
    }
};