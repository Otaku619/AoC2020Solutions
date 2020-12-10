#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
map<string, vector<pair<string, long>>> mm;
long ans;

void solve(long x, string s) {
  ans += (x * m[s]);
  for (auto gg : mm[s])
    solve(gg.second * x, gg.first);
}

int main() {
  string s;
  while (getline(cin, s)) {
    vector<string> vs;
    string ss = "";
    for (char ch : s) {
      if (ch == ' ') {
        vs.push_back(ss);
        ss = "";
      } else
        ss += ch;
    }
    if (vs[4] == "no") {
      m[vs[0] + " " + vs[1]] = 0;
    } else {
      for (int i = 4; i < vs.size(); i += 4) {
        m[vs[0] + " " + vs[1]] += (vs[i][0] - '0');
        mm[vs[0] + " " + vs[1]].push_back(
            {vs[i + 1] + " " + vs[i + 2], vs[i][0] - '0'});
      }
    }
  }
  solve(1, "shiny gold");
  cout << ans;
}
