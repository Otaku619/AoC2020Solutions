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
        int c = 0, m, n;
        ans += v[i][j] == '#';
        char ch = '#';
        for (m = i + 1; m < h && v[m][j] == '.'; m++)
          ;
        c += (m >= 0 && m < h ? v[m][j] == ch : 0);
        for (m = i - 1; m > -1 && v[m][j] == '.'; m--)
          ;
        c += (m >= 0 && m < h ? v[m][j] == ch : 0);
        for (n = j - 1; n > -1 && v[i][n] == '.'; n--)
          ;
        c += (n >= 0 && n < w ? v[i][n] == ch : 0);
        for (n = j + 1; n < w && v[i][n] == '.'; n++)
          ;
        c += (n >= 0 && n < w ? v[i][n] == ch : 0);
        for (m = i + 1, n = j + 1; m < h && n < w && v[m][n] == '.'; n++, m++)
          ;
        c += (n >= 0 && n < w && m >= 0 && m < h ? v[m][n] == ch : 0);
        for (m = i - 1, n = j + 1; m > -1 && n < w && v[m][n] == '.'; n++, m--)
          ;
        c += (n >= 0 && n < w && m >= 0 && m < h ? v[m][n] == ch : 0);
        for (m = i + 1, n = j - 1; n > -1 && m < h && v[m][n] == '.'; n--, m++)
          ;
        c += (n >= 0 && n < w && m >= 0 && m < h ? v[m][n] == ch : 0);
        for (m = i - 1, n = j - 1; m > -1 && n > -1 && v[m][n] == '.'; n--, m--)
          ;
        c += (n >= 0 && n < w && m >= 0 && m < h ? v[m][n] == ch : 0);
        if (v[i][j] == '#' && c >= 5)
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
