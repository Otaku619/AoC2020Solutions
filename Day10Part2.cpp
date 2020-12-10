#include <bits/stdc++.h>
using namespace std;

const int mxS = 1e6;
long long a[mxS];

int main() {
  vector<long long> v;
  long long x;
  while (cin >> x)
    v.push_back(x);
  sort(v.begin(), v.end());
  v.push_back(v[v.size() - 1] + 3);
  v.insert(v.begin(), 0);
  a[0] = 1;
  for (long long gg : v)
    a[gg] += (gg > 0 ? a[gg - 1] : 0) + (gg > 1 ? a[gg - 2] : 0) +
             (gg > 2 ? a[gg - 3] : 0);
  cout << a[v[v.size() - 1]];
}
