#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> pairs;
map<int, pair<bool, int>> m;
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
  int x, imposter;
  bool b = 0;
  while (cin >> x) {
    if (find(pairs.begin(), pairs.end(), x) == pairs.end() && !b) {
      imposter = x;
      b = 1;
    }
    a.push_back(x);
    if (!b)
      combine(++idx);
  }
  long long temp = 0;
  int nig, ger;
  for (int i = 0; i < a.size(); i++) {
    temp += a[i];
    if (m[temp - imposter].first) {
      nig = m[temp - imposter].second + 1;
      ger = i + 1;
      break;
    }
    m[temp] = {1, i};
  }
  cout << *min_element(a.begin() + nig, a.begin() + ger) +
              *max_element(a.begin() + nig, a.begin() + ger);
}
