#include<bits/stdc++.h>
using namespace std;

vector <int> ans;

void bfs(int n,int m, int num){
    queue <int> q;
    q.push(num);

    while(!q.empty()){
        int stepNum = q.front();
        q.pop();

        if(stepNum<=m && stepNum >= n){
            ans.push_back(stepNum);
        }

        if(num == 0 || stepNum > m ){
            continue;
        }

        int LastDigit = stepNum%10;
        int A = stepNum*10 + LastDigit-1;
        int B = stepNum*10 + LastDigit+1;

        if(LastDigit == 0){
            q.push(B);
        }else if(LastDigit == 9){
            q.push(A);
        }else{
            q.push(A);
            q.push(B);
        }
    }
}

vector<int> stepnum(int A, int B) {
    ans.clear();
    for(int i = 0;i<=9;i++){
        bfs(A,B,i);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
