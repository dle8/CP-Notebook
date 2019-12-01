#include <bits/stdc++.h>
using namespace std;

class ChipRace {
public:
    vector<double> chances(vector<int> chips) {
        int total = accumulate(chips.begin(), chips.end(), 0);
        int num = round(total / (double)(5));
        int n = chips.size();
        vector<double> res(n, 0.0);
        for (int i = 0; i < n; ++i) {
            for (int pos = 1; pos <= num; ++pos) {
                // generate a subset of pos - 1 elements
                for (int k = 0; k < (1 << n) - 1; ++k) {
                    if (__builtin_popcount(k) == pos - 1 && !((k >> i) & 1)) {
                        vector<int> prevs;
                        for (int pos_bit = 0; pos_bit < n; ++pos_bit) {
                            if ((k >> pos_bit) & 1) {
                                prevs.push_back(pos_bit);
                            }
                        }
                        do {
                            int tmp = total;
                            double prev_prob = 1.0;
                            for (int u: prevs) {
                                prev_prob *= (double)(chips[u]) / tmp;
                                tmp -= chips[u];
                            }
                            res[i] += prev_prob * (double)chips[i] / tmp;
                        } while (next_permutation(prevs.begin(), prevs.end()));
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> chips;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        chips.push_back(x);
    }
    ChipRace c;
    vector<double> res = c.chances(chips);
    copy(res.begin(), res.end(), ostream_iterator<double>(cout, " "));
    return 0;
}