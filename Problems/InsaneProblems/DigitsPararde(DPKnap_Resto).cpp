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
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

lli pd[1000001][13];
string s;

/*
  D ATcOder
  Quantos numeros consegue formar tal que %13 == 5;
  ? pode botar qualquer digito
 */

lli modFexp(lli x, lli y, lli p){ //Calcula x^y%p em Log Y
	int ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x) % p;
		y = y >> 1;
		x = (x*x) % p;
	}
	return ans;
}

lli solve(int pos , int rem){
  if(pos == sz(s)) return (rem == 5);

  lli &ans = pd[pos][rem];
  if(ans != -1) return ans;
  lli a = 0;
  if(s[pos] == '?'){
    for(int i=0;i<=9;i++)
      a = (a + solve(pos+1, (rem*10 + i)%13 ))%MOD;
  } else {
    a = solve(pos+1, (rem*10 + (s[pos]-'0'))%13)%MOD;
  }

  return ans = a%MOD;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  memset(pd, -1, sizeof pd);

  cout << solve(0, 0)%MOD << endl;


  return 0;
}