#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
using namespace std;

typedef long long ll;

bool diff(string file1, string file2) {
  ll ans1, ans2;
  ifstream out(file1.c_str());
  out >> ans1;
  ifstream ans(file2.c_str());
  ans >> ans2;
  cout << ans1 << " " << ans2 << '\n';
  return (ans1 == ans2);
}

int main() {
  long sign[] = {-1, 1};
  FOR(current_test, 1, 100) {
//     use rng instead of rand(). 
//     for exp: generate an long n randomly: long n = rng();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ofstream inp("input.txt");

    // input making goes here.

    inp.close();
    system("g++ -o run test2.cpp");
    system("./run");
    // system("g++ -o run test.cpp");
    // system("./run");
    system("javac test.java");
    system("java test");
    if (diff("ans.txt", "output.txt") == 0) {
      cout << "Test #" << current_test << ": WRONG!";
      break;
    }
    else cout << "Test #" << current_test << ": CORRECT";
    cout << '\n';
  }
  return 0;
}
