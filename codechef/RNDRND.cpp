#include<bits/stdc++.h>
#include<vector>
using namespace std;

int next(int n,int current,int gap){

    for(int i=0;i<gap;i++){
        if(current<n){
            current++;
        }else{
            current=1;
        }
    }

    return current;
}
int exists(vector <int> del,int p){
//cout<<"size in exists - "<<del.size()<<endl;
    for(int i=0;i<del.size();i++){
        if(del[i]==p){
            cout<<"element found"<<endl;
            return i;
        }
    }
    return del.size() + 1;
}

int calculate(vector <int> del, int n, int m){
    vector <int> del_copy = del;
    int steps = n; 
    int pos = 1;
    for(int i=1;i<n;i++){
        //cout<<"trying for i = "<<i<<endl;
        pos = 1;
        int count = 0;
        del = del_copy;
        while(del.size() !=0 ){   
            //cout<<"position - "<<pos<<endl;
            int p = exists(del,pos);
            //cout<<"value of p = "<<p<<endl;
            if(p<=del.size()){
                //cout<<"deleting"<<endl;
                del.erase(del.begin() + p);
            }
            //cout<<del.size()<<endl;
            count++;
            //cout<<"count = "<<count<<endl;
            pos = next(n,pos,i);
            //cout<<"pos = "<<pos<<endl;
            if(count>steps){
                //cout<<"count>steps"<<endl;
                break;
            }
        }
        if(count<steps && count!=0){
            steps = count;
        }
    }
    return steps;
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector <int> del;
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        del.push_back(p);
    }

    int ans = calculate(del,n,m);
    cout<<ans;

}