// Sau nhiều năm chiến tranh liên miên giữa các Đảng phái, nước 𝑋 rơi vào tình trạng đói nghèo, người dân khổ cực trăm
// bề. Nhận thức được việc nếu tiếp tục kéo dài chiến tranh sẽ càng bất lợi cho đất nước, các Đảng trong nước 𝑋 đã quyết
// định họp bàn nhau lại, bỏ qua hiềm khích chung để xây dựng lại đất nước.
// Việc làm đầu tiên sẽ là họp để chọn ra các vị đại biểu để lập nên Quốc Hội. Mỗi Đảng đã chọn ra 2 gương mặt tiêu biểu
// nhất cho Đảng của mình để ứng cử vào Quốc Hội. Tuy nhiên trong số các vị đại biểu của các Đảng này thì có một số vị
// vì li do cá nhân trong chiến tranh nên rất căm thù nhau (ví dụ như ông 𝐴 của Đảng 𝑃 ghét ông 𝐵 của Đảng 𝑄, …). Vì li
// do chính trị mà trong Quốc Hội mỗi Đảng chỉ được phép có một người mà thôi. Ngoài ra để đảm bảo Quốc Hội làm việc 1
// cách công minh thì các vị đại biểu Quốc Hội phải được chọn ra sao cho đảm bảo không có ai thù ghét ai cả, nếu không
// rất có thể chiến tranh sẽ lại nổ ra. Bạn là một người yêu chuộng hoà bình đồng thời là 1 lập trình viên siêu hạng.
// Hãy xem xét xem liệu có 1 cách tổ chức Quốc Hội sao cho thoả mãn được các yêu cầu đề ra hay không?
// Dữ liệu
// - Dòng 1: 2 số nguyên 𝑁 và 𝑀 tương ứng là số Đảng và số mối quan hệ thù ghét nhau giữa các ứng viên của các Đảng.
// Các Đảng được đánh số từ 1 đến 𝑁. Hai ứng viên của Đảng 𝑖 sẽ có số hiệu là 𝑖 ∗ 2 − 1 và 𝑖 ∗ 2.
// - 𝑀 dòng tiếp theo mỗi dòng gồm 2 số nguyên 𝑢, 𝑣 cho biết người 𝑢 và người 𝑣 ghét nhau (1 ≤ 𝑢 < 𝑣 ≤ 2𝑁).
// Kết quả
// - Dòng 1: Ghi 0 nếu không có phương án thoả mãn và 1 nếu có phương án thoả mãn.
// - Nếu dòng 1 là 1 thì dòng thứ 2 ghi ra 𝑁 số nguyên là số hiệu của các thành viên được chọn vào
// Quốc Hội.
// Giới hạn
// - 1 ≤ 𝑁 ≤ 8000.
// - 1 ≤ 𝑀 ≤ 20000.

#include <bits/stdc++.h>
using namespace std;

#define maxn 50 + 10
pair<int, int> p1[maxn], p2[maxn];

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

int get_party(int member) {
    if (member % 2 == 0) return -member / 2;
    return (member + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    TwoSat ts(n);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        u = get_party(u);
        v = get_party(v);
        if (u < 0) u = ~(-u - 1);
        else u--;
        if (v < 0) v = ~(-v - 1);
        else v--;
        ts.either(~u, ~v);
    }
    if (ts.solve()) {
        cout << 1 << '\n';
        for (int i = 0; i < ts.values.size(); ++i) {
            if (ts.values[i] == 1) cout << (2 * (i + 1) - 1) << " ";
            else cout << (2 * (i + 1)) << " ";
        }
    } else cout << 0;
    return 0;
}