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

lli h, n;
lli vec[(int)(3*1e5)];
lli pre[(int)(3*1e5)];
lli tot;

/*
Nessa função só passei pra long double pra checar divisão
pra não dar overflow (sagaz)

Busca binaria
*/

bool test(lli atual, lli pos){
  // if(h + pre[pos] + (tot * atual) <= 0) return true;
  if((long double)(-h-pre[pos])/atual >= tot) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> n;
  for(int i=1;i<=n;i++) cin >> vec[i];

  memset(pre, 0, sizeof pre);
  for(int i=1;i<=n;i++) pre[i] += pre[i-1] + vec[i];

  
  for(int i=1;i<=n;i++){
    if(h + pre[i] <= 0){
      cout << i << endl;
      return 0;
    }
  }

  if(pre[n] >= 0){
    cout << -1 << endl;
    return 0;
  }

  lli ans = LLONG_MAX;
  tot = pre[n];
  for(int i=1;i<=n;i++){

    lli com = 1, fim = 1e18;
    while(com < fim){
      lli mid = (com + fim) >> 1;
      // cout << com << " - " << mid << " - " << fim << endl;
      if(test(mid, i)){
        fim = mid;
      } else{
        com = mid + 1;
      }
    }
    // cout << "Com : " << fim << endl;
    ans = min(ans, fim*n + i);
  }


  cout << ans << endl;


  return 0;
}