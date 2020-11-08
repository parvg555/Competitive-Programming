#include<bits/stdc++.h>
using namespace std;

int main(void){

    int t;
    cin>>t;
    while(t>0){
        string s;
        char p;
        cin>>s;
        int holes = 0;
        for(int i=0;i<s.length();i++){
            p = s.at(i);
            if(p=='A'||p=='D'||p=='O'||p=='P'||p=='Q'||p=='R'){
                holes=holes+1;
            }else if(p=='B'){
                holes=holes+2;
            }
        }
        cout<<holes<<endl;
        t--;
    }

}