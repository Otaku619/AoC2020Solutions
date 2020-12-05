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

vector<string> split(string s){
  s+=':';
  vector<string> v;
  string g="";
  IN(gg,s){
    if(gg==':')
    {
      v.push_back(g);
      g="";
    }
    else
      g+=gg;
  }
  return v;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  //Add a blank line at the end of the input for it to work or tweak the loop a little
  string s;
  vector<string> v;
  int b=0;
  vector<string> eyecolors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
  int ans=0;
  while(getline(cin,s)){
    if(s.empty()){
      IN(ss,v){
        istringstream is(ss);
        while(is){
          string k;
          is>>k;
          if(is){
            vector<string> heya = split(k);
            if(heya[0]=="byr")
            {
              stringstream conv(heya[1]);
              int x;
              conv>>x;
              if(x>=1920 && x<=2002)
                b++;
            }
            else if(heya[0]=="iyr"){
              stringstream conv(heya[1]);
              int x;
              conv>>x;
              if(x>=2010 && x<=2020)
                b++;
            }
            else if(heya[0]=="eyr"){
              stringstream conv(heya[1]);
              int x;
              conv>>x;
              if(x>=2020 && x<=2030)
                b++;
            }
            else if(heya[0]=="hgt"&&heya[1].length()>=3){
              stringstream conv(heya[1].substr(0,heya[1].length()-2));
              int x;
              conv>>x;
              if(heya[1].substr(heya[1].length()-2)=="cm" && x>=150 && x<=193)
                b++;
              else if(heya[1].substr(heya[1].length()-2)=="in" && x>=59 && x<=76)
                b++;
            }
            else if(heya[0]=="hcl" && heya[1].length()==7){
              bool bbb=1;
              IN(ggg, heya[1].substr(1)){
                bbb&=((ggg>='0'&&ggg<='9')||(ggg>='a'&&ggg<='f'));
              }
              bbb&=heya[1][0]=='#';
              b+=bbb;
            }
            else if(heya[0]=="ecl" && find(eyecolors.begin(),eyecolors.end(),heya[1])!=eyecolors.end())
              b++;
            else if(heya[0]=="pid" && heya[1].length()==9)
            {
              bool bbb=1;
              IN(ggg, heya[1])
            bbb&=(ggg>='0'&&ggg<='9');
              b+=bbb;
              
      }
      }}}
  ans+=(b==7);
      v.clear();
      b=0;
    }
    else
      v.push_back(s);
  }
  cout<<ans;
}
