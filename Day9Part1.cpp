#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> pairs;

void combine(int idx) {
  pairs.clear();
  for (int i = 0; i < 25; i++)
    for (int j = i + 1; j < 25; j++)
      pairs.push_back(a[i + idx] + a[j + idx]);
}

int main() {
  int idx = 0;
  for (int i = 0; i < 25; i++) {
    int aa;
    cin >> aa;
    a.push_back(aa);
  }
  combine(idx);
  int x;
  while (cin >> x) {
    if (find(pairs.begin(), pairs.end(), x) == pairs.end()) {
      cout << x;
      return 0;
    }
    a.push_back(x);
    combine(++idx);
  }
}
