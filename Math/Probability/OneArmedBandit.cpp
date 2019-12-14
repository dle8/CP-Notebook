#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll __gcd(ll A, ll B) {
    if (B == 0) return A;
    else return __gcd(B, A % B);
}

pll operator + (pll x, pll y) {
    if (x.second == 0) return y;
    else if (y.second == 0) return x;
    ll num = x.first * y.second + x.second * y.first;
    ll denum = x.second * y.second;
    ll tmp = __gcd(num, denum);
    return {num / tmp, denum / tmp};
}

pll operator * (pll x, pll y) {
    ll num = x.first * y.first;
    ll denum = x.second * y.second;
    ll tmp = __gcd(num, denum);
    return {num / tmp, denum / tmp};
}

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

class OneArmedBandit{
public:

    double progressiveJackPot(vector<string> wheels, string jackpotLine, vector<string> payoffTable) {
        ll n = wheels.size(), m = payoffTable.size();
        ll cnt[n][128];
        memset(cnt, 0, sizeof(cnt));
        for (ll i = 0; i < n; ++i) {
            for (char c: wheels[i]) cnt[i][int(c)]++;
        }
        for (int i = 0; i < jackpotLine.size(); ++i) {
            if (cnt[i][int(jackpotLine[i])] == 0) return -1;
        }
        vector<pll> prob;
        for (ll i = 0; i < m; ++i) {
            string line = payoffTable[i].substr(0, wheels[0].size());
            ll amount = stoi(payoffTable[i].substr(wheels[0].size() + 1));

            pll win = {1, 1};
            for (ll j = 0; j < line.size(); ++j) {
                if (line[j] == '-') {
                    win = win * make_pair(1, 1);
                    continue;
                }
                win = win * make_pair(cnt[j][int(line[j])], line.size());
            }
            win = win * make_pair(amount, 1);
            prob.push_back(win);
        }
        pll res = {0, 0};
//        for (pll p: prob) cout << p.first << " " << p.second << '\n';
        for (pll p: prob) res = res + p;
        return max(res.second - res.first, 0);
    }
};
//
//int main() {
//    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
//    int n; cin >> n;
//    vector<string> wheels;
//    for (int i = 1; i <= n; ++i) {
//        string str; cin >> str;
//        wheels.push_back(str);
//    }
//    string jackpotLine; cin >> jackpotLine;
//    int m; cin >> m;
//    vector<string> payoffTable;
//    cin.ignore();
//    for (int i = 1; i <= m; ++i) {
//        string str; getline(cin,str);
//        payoffTable.push_back(str);
//    }
//    OneArmedBandit sol;
//    cout << sol.progressiveJackPot(wheels, jackpotLine, payoffTable);
//    return 0;
//}
