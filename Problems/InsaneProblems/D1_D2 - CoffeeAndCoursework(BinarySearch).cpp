#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010
#define MAXL 20
#define F first
#define S second
#define lli long long int

int n, m;
vector<int> vec;
bool at = false;

bool comp(int a, int b){
	return a > b;
}

bool solve(int atual){

	int mm = m;
	int j = 0, vol = 0;
	for(int i=0;i<vec.size();i++){
		mm -= max(0, (vec[i] - vol));
		if(mm <= 0){
			at = true;
			return true;
		}
		j++;
		if(j == atual) j = 0, vol++;
	}

	return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	vec.push_back(a);
  }

  sort(vec.begin(), vec.end(), comp);

  int com = 1, fim = n;
  while(com < fim){
  	int mid = (com + fim) >> 1;
  	if(solve(mid)) fim = mid;
  	else com = mid + 1;
  }
  if(!solve(fim)){
  	cout << -1 << endl;
  	return 0;
  }

  cout << fim << endl;

  return 0;
}