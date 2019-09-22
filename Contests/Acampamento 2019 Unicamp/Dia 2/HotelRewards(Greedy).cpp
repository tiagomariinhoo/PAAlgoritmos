#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353  
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

lli n, k;
vector<lli> vec;

/*
    problema: Dado N e K
    N é o numero de Hoteis e
    K é o numero de moedas pra gastar e não pagar 
    um hotel.
    Cada hotel pago, ganha uma moeda
    6 2
    10 3 12 15 12 18

    Posso pagar o hotel 10 3 12 e 12 
    E escolher não pagaro hotel 15 e 18
    
    Solução:
    Sempre que você passa por K hoteis
    Coloca o valor na PQ, senão,
    verifica se o hotel atual, é maior do que
    o menor elemento da PQ, se for, troca

*/

void solve(){

  lli sum = 0, count = 0, sum2 = 0;

  priority_queue<lli, vector<lli>, greater<lli> > aux;

  DEBUG;
  for(auto i : vec){
    sum += i;
    if(count == k){
      aux.push(i);
      count = 0;
      continue;
    } else {
      if(!aux.empty()){
          if(i > aux.top()){
            aux.pop();
            aux.push(i);
          }
      }
    }
    count++;
  }
  DEBUG;
  while(!aux.empty()){
  // cout << "Aux : " << aux.top() << endl;
  sum2 += (aux.top()), aux.pop();
  } 

  cout << sum - sum2 << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> n >> k){
    vec.clear();
    for(int i=0;i<n;i++){
      lli a;
      cin >> a;
      vec.push_back(a);
    }
    solve();

  }

  return 0;
}