#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 10)
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
string s, t;

/*
  TEORIA DOS NUMEROS, MUDANÇA DE BASE
  Quer achar a string no meio somando duas strings

  Trata as strings como base 26
  Soma as duas

  Divide a soma por 2 (como se fosse Big Int)

  Tudo usando base 26
  Para qualquer outra base, basta trocar o 26.
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> s >> t;

  vector<int> a, b;
  for(int i=0;i<n;i++){
    a.push_back(s[i] - 'a');
    b.push_back(t[i] - 'a');
  }

  a[0] += b[0];
  for(int i = n - 1; i > 0; i--){
    a[i] += b[i];
    a[i-1] += (a[i]/26);
    a[i] %= 26;
  }

  int tmp = a[0];
  for(int i=1;i<=n;i++){
    cout << char(tmp/2 + 'a');
    tmp = (tmp%2) * 26 + a[i];
  }

  return 0;
}