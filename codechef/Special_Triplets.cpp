#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        //cout<<"n: "<<n<<"\n";
        int ans = 0;
        for(int c = 1;c<=n;c++){
            int b = c;
            while(b<=n){
                if(b%c==0){
                    int a = c;
                    while(a<=n){
                        //cout<<"a: "<<a<<"\n";
                        //cout<<"b: "<<b<<"\n";
                        //cout<<"c: "<<c<<"\n";
                        if(a%b == c){
                            ans++;
                        }
                        a+=b;
                    } 
                }
                b+=c;
            }
        }
        cout<<ans<<"\n";
    }
}