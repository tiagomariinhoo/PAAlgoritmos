#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2 * 1e5 + 5)
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

int n;
vector<int> vec;
lli pd[101][(1 << 17)];
lli resp[101][(1 << 17)];
vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

/**
 * Problema: Achar um array Bi tal que 
 * todos os pares de elemento são coprimos entre si
 * E o somatório de abs(ai - bi) é minimo.
 * 
 * Tenta para cada conjunto de numeros primos
 * Fazer um conjunto B, tal que os números
 * não sejam divisíveis por nenhum dos primos utilizados
 * 
 * Solução:
 * como o N é até 100 e o valor máximo de ai = 30
 * Então é possível guardar para todos os números
 * 
 * Para cada número de 1 até 59, eu guardo em uma bitmask
 * todos os primos que dividem ele, já que para qualquer número
 * ele pode ser divisível por algum número (fatorização de primos).
 * 
 * Então depois disso, posso fazer uma pd com bitmask que irá
 * testar todas as combinações, verificando se já tem algum número
 * que já usou aqueles primos como divisores.
 * 
 */ 

lli factor[MAXN];

void preCalc() {
  for(int i=1;i<=59;i++) {
    factor[i] = 0;
    for(int j=0;j<sz(p);j++) {
      if(i%p[j] == 0) {
        factor[i] |= (1 << j);
      }
    }
  }
}

lli solve(int pos, int mask) {
  if(pos == n) return 0;

  if(pd[pos][mask] != -1) return pd[pos][mask];
  
  int aux = INT_MAX;

  for(int i=1;i<=59;i++) {
    // Verifica se para o número atual
    // Já tem algum cara que utiliza algum divisor dele
    if(!(factor[i]&mask)) {
      int a = solve(pos+1, mask|factor[i]) + abs(vec[pos] - i);
      if(a < aux) {
        aux = a;
        resp[pos][mask] = i;
      }    
    }
  }
  return pd[pos][mask] = aux;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }

  memset(pd, -1, sizeof pd);

  preCalc();

  solve(0, 0);
  
  // Recuperar os itens da pd, fazendo a mask ao contrário
  int atual = 0;
  for(int i=0;i<n;i++) {
    int a = pd[i][atual];
    
    int ans = resp[i][atual];
    cout << ans << " ";

    atual |= factor[resp[i][atual]];
  } cout << endl;

  return 0;
}