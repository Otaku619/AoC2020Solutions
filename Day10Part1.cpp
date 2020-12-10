#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  int x;
  while (cin >> x)
    v.push_back(x);
  sort(v.begin(), v.end());
  v.push_back(v[v.size() - 1] + 3);
  v.insert(v.begin(), 0);
  int cnt[] = {0, 0, 0, 0};
  for (int i = 0; i < v.size() - 1; i++)
    cnt[v[i + 1] - v[i]]++;
  cout << cnt[1] * cnt[3];
}
