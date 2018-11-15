#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
// typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100010
#define MAXL 20
#define MOD2 998244353


/*
  O problema da questão é ver quantas voltas de tantos graus eu consigo dar até
  chegar no ponto inicial da circunferência
  Supondo que o ponto de cima da pizza é o ponto inicial, se eu faço giros de 45 graus
  (fatias cortadas), quantas fatias eu vou cortando até chegar no ponto inicial? 8.
  O problema da questão é a questão de arredondamento.

  Como a entrada é dada: 13.13, com duas casas decimais
  Podemos ler scanf("%d.%d", &a, &b), pegarmos como inteiro e tratarmos a*100 + b;
*/

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int a, b;
  scanf("%d.%d", &a, &b);
  // cout << a << " - " << b << endl;
  int atual = 360*100;
  lli n = 100*a + b;
  lli soma = n;
  lli ans = 0;
  while(n%atual!=0){
    // cout << n << endl;
    n += soma;
    ans++;
  } ans++;

  // cout << atual/(__gcd(atual, n)) << endl;

  cout << ans << endl;

  return 0;
} 