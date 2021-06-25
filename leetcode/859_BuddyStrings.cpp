#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        set<char> vis;
        vector<vector<char>> miss;
        if (s.size() != goal.size()) return false;
        else if (s == goal) return set<char>(s.begin(), s.end()).size() < s.size();
        for (int i = 0; i < s.size(); i++)
            if (miss.size() > 2) return false;
            else if (s[i] != goal[i]) miss.push_back({s[i], goal[i]});
        return miss.size() == 2 and miss[0][0] == miss[1][1] and miss[0][1] == miss[1][0];
    }
};