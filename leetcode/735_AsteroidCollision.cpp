#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> l;
        for(int i=0;i<asteroids.size();i++){
            if(l.size()>0){
                int c = asteroids[i];
                if(c*l.top() > 0 || l.top() < 0 ){
                    l.push(c);
                    continue;
                }
                while(l.size()>0 && c*l.top() < 0 && l.top()>0 && abs(l.top())<abs(c)){
                    l.pop();
                }
                if(l.size()>0 && l.top()> 0){
                    if(abs(l.top()) == abs(c) && c*l.top() < 0 ){
                        l.pop();
                    }
                }else{
                    l.push(c);
                }
                
            }else{
                l.push(asteroids[i]);
            }
        }
        vector <int> answer;
        while(l.size()>0){
            answer.push_back(l.top());
            l.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};