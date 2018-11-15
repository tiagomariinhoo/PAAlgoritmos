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
  
  Dado os tamnhos dos arcos do circulo, 
  verificar se é possível colocar um retangulo dentro
  A ideia é guardar todos os pontos que são opostos (a soma indo pros dois lados são iguais)
  Caso exista duas retas distintas com somas iguais, então é possível fazer o retangulo
*/

int n;
vector<int> vec;
int sum[100005];
map<int,int> opo;
bool at = false;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.push_back(a);
  }

  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1] + vec[i-1];
  }

  int a = 0, b = 2;

  while(b < n){
    int sum2 = sum[b] - sum[a];
    int sum1 = sum[a] + (sum[n] - sum[b]);
      
    // cout << sum1 << " - " << sum2 << endl;

    if(sum1 < sum2){
      a++;
    } else if(sum1 > sum2){
      b++;
    } else{
      // cout << a << " - " << b << endl;
      opo[sum1]++;
      a++;
    }
    if(a == b) b++;
  }

  for(auto i : opo) if(i.S > 1) at = true;

  if(at) cout << "Y" << endl;
  else cout << "N" << endl;

  return 0;
} 