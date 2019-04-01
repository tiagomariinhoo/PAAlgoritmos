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

int n;
int vec[1501];
map<int, vector<pair<int, int> > > aux;
int global;
vector<pair<int, int> > anss;
vector<pair<int, int> > anss2;

/*
  Guloso
  Gera todas as possibilidades de soma
  Ordena as possibilidades de índices de cada soma
  Pelo R menor. 

  Pegar o maior número de segmentos [l,r] que não se sobrepoem
*/

bool comp(pair<int, int> a, pair<int, int> b){
  return a.S < b.S;
}

void resp(int atual){  
  anss.clear();
  vector<pair<int, int> > aux2 = aux[atual];

  sort(aux2.begin(), aux2.end(), comp);
  anss.push_back(aux2[0]);
  int ult = aux2[0].S;
  for(int i=1;i<aux2.size();i++){
    if(aux2[i].F > ult){
      ult = aux2[i].S;
      anss.push_back(aux2[i]);
    }
  }

  if(anss.size() > anss2.size()) anss2 = anss;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> vec[i];

  for(int i=1;i<=n;i++){
  int sum = 0;
    for(int j=i;j<=n;j++){
      sum += vec[j];
      aux[sum].push_back({i, j});
    }
  }  

  int ans = 0;
  int poss;
  for(auto i : aux){
    resp(i.F);
  }

  cout << anss2.size() << endl;
  for(auto i : anss2) cout << i.F << " " << i.S << endl;


  return 0;
}