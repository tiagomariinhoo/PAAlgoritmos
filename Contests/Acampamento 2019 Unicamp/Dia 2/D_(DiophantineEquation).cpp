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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int t;
lli n, f, d, nn, ff, dd;

/*
  Problema: Dado n1, f1, d1 e n2, f2, d2
  'n' - Numero de elementos
  'f' - Numero inicial
  'd' - O numero que vai somar

  Achar as intersecções que dá nos dois
  5 3 4 15 3 1
  3 , 7, 11...
  3, 4, 5....

  Solução:
  Achar o número de soluções da equação diofantina

*/

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

bool find_any_solution(lli a, lli b, lli c, lli &x0, lli &y0, lli &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(lli & x, lli & y, lli a, lli b, lli cnt) {
    x += cnt * b;
    y -= cnt * a;
}

lli find_all_solutions(lli a, lli b, lli c, lli minx, lli maxx, lli miny, lli maxy) {
    lli x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    lli sign_a = a > 0 ? +1 : -1;
    lli sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    lli lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    lli rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    lli lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    lli rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    lli lx = max(lx1, lx2);
    lli rx = min(rx1, rx2);

    if (lx > rx)
        return 0;

    return (rx - lx) / abs(b) + 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while(t--){
    cin >> n >> f >> d >> nn >> ff >> dd;
    cout << find_all_solutions(d, -dd, ff-f, 0, n-1, 0, nn-1) << endl;
  }

  return 0;
}