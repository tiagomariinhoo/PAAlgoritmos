#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<lli,lli> ii;

lli k, d, t;

lli multiplo(){
  return (k + d - (k%d));
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  cin >> k >> d >> t;

  if(k%d == 0 or k >= t){
    cout << t << endl;
    return 0;
  }

  lli x = d;
  if(x < k)
  x = multiplo();
  long double kk = k;
  long double dif = (x - k);
  long double sum = (kk + dif*0.5);
  lli tempo = (x);
  lli qt = (t / sum);

  sum *= qt;
  tempo *= qt;
  if(sum >= t){
    printf("%lld", tempo);
    return 0;
  }

  if(t - sum >= k){
    lli l = 0, r = 1e18;
    while(l < r){
      lli mid = (l + r) >> 1;
      if(k + sum + mid*0.5 >= t){
        r = mid;
      } else l = mid + 1;
    }
    long double anss = (tempo + r + k);
    printf("%.2Lf", anss);
  } else {
    lli l = 0, r = 1e18;
    while(l < r){
      lli mid = (l + r) >> 1;
      if((long double)mid*0.5 + sum >= t){
        r = mid;
      } else l = mid + 1;
    }
    // cout << tempo << " " << r << endl;
    printf("%.2Lf", tempo + (long double)r/2);
  }



  return 0;
}