#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 50000 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())

lli n, m, k;

/*
  PROBLEMA: DADO N E M
  A MATRIZ É CONSTRUIDA I*J (I ROW E J COL)
  ACHAR  O K-TH MAIOR ELEMENTO DA MATRIZ

  É POSSÍVEL PERCEBER QUE DADO UM X QUALQUER
  EM CADA LINHA I, EXISTEM MIN(X/I, M) ELEMENTOS MENORES QUE ELE

  BASTA FAZER BUSCA BINARIA CHUTANDO A RESPOSTA

*/

lli solve(lli atual){
  lli qt = 0;
  if(atual > n*m) return k+1;

  for(lli i=1;i<=n;i++){
    qt += min(atual/i, m);
  }
  return qt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  lli com = 1, fim = 1e12;
  while(com < fim){
    lli mid = (com + fim) >> 1;
    if(solve(mid) >= k){
      fim = mid;
    } else {
      com = mid + 1;
    }
  }

  cout << com << endl;

  return 0;
}