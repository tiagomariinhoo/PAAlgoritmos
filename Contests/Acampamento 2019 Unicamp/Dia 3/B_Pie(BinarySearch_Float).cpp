#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int t;
int n, f;
vector<long double> vec;

bool can(long double atual){
  int qt = 0;
  for(auto i : vec) qt += (i/atual);
  //cout << atual << " - " << qt << endl;
  return qt >= f;
}

void ternarySearch(long double l, long double r){

  while(r-l > 1e-9){
    long double mid = (l+r)/2.0;
    if(can(mid)) l = mid;
    else r = mid;
  }

  printf("%.4Lf\n", l);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while(t--){
    cin >> n >> f;
    vec.clear();
    f++;
    long double maxi = 0;
    for(int i=0;i<n;i++){
      long double a;
      cin >> a;
      vec.push_back((a*a)*PI);
      maxi = max(maxi, a*a*PI);
    }

    ternarySearch(0, maxi);
  }

  return 0;
}