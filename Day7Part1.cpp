#include <bits/stdc++.h>
using namespace std;
map<string, bool> m;
map<string, vector<string>> mm;
long ans;

void dfs(string s) {
  for (auto gg : mm[s]) {
    if (m[gg]) {
      ans++;
      m[s] = 1;
      break;
    } else {
      dfs(gg);
      if (m[gg]) {
        ans++;
        m[s] = 1;
        break;
      }
    }
  }
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
    if (vs[4] != "no" && vs[0] + " " + vs[1] != "shiny gold") {
      for (int i = 5; i < vs.size(); i += 4) {
        if (vs[i] + " " + vs[i + 1] == "shiny gold" &&
            !m[vs[0] + " " + vs[1]]) {
          m[vs[0] + " " + vs[1]] = 1;
          ans++;
          // cout << vs[0] << " " << vs[1] << endl;
        }
        mm[vs[0] + " " + vs[1]].push_back(vs[i] + " " + vs[i + 1]);
      }
    }
  }
  for (auto gg : mm) {
    if (!m[gg.first]) {
      dfs(gg.first);
    }
  }
  cout << ans;
}
