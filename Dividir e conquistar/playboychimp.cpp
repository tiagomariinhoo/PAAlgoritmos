#include <bits/stdc++.h>
#define INF -10000000001
#define DEBUG cout << "AQUI" << endl;
#define vint vector<int>
using namespace std;

int main (){

	int N,Q,element;
		cin >> N;
		vint vec,vec2;
			for(int i=0;i<N;i++){
					cin >> element;
						vec.push_back(element);
			}
		cin >> Q;
			for(int i=0;i<Q;i++){
					cin >> element;
						vec2.push_back(element);
			}

	vector<int>::iterator low,up;
	
	for(int i=0;i<Q;i++){
		low =std::lower_bound(vec.begin(),vec.end(),vec2[i]);
		up =std::upper_bound(vec.begin(),vec.end(),vec2[i]);

		int poslow = low-vec.begin();
		int posup = up-vec.begin();

		if(poslow>0){
			if(vec[poslow-1]<vec2[i]){
				cout << vec[poslow-1] << " ";
			} else {
				cout << "X" << " ";
			}
		} else {
				cout << "X" << " ";
			
		}

		if(posup<vec.size()){
			if(vec[posup]>vec2[i]){
				cout << vec[posup] << endl;
			} else {
				cout << "X" << endl;
			}
		} else {
			cout << "X" << endl;
		}

	}
	return 0;

}