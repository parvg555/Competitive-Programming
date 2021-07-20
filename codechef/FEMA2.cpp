#include<bits/stdc++.h>
using namespace std;

int score(int i, int j, int k, int sheets){
    return k+1-abs(j-i)-sheets;
}


void answer(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0;
    int sheets = 0;
    int sh[n];
    memset(sh,0,sizeof(sh));
    queue <int> iron;
    queue <int> magnet;
    for(int i=0;i<n;i++){
        sh[i] = sheets;
        if(s[i] == 'I'){
            bool flag = false;
            if(magnet.size()>0){
                while(magnet.size() > 0 && flag == false){
                    if(score(magnet.front(),i,k,sh[i]-sh[magnet.front()])>0){
                        magnet.pop();
                        flag = true;
                        ans++;
                    }else{
                        magnet.pop();
                    }
                }
                if(magnet.size() < 1 && flag == false){
                    iron.push(i);
                }
            }else{
                iron.push(i);
            }
        }else if( s[i] == 'M'){
            bool flag = false;
            if(iron.size()>0){
                while(iron.size() > 0 && flag == false){
                    if(score(iron.front(),i,k,sh[i]-sh[iron.front()])>0){
                        iron.pop();
                        flag = true;
                        ans++;
                    }else{
                        iron.pop();
                    }
                }
                if(iron.size()<1 && flag == false){
                    magnet.push(i);
                }

            }else{
                magnet.push(i);
            }
        }

        if(s[i]=='X'){
            while(!iron.empty()){
                iron.pop();
            }
            while(!magnet.empty()){
                magnet.pop();
            }
        }
        if(s[i]==':'){
            sheets++;
        }
    }
    cout<<ans<<endl;
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        answer();
    }
}