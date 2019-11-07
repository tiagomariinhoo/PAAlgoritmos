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

/**
 * Given x.w + y.d = p
 * and x + y + z = n
 * find the diophantine solution
 * 
 * Solução:
 * Achar a solução da diofantina com menor x+y
 * 
 * Maximiza o X, de tal forma:
 * Sabemos que para iterar entre as soluções temos:
 * x - k*(d/g) e y + k*(w/g)
 * Podemos inverter o sinal também.
 * 
 * Após acharmos a solução com menor x+y
 * (para não tomar overflow), basta usar divisão
 * ou busca binária para maximizar o x e minimizar o y
 * de forma que x >= 0 e y >= 0
 * 
 * isOverflow checa se uma multiplicação dá overflow
 * Ao invés de usar busca binaria para isso, apenas
 * peguei a solução de y e tentei minimizar ela o maximo
 * possível continuando na condição de y >= 0
 * basta pegar a solução e dividir por (w/g)
*/

lli n, p, d, w;

lli gcd(lli a, lli b, lli &x, lli &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    lli x1, y1;
    lli d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long int mulMod(long long int a,long long  int b,long long int c){
    return ((a % c)*(b % c)) % c;
}


bool find_any_solution(lli a, lli b, lli c, lli &x0, lli &y0, lli &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    lli dx = c/a;
    c -= dx*a;
    lli dy = c/b;
    c -= dy*b;

    x0 = dx + mulMod(x0, c/g, b);
    y0 = dy + mulMod(y0, c/g, a);
    g = abs(g);
    return true;
}

bool isOverflow(lli a, lli b){
  if(a == 0 or b == 0) return false;
  lli result = a*b;
  if(a == result/b) return false;
  return true;
}

bool check(lli atual, bool isSum, lli x0, lli y0, lli g){
  if(isOverflow(atual, d/g) or isOverflow(atual, w/g)) return false;
  if(isSum){
    lli aa = atual*(d/g);
    lli bb = atual*(w/g);

    if(aa > x0) return false;
    if(bb)

    return true;
  } else {
    lli aa = atual*(d/g);
    lli bb = atual*(w/g);
    
    if(bb > y0) return false;

    return true;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> p >> w >> d;

  lli x=0, y=0, g;

  if(!find_any_solution(w, d, p, x, y, g)){
    cout << -1 << endl;
    return 0;
  }

  cout << x << " - " << y << endl;

  lli x0 = x, y0 = y;

  bool isSum = false;
  if(y < 0){ //x0-i*(d/g), y0+i*(w/g)
    isSum = true;
  } else { //x0+i*(d/g), y0-i*(w/g)
    isSum = false;
  }

  if(isSum){
    lli divi = y/(w/g);
    divi *= -1;
    divi++;
    y = y0 + divi*(w/g);
    x = x0 - divi*(d/g);
  } else {
    lli divi = y/(w/g);
    divi *= -1;
    // divi++;
    y = y0 + divi*(w/g);
    x = x0 - divi*(d/g);
  }

  if(y < 0 or x < 0 or (x+y > n)){
    cout << -1 << endl;
    return 0;
  }

  cout << x << " " << y << " " << n - x - y  << endl;

  return 0;
}