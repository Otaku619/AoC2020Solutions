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
  vector<string> v;
  string s;
  ll finans = 1;
  while(cin>>s)
    v.push_back(s);
  int t = s.length();
  pair<int,int> arr[] = {{1,1},{3,1},{5,1},{7,1},{1,2}};
  IN(gg,arr){
  int i=0,j=1;
  int ans=0;
  while(j<=v.size()){
    if(v[j-1][i]=='#')
      ans++;
    j+=gg.second;
    i=(i+gg.first)%t;
  }
  finans*=ans;
  }
  cout<<finans<<endl;
}
