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

string s;
int q;
int pd[5001][5001], pre[5001][5001];

/*
  Explicação:
  https://www.youtube.com/watch?v=CqctkhXMJdQ

  Se ligar no preffix sum 2D
  Bottom Up para construir o numero de palindromos na substring

  Caso base, tamanho 1 e 2 
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  cin >> q;
  int n = sz(s);
  s = ' ' + s;

  for(int i=1;i<=n;i++) pd[i][i] = 1;
  for(int i=1;i<n;i++) pd[i][i+1] = (s[i] == s[i+1]);

  for(int i=0;i<n;i++){
    for(int j=1;j<=n-i;j++){
      if(s[j] == s[j+i] and pd[j+1][i+j-1]){
        pd[j][j+i] = 1;
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      pre[i][j] += pre[i][j-1] + pre[i-1][j] + pd[i][j] - pre[i-1][j-1];
    }
  }

  for(int i=0;i<q;i++){
    int a, b;
    cin >> a >> b;
    cout << pre[b][b] + pre[a-1][a-1] - pre[a-1][b] - pre[b][a-1] << endl;
  }

  return 0;
}