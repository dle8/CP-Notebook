// Source: https://codeforces.com/blog/entry/54090

std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
    std::fill (is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 2; i * j < n; ++j)
            is_composite[i * j] = true;
    }
}
