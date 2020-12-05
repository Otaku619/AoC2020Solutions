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
  string s;
  long mx=-1;
  while(cin>>s){
  int l=0,r=127;
  FOR(7){
    if(s[i]=='F')
      r=(r+l)/2;
    else
      l=(r+l)/2+1;
  }
  long ans = l*8;
  l=0,r=7;
  FOR(i,7,10){
    if(s[i]=='L')
      r=(r+l)/2;
    else
      l=(r+l)/2+1;
  }
  mx=max(mx,ans+l);
}
cout<<mx;
}
