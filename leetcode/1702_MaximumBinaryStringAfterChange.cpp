#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.length();
        
        stack <int> pos;
        
        for(int i = n-1;i>=0;i--){
            if(binary[i] == '0'){
                pos.push(i);
            }
        }
        
        for(int i=0;i<n-1;i++){
            if(binary[i] == '0'){
                pos.pop();
                if(binary[i+1] == '0'){
                    binary[i] = '1';
                }else{
                    if(pos.size()>0){
                        binary[i] = '1';
                        binary[i+1] = '0';
                        binary[pos.top()] = '1';
                        pos.pop();
                        pos.push(i+1);
                    }
                }
            }
        }
        return binary;
    }
};


//NAIVE APPROACH

// class Solution {
// public:
//     string maximumBinaryString(string binary) {
//         if(binary.length() == 1){
//             return binary;
//         }
//         int n = binary.length();
//         for(int i=0;i<n;i++){
//             if(binary[i] == '0'){
//                 if(i+1<n && binary[i+1] == '0'){
//                     binary[i] = '1';
//                 }else{
//                     int pos = i;
//                     for(int j = i+1;i<n && j<n;j++){
//                         if(binary[j] == '0'){
//                             pos = j;
//                             break;
//                         }
//                     }
//                     for(int j = pos;j>i;j--){
//                         if(j-1>=0 && j-1>i){
//                             binary[j] = '1';
//                             binary[j-1] = '0';
//                         }
//                     }
//                     if(pos!=i){
//                         binary[i] = '1';
//                     }
//                 } 
//             }
//             //cout<<binary<<"\n";
//         }
//         return binary;
//     }
// };