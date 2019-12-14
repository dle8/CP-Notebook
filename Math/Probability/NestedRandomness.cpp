#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

class NestedRandomness{
public:
    double probability(int n, int nestings, int target) {
        ld dp[n + 1][nestings + 1];
        memset(dp, 0.0, sizeof(dp));
        for (int i = target + 1; i <= n; ++i) dp[i][1] = 1.0 / (double)(i);
        for (int j = 2; j <= nestings; ++j) {
            for (int i = target + j; i <= n; ++i) {
                for (int k = 0; k < i; ++k) dp[i][j] += dp[k][j - 1];
                dp[i][j] *= 1 / (double)(i);
            }
        }
        return dp[n][nestings];
    }
};