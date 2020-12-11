#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int ans = 0;
void solve() {
  int cnt = 0;
  vector<string> t;
  t = v;
  size_t h = v.size();
  size_t w = v[0].size();
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] != '.') {
        int c = 0;
        ans += v[i][j] == '#';
        char ch = '#';
        c += (j < w - 1 && v[i][j + 1] == ch) + (j > 0 && v[i][j - 1] == ch) +
             (i > 0 && v[i - 1][j] == ch) + (i < h - 1 && v[i + 1][j] == ch) +
             (i < h - 1 && j < w - 1 && v[i + 1][j + 1] == ch) +
             (i < h - 1 && j > 0 && v[i + 1][j - 1] == ch) +
             (i > 0 && j < w - 1 && v[i - 1][j + 1] == ch) +
             (i > 0 && j > 0 && v[i - 1][j - 1] == ch);
        if (v[i][j] == '#' && c >= 4)
          t[i][j] = 'L', cnt++;
        if (v[i][j] == 'L' && c == 0)
          t[i][j] = '#', cnt++;
      }
    }
  }
  if (cnt) {
    v = t, ans = 0;
    solve();
  }
}

int main() {
  string s;
  while (cin >> s)
    v.push_back(s);
  solve();
  cout << ans;
};
