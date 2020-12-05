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
vector<int> split(string s){
  s+='-';
  vector<int> p;
  string temp="";
  IN(gg,s){
    if(gg=='-'){
      stringstream ss(temp);
      int bruh;
      ss >> bruh;
      p.push_back(bruh);
      temp="";
    }
    else
      temp+=gg;
}
return p;
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  string s;
  int cnt=0;
  int a,b;
  char ch;
  int ans=0;
  while(cin >> s){
    cnt++;
    if(cnt%3==1)
    {
      vi v = split(s);
      a=v[0];
      b=v[1];
    }
    else if(cnt%3==2)
      ch=s[0];
    else{
      int t=0;
      IN(gg,s)
        t+=(gg==ch);
      ans+=(t>=a&&t<=b);
    }
  }
  cout<<ans;
}
