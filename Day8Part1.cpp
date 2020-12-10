#include <bits/stdc++.h>
using namespace std;
long acc;
struct operation {
  string cmd;
  int num;
  operation(string a, char b, int c) {
    cmd = a;
    num = c;
    if (b == '-')
      num *= -1;
  }
};

vector<pair<operation, bool>> v;

operation parser(string s) {
  string cmd = s.substr(0, 3);
  char sign = s[4];
  int number = 0;
  for (int i = 5; i < s.size(); i++) {
    number += s[i] - '0';
    number *= 10;
  }
  return operation(cmd, sign, number / 10);
}
int main() {
  string s;
  while (getline(cin, s))
    v.push_back({parser(s), 0});
  for (int i = 0; i < v.size();) {
    if (v[i].second) {
      cout << acc;
      return 0;
    }
    v[i].second = 1;
    if (v[i].first.cmd == "acc")
      acc += v[i].first.num, i++;
    else if (v[i].first.cmd == "jmp")
      i += v[i].first.num;
    else
      i++;
  }
}
