#include<bits/stdc++.h>
using namespace std;


void calculate(vector <int> s, int n){
    vector <int> scopy;
    for(int i=0;i<s.size();i++){
        scopy.push_back(s[i]);
        //cout<<s[i]<<" ";
    }
    //cout<<endl;
    for(int i=0;i<s.size();i++){
        s[i]=scopy[i];
        //cout<<s[i]<<" ";
    }
    //cout<<endl;
    sort(scopy.begin(),scopy.end());
    scopy.clear();
    int largest = scopy[s.size()-1];
    int second = scopy[s.size()-2];
    //cout<<"largest - "<<largest<<" second - "<<second<<endl;
    vector <int> lp;
    vector <int> sp;

    for(int i=0;i<s.size();i++){
        if(s[i]==largest){
            lp.push_back(i);
            //cout<<i<<" ";
        }
        //cout<<endl;
        if(s[i]==second){
            sp.push_back(i);
            //cout<<i<<" ";
        }
    }

    //cout<<endl;

    int lpos,spos;
    int diff=0;

    for(int i=0;i<lp.size();i++){
        for(int j=0;j<sp.size();j++){
            if(abs(lp[i]-sp[j])>=diff){
                diff = abs(lp[i]-sp[j]);
                lpos=lp[i];
                spos=sp[j];
            }
        }
    }

   // cout<<lpos<<" "<<spos<<endl;
    
    
    if(abs(lpos-spos)==1){
        cout<<"0"<<endl;
        cout<<"0";
        return;
    }
    
    cout<<largest+second<<endl;
    cout<<lpos-spos<<" ";
    
    if(spos<lpos){
        for(int i=spos;i<lpos;i++){
            cout<<i+1<<" ";
        }
    }else{
        for(int i=lpos+1;i<spos+1;i++){
            cout<<i+1<<" ";
        }
    }
    
    cout<<endl;
    scopy.clear();

}

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int f;
        vector <int> s;
        for(int i=0;i<n;i++){
            cin>>f;
            s.push_back(f);
        }
        calculate(s,n);
        
    }
}