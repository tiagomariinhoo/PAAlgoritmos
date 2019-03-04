#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 50000 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define pb push_back

int n;
lli vec[2002][2002];

lli aa[2002][2002];
lli bb[2002][2002];
lli cc[2002][2002];
lli dd[2002][2002];

void aaprep(){ //Cima para Diagonal Direita baixo
  for(int i=1;i<=n;i++){
    int ii = 0;
    while(i+ii <= n and ii <= n){
      aa[i+ii][ii+1] = aa[i+ii-1][ii] + vec[i+ii][ii + 1];
      ii++;
    }
  }
  for(int i=1;i<=n;i++){
    int ii = 0;
    while(i+ii <= n and ii+1+i <= n){
      aa[ii+1][i+1+ii] = aa[ii][i + ii] + vec[ii+1][ii + i + 1];
      ii++;
    }
  }
}

void bbprep(){ //Baixo paga diagonal esquerda cima
  for(int i=n;i>=1;i--){
    int ii = 0;
    while(i-ii >=1 and n-ii >= 1){
      bb[i-ii][n-ii] = bb[i-ii + 1][n-ii+1] + vec[i-ii][n-ii];
      ii++;
    }
  }

  for(int i=n;i>=1;i--){
    int ii = 0;
    while(i-ii-1 >= 1 and n-ii >= 1){
      bb[n-ii][i-ii-1] = bb[n-ii+1][i-ii] + vec[n-ii][i-ii-1];
      ii++;
    }
  }
}

void ccprep(){ //Cima para diagonal esquerda baixo
  for(int i=1;i<=n;i++){
    int ii = 0;
    while(ii+1 <= n and i-ii >= 1){
      cc[ii + 1][i-ii] = cc[ii][i-ii-1] + vec[ii + 1][i-ii];
      ii++;
    }
  }

  for(int i=2;i<=n;i++){
    int ii = 0;
    while(i+ii <= n and n-ii >= 1){
      cc[i+ii][n-ii] = cc[i+ii-1][n-ii-1] + vec[i+ii][n-ii];
      ii++;
    }
  }
}

void ddprep(){//Baixo para diagonal direita cima
  for(int i=1;i<=n;i++){
    int ii = 0;
    while(i-ii>= 1 and 1+ii <= n){
      dd[i-ii][1+ii] = dd[i-ii+1][ii] + vec[i-ii][1+ii];
      ii++;
    }
  }

  for(int i=2;i<=n;i++){
    int ii = 0;
    while(n-ii >= 1 and i+ii <= n){
      dd[n-ii][i+ii] = dd[n-ii+1][i+ii-1] + vec[n-ii][i+ii];
      ii++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> vec[i][j];
    }
  }


  aaprep();
  bbprep();
  ccprep();
  ddprep();

  vector<pair<lli, pair<int, int> > > aux;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      lli sum = aa[i-1][j-1] + bb[i+1][j+1] + cc[i-1][j+1] + dd[i+1][j-1] + vec[i][j];
      
      aux.push_back({sum, {i, j}});
    }
  }

  sort(aux.begin(), aux.end());
  lli ans = 0;
  int _x, _y, _xx, _yy;
  lli sum = aux[aux.size()-1].F;
  int x = aux[aux.size()-1].S.F;
  int y = aux[aux.size()-1].S.S;
  for(int i=aux.size()-2;i>=0;i--){
    int xx = aux[i].S.F, yy = aux[i].S.S;
    lli sum2 = aux[i].F;
    if(abs(xx - x) == abs(yy-y)){
      if(xx >= x and yy >= y or (xx <= x and yy <= y)){
        sum2 -= (aa[xx][yy] + bb[xx+1][yy+1]);
        if(sum + sum2 >= ans){
          _x = x, _y = y, _xx = xx, _yy = yy;
          ans = sum + sum2;
        }
      } else if(xx >= x and yy <= y or (xx <= x and yy >= y)){
        sum2 -= (cc[xx][yy] + dd[xx+1][yy-1]);
        if(sum + sum2 >= ans){
          _x = x, _y = y, _xx = xx, _yy = yy;
          ans = sum + sum2;
        }
      }
    } else {
      if(sum + sum2 >= ans) {
        ans = sum + sum2;
        _x = x, _y = y, _xx = xx, _yy = yy;
      }
    }
  }

  cout << ans << endl;
  cout << _x << " " << _y << " " << _xx << " " << _yy << endl;
  return 0;
}