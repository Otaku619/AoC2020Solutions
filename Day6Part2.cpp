#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define FOR_(i, a, b, x) for (int i = a; (x > 0) ? i < b : i > b; i += x)
#define FOR_1(e) FOR_(i, 0, e, 1)
#define FOR_2(i, e) FOR_(i, 0, e, 1)
#define FOR_3(i, a, e) FOR_(i, a, e, 1)
#define FOR_4(i, a, e, b) FOR_(i, a, e, b)
#define FOR_5(...) G5(__VA_ARGS__, FOR_4, FOR_3, FOR_2, FOR_1)
#define G5(a, b, c, d, e, ...) e
#define FOR(...)                                                               \
  FOR_5(__VA_ARGS__)                                                           \
  (__VA_ARGS__)
#define IN(a, b) for (auto &a : b)

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  string ss;
  int ans=0;
  map<char,int> m;
  int totans=0;
  int temp=0;
  //add empty line at the end to run the last iteration or tweak the loop yourself
  while(getline(cin,ss)){
    if(ss.empty()){
      IN(gg,m)
        if(gg.second==temp)
          ans++;
      m.clear();
      totans+=ans;
      temp=0,ans=0;
    }
    else
    {
      IN(gg,ss)
        m[gg]++;
    temp++;
    }
  }
  cout<<totans;
}

