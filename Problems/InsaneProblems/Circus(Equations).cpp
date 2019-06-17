#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<pair<char, char> > vec;
vector<int> ans, ans2;

string sa, sb;

void no(){
  cout << -1 << endl;
  exit(0);
}

  queue<int> a, b, c, d;

void solve(int aa, int bb, int cc, int dd){
  vector<int> ans;
  while(aa){
    ans.push_back(a.front());
    a.pop();
    aa--;
  }
  while(bb){
    ans.push_back(b.front());
    b.pop();
    bb--;
  }
  while(cc){
    ans.push_back(c.front());
    c.pop();
    cc--;
  }
  while(dd){
    ans.push_back(d.front());
    d.pop();
    dd--;
  }

  for(auto i : ans) cout << i+1 << " ";
  cout << endl;
}

/*
  Perceber que:
  a + b + c + d == n/2 e c + d = B + D - d - b
  Substitui fica
  a - d = n/2 - B - D
  Bruta 'a' e 'd'
  Se satisfazer, bruta b e c pra primeira equação
  */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> sa;
  cin >> sb;


  for(int i=0;i<sz(sa);i++){
    if(sa[i] == '0' and sb[i] == '0'){
      a.push(i);
    } else if(sa[i] == '0' and sb[i] == '1'){
      b.push(i);
    } else if(sa[i] == '1' and sb[i] == '0'){
      c.push(i);
    } else{ 
      d.push(i);
    }
    vec.push_back({sa[i], sb[i]});
  }

  for(int aa=0;aa<=sz(a);aa++){
    for(int dd=0;dd<=sz(d);dd++){
      if(aa-dd == (n/2 - sz(b) - sz(d))){
        for(int bb=0;bb<=sz(b);bb++){
          for(int cc=0;cc<=sz(c);cc++){
            if(aa + dd + bb + cc == n/2
            and (dd + cc == (sz(d) - dd + sz(b) - bb))){
              solve(aa, bb, cc, dd);
              return 0;
            }
          }
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}