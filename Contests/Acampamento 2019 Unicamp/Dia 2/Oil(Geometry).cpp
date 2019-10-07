#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/*
    Ordena os pontos pelo slope
    Tomando cuidado com quem tá acima do centro e embaixo
    E quem tem que subtrair e somar
*/ 

bool comp(pair<lli, pair<lli, lli> > a, pair<lli, pair<lli, lli> > b){
  lli av = (lli) a.S.F * b.S.S;
  lli bv = (lli) b.S.F * a.S.S;
  if(av != bv) return av < bv;
  return a.F > b.F;
}
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> n){
    vector<int> x1(n), x2(n), y(n);
    for(int i=0;i<n;i++){
      cin >> x1[i] >> x2[i] >> y[i];
      if(x1[i] > x2[i]) swap(x1[i], x2[i]);
    }

    int ret = 0;

    for(int i=0;i<n;i++){
      vector<pair<lli, pair<lli, lli> > > v;
      int cur = 0;
      for(int j=0;j<n;j++){
        if(y[j] == y[i]){
          if(x1[i] >= x1[j] and x1[i] <= x2[j]) cur += (x2[j] - x1[j]);
        } else if(y[j] < y[i]){
          v.push_back(make_pair(x2[j]-x1[j], make_pair(x1[i]-x2[j], y[i]-y[j])));
          v.push_back(make_pair(x1[j]-x2[j], make_pair(x1[i]-x1[j], y[i]-y[j])));
        } else {
          v.push_back(make_pair(x2[j]-x1[j], make_pair(x1[j]-x1[i], y[j]-y[i])));
          v.push_back(make_pair(x1[j]-x2[j], make_pair(x2[j]-x1[i], y[j]-y[i])));
        }
      }      
      sort(v.begin(), v.end(), comp);
      ret = max(ret, cur);
      for(int j=0;j<sz(v);j++){
        cur += v[j].F;
        ret = max(ret, cur);
      }
    }

    cout << ret << endl;
  }

  return 0;
}