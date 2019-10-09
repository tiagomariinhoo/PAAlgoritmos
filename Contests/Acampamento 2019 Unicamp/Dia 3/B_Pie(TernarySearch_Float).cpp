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

  long double mid1, mid2, ans = 1000000000;
  while(r-l > 1e-9){
    mid1 = l + (r-l)/3.0;
    mid2 = r - (r-l)/3.0;

    if(can(mid1)){
      ans = mid1, l = mid1;
    } 

    if(can(mid2)){
      ans = mid2, l = mid2;
    }

    if(!can(mid1) and !can(mid2)){
      r = mid2;
      ans = mid2;
    }
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