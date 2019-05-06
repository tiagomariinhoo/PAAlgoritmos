#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<lli,lli> ii;

int n, m;
// vector<pair<int, pair<int, int> > > vec;
vector<pair<int, int> > vec;
int qt[MAXN];
vector<int> divs;

void takeDiv(){
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      if(n/i == i) divs.push_back(i);
      else divs.push_back(i), divs.push_back(n/i);
    }
  }
}

bool solve(int k){
  vector<pair<int ,int> > vec2 = vec;
  for(int i=0;i<sz(vec2);i++){
    vec2[i].F = (vec2[i].F + k)%n;
    vec2[i].S = (vec2[i].S + k)%n;
    if(vec2[i].F > vec2[i].S) swap(vec2[i].F, vec2[i].S);
  }
  sort(vec2.begin(), vec2.end());
  for(int i=0;i<sz(vec2);i++){
    if(vec[i].F != vec2[i].F or (vec[i].S != vec2[i].S)){
      return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    a--,b--;
    if(a > b) swap(a, b);
    vec.push_back({a, b});
  }

  sort(vec.begin(), vec.end());

  takeDiv();
  for(auto i : divs){
    if(i == n) continue;
    if(solve(i)){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}