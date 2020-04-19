#include<bits/stdc++.h>
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

/**
 * Basicamente essa solução funciona como um crivo
 * Do jeito que os for's estão aninhados, eu já pego os
 * múltiplos seguintes certinho
 * Então se a complexidade do crivo è N log n log n, 
 * colo cando mais um for isso não vai piorar tanto.
 * 
 * basicamente eu já testo todas as possibilidades gerando apenas
 * o que é preciso
 */ 

int t;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while(t--){
    int a, b, c;
    cin >> a >> b >> c;

    int ans = INT_MAX;
    int aa = a, bb = b, cc = c;
    
    for(int i=1;i<=2*1e4;i++) {
      for(int j=i;j<=2*1e4;j+=i) {
        for(int k=j;k<=2*1e4;k+=j) {
          int aux = (abs(i-a) + abs(j-b) + abs(k-c));
          if(aux < ans) {
            aa = i;
            bb = j;
            cc = k;
            ans = aux;
          }
        }
      }
    }
    
    cout << ans << endl;
    cout << aa << " " << bb << " " << cc << endl;
  }

  return 0;
}