//Bạn đang chuẩn bị trang trí một chiếc bảng trắng bằng các trang giấy màu hình vuông. Mỗi trang
//giấy có thể có kích thước khác 0 tuỳ ý. Bạn đã chọn được 𝑁 màu, đánh số từ 0 đến 𝑁 − 1, và bạn
//sẽ dùng đúng 1 trang giấy mỗi màu.
//Cho 4 dãy số nguyên 𝑋𝑎, 𝑌𝑎, 𝑋𝑏, 𝑌𝑏, mỗi dãy có đúng 𝑁 phần tử. Trang giấy với màu 𝑖 phải được đặt sao cho tâm của nó
//có toạ độ 𝑋𝑎[𝑖] , 𝑌𝑎[𝑖] hoặc 𝑋𝑏[𝑖] , 𝑌𝑏[𝑖] . Các cạnh của trang giấy phải song song với các trục toạ độ và không có 2
//trang giấy đặt đè lên nhau. (Hai hình vuông được coi là đè lên nhau nếu giao điểm của chúng có diện tích khác 0).
//Hãy tính kích thước lớn nhất có thể của trang giấy nhỏ nhất trong số 𝑁 trang. Kích thước của một trang giấy hình vuông
//là độ dài cạnh của nó. Nếu không thể đặt được tất cả 𝑁 trang giấy thì in ra 0.
//Dữ liệu
//- Dòng đầu ghi số nguyên 𝑁.
//- Dòng 2 ghi 𝑁 số nguyên thể hiện dãy số 𝑋𝑎
//- Dòng 3 ghi 𝑁 số nguyên thể hiện dãy số 𝑌𝑎
//- Dòng 4 ghi 𝑁 số nguyên thể hiện dãy số 𝑋𝑏
//- Dòng 5 ghi 𝑁 số nguyên thể hiện dãy số 𝑌𝑏
//Kết quả
//- Gồm 1 dòng duy nhất chứa một số nguyên là kết quả của bài toán, hoặc số 0 nếu vô
//nghiệm.
//Giới hạn
//- 2 ≤ 𝑁 ≤ 50.
//- 0 ≤ 𝑋𝑎[𝑖] , 𝑌𝑎[𝑖] , 𝑋𝑏[𝑖] , 𝑌𝑏[𝑖] ≤ 1,000,000,000.

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

ostream& operator<<(ostream& os, const Point &p) {
    return os << p.first << " " << p.second;
}

bool overlap(Point l1, Point r1, Point l2, Point r2) {
    if (l1.first >= r2.first|| l2.first >= r1.first) return false;
    if (l1.second <= r2.second || l2.second <= r1.second) return false;
    return true;
}

bool overlap(pii pp1, pii pp2, int len) {
    return overlap({double(pp1.first) - len / 2.0, double(pp1.second) + len / 2.0}, {double(pp1.first) + len / 2.0, double(pp1.second) - len / 2.0}, {double(pp2.first) - len / 2.0, double(pp2.second) + len / 2.0}, {double(pp2.first) + len / 2.0, double(pp2.second) - len / 2.0});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p1[i].first;
    for (int i = 1; i <= n; ++i) cin >> p1[i].second;
    for (int i = 1; i <= n; ++i) cin >> p2[i].first;
    for (int i = 1; i <= n; ++i) cin >> p2[i].second;

    int left = 1, right = pow(10, 9);
    while (left <= right) {
        int mid = (left + right) / 2;
        TwoSat ts(n);
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (overlap(p1[i], p1[j], mid)) ts.either(~(i - 1), ~(j - 1));
                if (overlap(p1[i], p2[j], mid)) ts.either(~(i - 1), j - 1);
                if (overlap(p2[i], p1[j], mid)) ts.either(i - 1, ~(j - 1));
                if (overlap(p2[i], p2[j], mid)) ts.either(i - 1, j - 1);
            }
        }
        if (ts.solve()) {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << right;
    return 0;
}