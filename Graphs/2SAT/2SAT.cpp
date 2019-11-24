#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef pair<double, double> Point;
typedef vector<int> vi;

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = fa lse , 1 = true
    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    void either(int f, int j) {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }

    vi val, comp, z; int time = 0;

    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        trav(e, gr[i]) if (!comp[e]) low = min(low, val[e] ?: dfs(e));
        if (low == val[i]) do {
                x = z.back(); z.pop_back();
                comp[x] = low;
                if (values[x >>1] == -1)
                    values[x >>1] = x & 1;
            } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0); comp = val;
        rep(i,0,2 * N) if (!comp[i]) dfs(i);
        rep(i,0, N) if (comp[2 * i] == comp[2 * i + 1]) return false;
        return true;
    }
};