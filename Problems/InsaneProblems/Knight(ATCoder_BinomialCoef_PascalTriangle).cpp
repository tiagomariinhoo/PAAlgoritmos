#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int,int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/*

  1 - É possível notar que de acordo com os movimentos do cavalo
  Ele vai formando um triangulo de pascal na matriz, então: 

  6 I 0 0 0 1 0 0 0
  5 I 0 0 0 0 3 0 0
  4 I 0 0 1 0 0 3 0
  3 I 0 0 0 2 0 0 1
  2 I 0 1 0 0 1 0 0
  1 I 0 0 1 0 0 0 0
  0 I 1 0 0 0 0 0 0 
      -------------
      0 1 2 3 4 5 6
  Olhando de baixo pra cima fazendo os movimentos do cavalo
  
  Supondo o caso da imagem (6, 6)
  Precisamos pegar a diagonal que ele tá, então 
  podemos perceber que a cada 3 diagonais (0, 3, 6...)
  Temos uma linha do triangulo de pascal, então, pra 
  pegar a linha atual do triangulo fazemos (x+y)/3
  Já que a diagonal 0 é a linha 1, diagonal 1 é a linha 2
  diagonal 3 é a linha 3 e assim vai...

  Podemos pegar a coluna do triangulo de pascal, fazendo:
  x - (x+y)/2, coluna atual no triangulo
  Para pegarmos a resposta, fazemos: nCk
  Nesse caso: linhaPascal C colunaPascal

  Tomar cuidado quando (x+y)%3 != 0, resposta 0
  E x -= linhaPascal e y -= linhaPascal, se algum deles
  for zero, então a resposta tb é zero

*/

lli C(lli n, lli r){
	lli f[n+1];
	f[0] = 1;

	for(int i=1;i<=n;i++){
		f[i] = i*f[i-1];
	}
	return f[n]/f[r]/f[n-r];
}

lli powMod(lli a, lli b, lli MOD2){
	lli x=1, y = a;
	while(b > 0){
		if(b%2==1){
			x = (x*y);
			if(x > MOD2) x%=MOD2;
		}
		y = (y*y);
		if(y > MOD2) y%=MOD2;
		b/=2;
	}
	return x;
}


lli inverseEuler(lli n, lli MOD2){
	return powMod(n, MOD2-2, MOD2);
}

/*
	Coeficiente Binomial com Modulo
*/

lli C(lli n, lli r, lli MOD2){
	vector<lli> f(n+1, 1);
	// Dá pra otimizar o calculo do fatorial
	// Deixando todos pre calculados
	for(lli i = 2;i<=n;i++){
		f[i] = (f[i-1]*i)%MOD2;
	}

	return (f[n]*((inverseEuler(f[r], MOD2) * inverseEuler(f[n-r], MOD2))%MOD2))%MOD2;
}

void no(){
  cout << 0 << endl;
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli n, m;
  cin >> n >> m;
  if(n < m) swap(n, m);
  if((n+m)%3 != 0){
    no();
  }
  
  lli h = (n+m)/3;
  n -= h, m -= h;
  if(n < 0 or m < 0) no();
  cout << h << " - " << n << endl;
  cout << C(h, n, MOD) << endl;

  return 0;
}