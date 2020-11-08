#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &vect) 
{ 
   vect[1]=30;
} 
   
int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 
   
    func(vect); 
  
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; 
   
    return 0; 
} 