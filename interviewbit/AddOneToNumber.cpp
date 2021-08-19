#include<bits/stdc++.h>
using namespace std;

vector<int>plusOne(vector<int> &a) {
    int n1=a.size();
    int startIndex=-1;
    for(int i=0;i<n1;i++)
    {
        if(a[i]!=0)
        {
            startIndex=i;
            break;
        }
    }
    if(startIndex==-1)
        return {1};
    int carry =1;
    for(int i = n1-1;i>=startIndex;i--)
    {
        int newCarry = ((carry+a[i]>9) ?((carry+a[i])/10):0);
        a[i] = (carry+a[i])%10;
        carry=newCarry;
    }
    auto first = a.begin() + startIndex;
    auto last = a.begin() + n1;
    vector<int> ans(first, last);
    if(carry)
        ans.insert(ans.begin(),carry);
    return ans;
}