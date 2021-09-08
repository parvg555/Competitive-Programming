#include<bits/stdc++.h>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool compareinterval(Interval i1, Interval i2){
    return i1.start < i2.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector <Interval> ans;
    stack <Interval> s;
    sort(intervals.begin(), intervals.end(), compareinterval);
    s.push(intervals[0]);
    int n = intervals.size();
    for(int i=1;i<n;i++){
        Interval top = s.top();
        if(top.end < intervals[i].start){
            s.push(intervals[i]);
        }else if(top.end < intervals[i].end){
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
