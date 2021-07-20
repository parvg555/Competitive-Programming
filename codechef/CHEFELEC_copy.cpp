#include<bits/stdc++.h>
using namespace std;

int makeone(vector <int> &x, int p, vector <int> pos){
    int count = 0;
    int left=0,right=0;
    if(p!=0){
        left = pos[p]-pos[p-1];
    }
    if(p!=pos.size()){
        right = pos[p+1]-pos[p];
    }
    
    if(left!=0 && right!=0){
        if(left<right){
            if(x[p-1]==1){
                x[p] =1;
                count = count + left;
            }else{
                count = count + makeone(x,p-1,pos);
                x[p]=1;
                count = count + left;
            }
        }else{
            if(x[p+1]==1){
                x[p]=1;
                count = count + right;
            }else{
                count = count + makeone(x,p+1,pos);
                x[p]=1;
                count = count + right;
            }

        }
    }else{
        if(p==0){
            //cout<<"problem here"<<endl;
            if(x[p+1]==1){
                //cout<<"true"<<endl;
                x[p]=1;
                count = count + right;
            }else{
                count = count + makeone(x,p+1,pos);
                x[p]=1;
                count = count + right;
            }
        }else{
            if(x[p-1]==1){
                x[p] =1;
                count = count + left;
            }else{
                count = count + makeone(x,p-1,pos);
                x[p]=1;
                count = count + left;
            }
        }

    }

    return count;
}

int calculate(int n, vector <int> &x, vector <int> pos){
    //cout<<"in calculate"<<endl;
    int count=0;
    vector <int> vect(n,1);

    while(x != vect){
        for(int i=0;i<x.size();i++){
            if(x[i]==0){
                //cout<<"called make one for - "<<i<<endl;
                count = count + makeone(x,i,pos);
            }
        }
    }
    return count;
}

int main(void){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector <int> x;
        vector <int> pos;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            x.push_back(p);
        }
        for(int i=0;i<n;i++){
            int l;
            cin>>l;
            pos.push_back(l);
        }

       int ans = calculate(n,x,pos);
       cout<<ans<<endl;
    }
}