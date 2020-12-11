#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))

/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        String_Operations.cpp
#  Created On:      10/12/2020
#  Problem Code:    STROPERS.cpp
=============================================================================*/


void sol(){
    set <tuple <int,int,int>> ans; 
    string s;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        int ones = 0;
        int oddones = 0;
        for(int j=1;j<=s.length()-i;j++){
            if(s[i+j-1] == '1'){
                ones++;
            }
            if(s[i+j-1] == '0' && ones%2!=0 && ones>0){
                oddones++;
            }
            if(ones%2==0 && ones>0){
                ans.insert(make_tuple(j,ones,(j-ones)-oddones));
            }else{
                ans.insert(make_tuple(j,ones,oddones));
            }
        }
    }
    cout<<ans.size()<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}


///this is my answerr for small test cases i.e. for 10 marks
/*
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
*/
/*=============================================================================
#  Author:          Parv Gupta - https://github.com/parvg555/
#  Email:           parvg555@gmail.com
#  FileName:        STROPERS2.cpp
#  Created On:      08/12/2020
=============================================================================*/
/*

set <string> allstrings;
int ans = 0;


void makecombination(string s){
    //cout<<"string inserted - "<<s<<endl;
    allstrings.insert(s);
    
    if(s.length()<3){
        return;
    }

    int ones[s.length() + 1];
    memset(ones,0,sizeof(ones));
    int on = 0;
    for(int i=0;i<s.length();i++){
        ones[i] = on;
        if(s[i]=='1'){
            on++;
        }
    }
    
    ones[s.length()] = on;
    for(int i=0;i<=s.length();i++){
        for(int j=1;j<=s.length()-i;j++){
            if((ones[i+j]-ones[i])%2==0 && (ones[i+j]-ones[i])>1){
                string copy = s;
                reverse(copy.begin() + i,copy.begin()+i+j);
                //cout<<"combination made - "<<copy<<endl;
                //auto f = find(allstrings.begin(),allstrings.end(),copy);
                if(allstrings.count(copy) == 0){
                    makecombination(copy);
                }
            }
            
        }
    }

}

void sol(){
    string s;
    cin>>s;
    ans = 0;
    allstrings.clear();
    for(int i=0;i<=s.length();i++){
        for(int j=1;j<=s.length()-i;j++){
            string temp = s.substr(i,j);
            //auto f = find(allstrings.begin(),allstrings.end(),temp);
            if(allstrings.count(temp) == 0){
                //cout<<temp<<endl;
                ans = ans + 1;
                makecombination(temp);
            } 
        }
    }
    cout<<ans<<endl;
}

int main(void){
    fast;
    test(t){
        sol();
    }
}
*/