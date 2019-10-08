#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e6 + 1)
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

int t;
int n, m;
vector<int> alf, alf2, path;
map<char, int> value;
map<int, char> value2;
int vec[33][33];

/*
Pegar um ciclo hamiltoniano (o caminho)

Dado um alfabeto e as arestas entre as letras
Achar um caminho hamiltoniano

- Nada mais é que o Algoritmo do TSP com Bitmask,
sem peso

2^n * n²

O primeiro caminho que achar é a resposta

*/

bool solve(int pos, int mask){
  
  if(mask == ((1 << n) - 1)) return (pos == value[alf[sz(alf) - 1]]);

  for(int i=1;i<n;i++){
    if((mask & (1 << i)) == 0) {
      if(vec[pos][i] and solve(i, mask|(1 << i))){
        path.push_back(i);
        return true;
      }
    }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  int tt = 1;
  while(t--){

    value.clear(), value2.clear(), alf.clear(), path.clear();
    for(int i=0;i<30;i++) for(int j=0;j<30;j++) vec[i][j] = 0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
      char a;
      cin >> a;
      alf.push_back(a-'A');
    }

    sort(alf.begin()+1, alf.end()-1);

    for(int i=0;i<sz(alf);i++){
      value[alf[i]] = i;
      value2[i] = alf[i]+'A';
    }

    for(int i=0;i<m;i++){
      char a, b;
      cin >> a >> b;
      // cout << value[a-'A'] << " - " << value[b-'A'] << endl;
      vec[value[a-'A']][value[b-'A']] = 1;
      vec[value[b-'A']][value[a-'A']] = 1;
    }

    // for(auto i : alf) cout << (char) (i+'A') << " - " << value[i] << endl;

    solve(0, (1 << value[alf[0]]));
    path.push_back(0);

    // cout << sz(path) << endl;
    cout << "Case " << tt++ << ": ";
    if(sz(path) == n) {
      reverse(path.begin(), path.end());
      for(auto i : path){
        cout << value2[i];
      }
       cout << endl;
    } else {
      cout << "impossible" << endl;
    }

  }

  return 0;
}