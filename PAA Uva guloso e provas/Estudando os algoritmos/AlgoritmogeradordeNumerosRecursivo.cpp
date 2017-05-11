#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAXN 5001
#define MAX 100001
#define INF 1e9
#define D cout << "DEBUG" << endl

vector<long long> vec;

int gerador(long long x,int s, int q, int p){

	if (p>=2 && s==q) vec.push_back(x);
	if(p < 6) gerador(x*10 + 6, s+1, q, p+1);
	if(p < 6) gerador(x*10 + 5, s, q+1, p+1);
}


int main (){
	int n;
		cin >> n;
	gerador(0,0,0,0);
	sort(vec.begin(),vec.end());

	for(int i=0;i<vec.size();i++){
		cout << vec[i] << endl;
	}

	return 0;
}