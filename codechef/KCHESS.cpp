#include<bits/stdc++.h>
using namespace std;

bool checktop(vector <pair<int,int>> knights, pair <int,int> pos){
    auto top_right = make_pair(pos.first-2,pos.second+1);
    if(find(knights.begin(),knights.end(),top_right) != knights.end()){
        return false;
    }
    auto top_left = make_pair(pos.first-2,pos.second-1);
    if(find(knights.begin(),knights.end(),top_left) != knights.end()){
        return false;
    }

    return true;
}

bool checkbottom(vector <pair<int,int>> knights, pair <int,int> pos){
    auto bottom_right = make_pair(pos.first+2,pos.second+1);
    if(find(knights.begin(),knights.end(),bottom_right) != knights.end()){
        return false;
    }
    auto bottom_left = make_pair(pos.first+2,pos.second-1);
    if(find(knights.begin(),knights.end(),bottom_left) != knights.end()){
        return false;
    }

    return true;
}

bool checkright(vector <pair<int,int>> knights, pair <int,int> pos){
    auto right_top = make_pair(pos.first-1,pos.second+2);
    if(find(knights.begin(),knights.end(),right_top) != knights.end()){
        return false;
    }
    auto right_bottom = make_pair(pos.first+1,pos.second+2);
    if(find(knights.begin(),knights.end(),right_bottom) != knights.end()){
        return false;
    }

    return true;
}

bool checkleft(vector <pair<int,int>> knights, pair <int,int> pos){
    auto left_top = make_pair(pos.first-1,pos.second-2);
    if(find(knights.begin(),knights.end(),left_top) != knights.end()){
        return false;
    }
    auto left_bottom = make_pair(pos.first+1,pos.second-2);
    if(find(knights.begin(),knights.end(),left_bottom) != knights.end()){
        return false;
    }

    return true;
}

bool checkthispos(vector<pair<int,int>> knights, pair <int,int> pos){
    if(checktop(knights,pos) && checkbottom(knights,pos) && checkleft(knights,pos) && checkright(knights,pos)){
        return true;
    }
    return false;
}

bool check(vector <pair<int,int>> knights, pair <int,int> king){

    if(checkthispos(knights,king) == true){
        //cout<<"at safe pos"<<endl;
        return false;
    }

    auto up = make_pair(king.first-1,king.second);
    if(checkthispos(knights,up) == true){
        //cout<<"going up safe"<<endl;
        return false;
    }

    auto up_right = make_pair(king.first-1,king.second+1);
    if(checkthispos(knights,up_right) == true){
        //cout<<"going up right safe"<<endl;
        return false;
    }

    auto up_left = make_pair(king.first-1,king.second-1);
    if(checkthispos(knights,up_left) == true){
        //cout<<"going up left safe"<<endl;
        return false;
    }

    auto down = make_pair(king.first+1,king.second);
    if(checkthispos(knights,down) == true){
        //cout<<"going down safe"<<endl;
        return false;
    }

    auto down_right = make_pair(king.first+1,king.second+1);
    if(checkthispos(knights,down_right) == true){
        //cout<<"going down right safe"<<endl;
        return false;
    }

    auto down_left = make_pair(king.first+1,king.second-1);
    if(checkthispos(knights,down_left) == true){
        //cout<<"going down left safe"<<endl;
        return false;
    }

    auto right = make_pair(king.first,king.second+1);
    if(checkthispos(knights,right) == true){
        //cout<<"going right safe"<<endl;
        return false;
    }

    auto left = make_pair(king.first,king.second-1);
    if(checkthispos(knights,left) == true){
        //cout<<"goind left safe"<<endl;
        return false;
    }

    return true;
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <pair<int,int>> knights;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            knights.push_back(make_pair(x,y));
        }
        int ki,kj;
        cin>>ki>>kj;
        auto king = make_pair(ki,kj);
        bool ans;

        ans = check(knights,king);
        if(ans == true){
            cout<<"Yes";
        }else{
            cout<<"No";
        } 
    }
}