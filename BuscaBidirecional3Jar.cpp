#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

struct State{
	int vec[3];
};

queue<State> q1, q2;
vector<State> vis, vis2;
State ans, ans2;
bool at1, at2;

bool test(State state, int a){

	if(a == 1){
		if(!sz(vis)) return false;
		for(int i=0;i<sz(vis);i++){
			int count = 0;
			for(int j=0;j<3;j++){
				if(vis[i].vec[j] == state.vec[j]) count++;
			}
			if(count == 3) return false;
		}
	} else {
		if(!sz(vis2)) return false;
		for(int i=0;i<sz(vis2);i++){
			int count = 0;
			for(int j=0;j<3;j++){
				if(vis2[i].vec[j] == state.vec[j]) count++;
			}
			if(count == 3) return false;
		}
	}

	return true;
}

vector<State> getState(State aux, int a){
	vector<State> state;

	if(aux.vec[0] > 0) {
			State aux2 = aux;
			State aux3 = aux;
			int qt = aux.vec[0];
			if(aux.vec[1] < 5) {
				if(qt > (5 - aux.vec[1])) {
					aux2.vec[0] -= (5 - aux.vec[1]);
					aux2.vec[1] = 5;
					if(test(aux2, a)) state.pb(aux2);
				} else {
					aux2.vec[0] = 0;
					aux2.vec[1] += qt;
					if(test(aux2, a)) state.pb(aux2);
				}
			}
			
			if(aux.vec[2] < 3) {
				if(qt > (3 - aux.vec[2])) {
					aux3.vec[0] -= (3 - aux.vec[2]);
					aux3.vec[2] = 3;
					if(test(aux3, a)) state.pb(aux3);
				} else {
					aux3.vec[0] = 0;
					aux3.vec[2] += qt;
					if(test(aux3, a)) state.pb(aux3);
				}
			}
		}
		
		if(aux.vec[1] > 0) {
			State aux2 = aux;
			State aux3 = aux;
			int qt = aux.vec[1];
			if(aux.vec[0] < 8) {
				if(qt > (8 - aux.vec[0])) {
					aux2.vec[0]	= 8;
					aux2.vec[1] -= (8 - aux.vec[0]);
					if(test(aux2, a)) state.pb(aux2);
				} else {
					aux2.vec[0] += qt;
					aux2.vec[1]  = 0;
					if(test(aux2, a)) state.pb(aux2);
				}
			}
			
			if(aux.vec[2] < 3) {
				if(qt > (3 - aux.vec[2])) {
					aux3.vec[2] = 3;
					aux3.vec[1] -= (3 - aux.vec[2]);
					if(test(aux3, a)) state.pb(aux3);
				} else {
					aux3.vec[1] = 0;
					aux3.vec[2] += qt;
					if(test(aux3, a)) state.pb(aux3);
				}
			}
		}
		
		if(aux.vec[2] > 0) {
			State aux2 = aux;
			State aux3 = aux;
			int qt = aux.vec[2];
			if(aux.vec[0] < 8) {
				if(qt > (8 - aux.vec[0])) {
					aux2.vec[0] = 8;
					aux2.vec[2] -= (8 - aux.vec[0]);
					if(test(aux2, a)) state.pb(aux2);
				} else {
					aux2.vec[0] += qt;
					aux2.vec[2] = 0;
					if(test(aux2, a)) state.pb(aux2);
				}
			}
			
			if(aux.vec[1] < 5) {
				if(qt > (5 - aux.vec[1])) {
					aux3.vec[1] = 5;
					aux3.vec[2] -= (5 - aux.vec[1]);
					if(test(aux3, a)) state.pb(aux3);
				} else {
					aux3.vec[1] += qt;
					aux3.vec[2] = 0;
					if(test(aux3, a)) state.pb(aux3);
				}
			}
		}

	return state;
}

bool have(State state, int a){

	if(a == 1){
		for(int i=0;i<sz(vis);i++){
			int count = 0;
			for(int j=0;j<3;j++){
				if(vis[i].vec[j] == state.vec[j]) count++;
			}
			if(count == 3){
				for(int j=0;j<3;j++) cout << state.vec[j] << " - ";
				cout << endl;
			return true;
			}
		}
	} else {
		for(int i=0;i<sz(vis2);i++){
			int count = 0;
			for(int j=0;j<3;j++){
				if(vis2[i].vec[j] == state.vec[j]) count++;
			}
			if(count == 3) return true;
		}
	}
	return false;
}

bool test2(State cur, State atual, int a){
	vector<State> aux2 = getState(cur, 1);

	bool at = false;
	for(int i=0;i<sz(aux2);i++){
		int c = 0;
		for(int j=0;j<3;j++){
			// cout << aux2[i].vec[j] << " ";
			if(aux2[i].vec[j] == atual.vec[j]) c++;
		}
		if(c == 3) at = true;
	}

	return at;
}

bool getPath(int a){
	if(a == 1){
		vector<State> aux;
		bool att = false;
		while(sz(q1)){
			State u = q1.front();
			q1.pop();

			// if(test(u, 1))
			vis.pb(u);

			vector<State> aux2 = getState(u, a);

			for(auto i : aux2){
				if(!test(i, a)) continue;
				// if(test(i, 1)){
					// vis.pb(i);
				// } 
					aux.pb(i);

					if(have(i, 2)){
						ans = i;
						att = true;
					}
			}
		}
		for(auto i : aux) q1.push(i);
		return att;
	} else{
		vector<State> aux;
		bool att = false;
		while(sz(q2)){
			State u = q2.front();
			q2.pop();

			// if(test(u, 2)){
			vis2.pb(u);
			// }

			vector<State> aux2 = getState(u, a);
			for(auto i : aux2){
				if(!test(i, a)) continue;
				if(!test2(i, u, a)) continue;

				// if(test(i, 2)){
					// vis2.pb(i);
				// }


					aux.pb(i);
				if(have(i, 2)){
					att = true;
					ans2 = i;
				}
			}
		}
		for(auto i : aux) q2.push(i);
		return att;
	}
	return false;
}

bool Intersection(){

	for(int i=0;i<sz(vis);i++){
		for(int j=0;j<sz(vis2);j++){
			int c = 0;
			for(int k=0;k<3;k++){
				if(vis[i].vec[k] == vis2[j].vec[k]) c++;
			}
			if(c == 3) return true;
		}
	}

	return false;
}

void pathBiSearch(){
	while(!q1.empty() and !q2.empty()){

		bool aa = getPath(1);
		bool bb = getPath(2);

		if(Intersection()){

			cout << "Vis 1 : " << endl;
			for(int i=0;i<sz(vis);i++){
				for(int j=0;j<3;j++){
					cout << vis[i].vec[j] << " ";
				} cout << endl;
			} cout <<"  -- - -  " << endl;
			cout << "Vis 2 : " << endl;
			for(int i=0;i<sz(vis2);i++){
				for(int j=0;j<3;j++){
					cout << vis2[i].vec[j] << " ";
				} cout << endl;
			} cout << " - - - - " << endl;

			cout << "ACHOU!" << endl;

			return ;
		}
	}
	cout << "NAO ACHOU!" << endl;
}

int main(){	
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	State state1, state2;
	state1.vec[0] = 8, state1.vec[1] = 0, state1.vec[2] = 0;
	state2.vec[0] = 4, state2.vec[1] = 4, state2.vec[2] = 0;
	q1.push(state1), q2.push(state2);
	pathBiSearch();

	return 0;
}

/*

	                                                 Grande Média Pequena
Situação inicial                                   8      0      0
Despeja a água da grande até encher a pequena      5      0      3
Despeja toda a água da pequena na média            5      3      0
Despeja a água da grande até encher a pequena      2      3      3
Despeja a água da pequena até encher a média       2      5      1
Despeja toda a água da média na grande             7      0      1
Despeja toda a água da pequena na média            7      1      0
Despeja a água da grande até encher a pequena      4      1      3
Despeja toda a água da pequena na média            4      4      0


*/
