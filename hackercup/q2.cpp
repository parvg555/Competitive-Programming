#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define ff first
#define ss second
#define google(x) cout << "Case #" << x << ": "
const int M = 1e9+7;

int main(){
    freopen("hacker cup/Round1/weak_typing_chapter_2_input.txt", "r", stdin);
    freopen("hacker cup/Round1/weak_typing_chapter_2_output.txt", "w", stdout);
    int T=1; cin>>T;
    for(int t = 1; t<=T; t++){
        int n; cin>>n; 
        string s; cin>>s;
        ll prev = 0;
        ll ans = 0;
        char last = '#';
        int id = -1;
        for(int i = 0; i< s.length(); i++){
            if(s[i]=='F'){
                ans += prev;
                ans %= M;
            }
            else{
                if(last=='#'){
                    last = s[i];
                    id = i;
                    ans += prev;
                    ans %= M;
                }
                else{
                    if(last==s[i]){
                        ans += prev;
                        ans %= M;
                        id = i;
                    }
                    else{
                        last = s[i];
                        prev += id+1;
                        ans += prev;
                        ans %=M;
                        prev %= M;
                        id = i;
                    }
                }
            }
        }
        google(t);
        cout<<ans<<endl;

    }
    return 0;
}
