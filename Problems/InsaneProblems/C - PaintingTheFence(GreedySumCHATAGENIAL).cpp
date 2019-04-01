#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, q;
vector<pair<int, int> > vec;
int sum[5002], sum2[5002], sum3[5002];
int aux[5002];
int ans = 0;
int vis[5002];

/*
  Pegar os dois pintores que tirando eles, ainda dê pra pintar o máximo de posições

  Basta simular e fazer soma acumulada onde tem apenas 1 pintor cobrindo a posição i e 2 pintores cobrindo a posição i
  Faz a intersecção e checa a soma

  GENIAL POREM CHATA
*/

void fill(int l, int r){
  for(int i=l;i<=r;i++) aux[i]++;
}

int check(pair<int, int> a, pair<int, int> b){
  int tame = 0;
  if(a.F > b.F) swap(a, b);


  if(a.S >= b.F){
    int r = a.S , l = b.F;
    r = min(a.S, b.S);
    tame += (sum2[r] - sum2[l-1]) + (sum[l-1] - sum[a.F-1] + sum[max(a.S, b.S)] - sum[r]);
  } else {
    tame += (sum[a.S] - sum[a.F - 1] + sum[b.S] - sum[b.F - 1]);
  }
  return tame;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for(int i=0;i<q;i++){
    int a, b;
    cin >> a >> b;
    vec.push_back({a, b});
    aux[a]++, aux[b+1]--;
  }

  for(int i=1;i<=n;i++) aux[i] += aux[i-1];

  for(int i=1;i<=n;i++) if(aux[i]) ans++;

  for(int i=1;i<=n;i++){
    if(aux[i] == 1) sum[i] = 1 + sum[i-1], sum2[i] += sum2[i-1];
    else if(aux[i] == 2) sum2[i] = 1 + sum2[i-1], sum[i] += sum[i-1];
    else if(aux[i] > 2){
      sum3[i] += sum3[i-1] + 1;
      sum2[i] += sum2[i-1];
      sum[i] += sum[i-1];
    } else sum3[i] += sum3[i-1], sum2[i] += sum2[i-1], sum[i] += sum[i-1];
  }

  int anss = 0;
  for(int i=0;i<vec.size();i++){

    if(i+1 <= vec.size() - 1)
    for(int j=i+1;j<vec.size();j++){
      anss = max(anss, ans - check(vec[i], vec[j]));
    }
  }

  cout << anss << endl;

  return 0;
}