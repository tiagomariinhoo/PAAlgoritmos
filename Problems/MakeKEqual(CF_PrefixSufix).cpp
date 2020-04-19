#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2 * 1e5 + 1)
#define MAXL 20
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

int n, k;
vector<lli> vec;
  set<lli> aux;
  map<lli, lli> qt;
  lli pre[MAXN], suf[MAXN], qtSuf[MAXN], qtPre[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  vector<lli> vec, vec2;

  for(int i=0;i<n;i++) {
    int a;
    cin >> a;
    aux.insert(a);
    qt[a]++;
    vec.push_back(a);
  }
  vec.assign(aux.begin(), aux.end());
  sort(vec.begin(), vec.end());

  if(sz(vec) == 1) {
    cout << 0 << endl;
    return 0;
  }

  for(int i=sz(vec)-1;i>=0;i--){
    qtSuf[i] = qtSuf[i+1] + qt[vec[i]];
    if(i != sz(vec) - 1) {
      suf[i] = suf[i+1] + abs(vec[i] - vec[i+1])*qtSuf[i+1];    
    }
  }

  for(int i=0;i<sz(vec);i++) {
    if(!i) {
      qtPre[i] = qt[vec[i]];
    } else {
      qtPre[i] = qt[vec[i]] + qtPre[i-1];
      pre[i] = pre[i-1] + abs(vec[i] - vec[i-1])*qtPre[i-1];
    }
  }

  lli ans = LLONG_MAX;
  for(int i=0;i<sz(vec);i++){
    
    if(qt[vec[i]] >= k) {
      ans = 0;
      break;
    }

    lli precisa = k - qt[vec[i]];

    if(!i) {
      lli soma = abs(vec[i] - vec[i+1]) * precisa + suf[i+1];
      ans = min(ans, soma);
    } else if (i == sz(vec) - 1){
      lli soma = abs(vec[i] - vec[i-1]) * precisa + pre[i-1];
      ans = min(ans, soma);
    } else {
      lli aux = LLONG_MAX;
      
      // Try preffix first
      lli resto = min(qtPre[i-1], precisa);
      lli soma = abs(vec[i] - vec[i-1]) * resto + pre[i-1];
      lli pprecisa = precisa - resto;
      lli soma2 = 0;
      if (pprecisa > 0) {
        lli auxx = abs(vec[i] + 1 - vec[i+1]) * qtSuf[i+1];
        soma2 = pprecisa + auxx + suf[i+1];
      }

      aux = min(aux, soma+soma2);
      // Try suffix
      resto = min(qtSuf[i+1], precisa);
      soma = abs(vec[i] - vec[i+1]) * resto + suf[i+1];
      pprecisa = precisa - resto;
      soma2 = 0;
      if (pprecisa > 0) {
        lli auxx = abs(vec[i] + 1 - vec[i-1]) * qtPre[i-1];
        soma2 = pprecisa + auxx + pre[i-1];
      }
      aux = min(soma+soma2, aux);
      
      ans = min(ans, aux);
    }
  }

  cout << ans << endl;

  return 0;
}