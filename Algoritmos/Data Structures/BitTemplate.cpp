#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2 * 1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct FenwickTree{
  // Index [0..n-1]
  // Para mudar para [1..n], coloca r > 0 e idx <= n

  vector<lli> bit;
  int n;

  FenwickTree(int n){
    this->n = n;
    bit.assign(n, 0);
  }

  lli sum(int r){
    lli ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];

    return ret;
  }

  lli sum(int l, int r){
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta){
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};

FenwickTree cnt(n), soma(n);