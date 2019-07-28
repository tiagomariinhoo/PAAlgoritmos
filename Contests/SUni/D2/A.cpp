#include <bits/stdc++.h>
using namespace std;

int sum[5001];

bool check(int n){

	set<int> aux;
	aux.insert(n%10);
	n/=10;

	while(n > 0){
		if(aux.find(n%10) != aux.end()) return false;
		aux.insert(n%10);
		n/=10;
	}

	return true;
}

void preComp(){

	for(int i=1;i<=5000;i++){
		sum[i] = sum[i-1] + check(i);
	}

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  preComp();

  int n, m;
  while(cin >> n >> m){
  	cout << sum[m] - sum[n-1] << endl;
  }



  return 0;
}