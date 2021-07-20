#include<bits/stdc++.h>
using namespace std;

int findone(vector <int> x){

    for(int i=0;i<x.size();i++){
        if(i!=0 && x[i]==0 && x[i-1]==1){
            return -1*(i-1);
        }
        if(i!=(x.size()-1) && x[i]==0 && x[i+1]==1){
            return i+1;
        }
    }

    return x.size()+1;
}

int calculate(int n, vector <int> x, vector <int> pos){
   cout<<"in calculate function"<<endl;
   int count = 0;
   int p=0;
    vector <int> vect(n,1);
    while(x != vect){
        p = findone(x);
        cout<<"value of p = "<<p<<endl;
        if(p<0){
            p=p*-1;
            cout<<"left"<<endl;
            x[p-1]=1;
            count = count + (pos[p]-pos[p-1]);

        }else{
            cout<<"right"<<endl;
            x[p+1]=1;
            count = count + (pos[p+1]-pos[p]);
        }

        for(auto m = x.begin(); m!=x.end();++m){
            cout<<*m<<" ";
        }
        cout<<endl;
    }

    return count;
}

int main(void){
    int t;
    t=1;
    //cin>>t;
    while(t>0){
        int n;
        vector <int> x;
        vector <int> pos;
        //for(int i=0;i<n;i++){
         //   int p;
         //   cin>>p;
        //    x.push_back(p);
       // }
       // for(int i=0;i<n;i++){
        //    int l;
        //    cin>>l;
         //   pos.push_back(l);
        //}

        n = 6;

        x.push_back(0);
        x.push_back(1);
        x.push_back(0);
        x.push_back(0);
        x.push_back(1);
        x.push_back(0);

        pos.push_back(1);
        pos.push_back(3);
        pos.push_back(6);
        pos.push_back(9);
        pos.push_back(10);
        pos.push_back(12);

        int ans = calculate(n,x,pos);
        cout<<ans<<endl;
        t--;
    }
}