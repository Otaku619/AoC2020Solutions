#include <bits/stdc++.h>
using namespace std;
long acc;
int idx;
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
vector<int> vector_to_store_the_index_cuz_imma_brute_force_saddies;
vector<pair<operation, bool>> v;

operation parser(string s) {
  string cmd = s.substr(0, 3);
  char sign = s[4];
  int number = 0;
  for (int i = 5; i < s.size(); i++) {
    number += s[i] - '0';
    number *= 10;
  }
  if (cmd == "jmp" || cmd == "nop")
    vector_to_store_the_index_cuz_imma_brute_force_saddies.push_back(idx);
  return operation(cmd, sign, number / 10);
}

void swap(int i) {
  if (v[i].first.cmd == "jmp")
    v[i].first.cmd = "nos";
  else
    v[i].first.cmd = "jmp";
}

int main() {
  string s;
  while (getline(cin, s)) {
    v.push_back({parser(s), 0});
    idx++;
  }
  for (int id : vector_to_store_the_index_cuz_imma_brute_force_saddies) {
    swap(id);
    int i = 0;
    bool flag = 1;
    for (; i < v.size();) {
      if (v[i].second) {
        flag = 0, acc = 0;
        break;
      }
      v[i].second = 1;
      if (v[i].first.cmd == "jmp")
        i += v[i].first.num;
      else if (v[i].first.cmd == "acc")
        acc += v[i].first.num, i++;
      else
        i++;
    }
    if (flag) {
      cout << acc;
      return 0;
    }
    for (int j = 0; j < v.size(); j++)
      v[j].second = 0;
    swap(id);
  }
}
