#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define test(t) \
    ll t;       \
    cin >> t;   \
    while (t--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(), arr.end()
#define fr(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))

void sol()
{
    string s, t;
    cin >> s >> t;
    sort(all(s));
    map<char, ll> mp;
    ll n = s.length();
    fr(i, n) mp[s[i]]++;
    string ans = "";
    if (t == "abc" && mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
    {
        bool flag = true;
        string temp = "";
        for (auto c : mp)
        {
            //cout << c.first << " " << c.second << "\n";
            if (c.first == 'a')
            {
                fr(i, c.second) ans += c.first;
            }
            else if (c.first == 'b')
            {
                fr(i, c.second) temp += c.first;
            }
            else if (c.first == 'c')
            {
                fr(i, c.second) ans += c.first;
                if (flag)
                {
                    ans += temp;
                    flag = false;
                }
            }
            else
            {
                if (flag)
                {
                    ans += temp;
                    flag = false;
                }
                fr(i, c.second) ans += c.first;
            }
        }
    }
    else
    {
        for (auto c : mp)
        {
            fr(i, c.second) ans += c.first;
        }
    }
    cout << ans << "\n";
}

int main(void)
{
    fast;
    test(t)
    {
        sol();
    }
}