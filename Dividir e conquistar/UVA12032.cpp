#include <bits/stdc++.h>
#define INF -10000000001
#define DEBUG cout << "AQUI" << endl;
#define vint vector<int>
using namespace std;

void testeVec(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		cout << "Vec i : " << vec[i] << endl;
	}

}


int main (){


	int N,casos,element;

		cin >> casos;
		for(int m=0;m<casos;m++){
			
			cin >> N;
			vint vec,intervalos;

				vec.push_back(0);
				for(int i=0;i<N;i++){
					cin >> element;
						vec.push_back(element);
				}

				int maior = 0;

				for(int i=0;i<vec.size()-1;i++){
					intervalos.push_back(vec[i+1] - vec[i]);
						if(intervalos[i]>maior) maior = intervalos[i];
				}

				int anterior = maior, resp;
				
					while(1){
						anterior = maior;
						resp = anterior;

						for(int i=0;i<intervalos.size();i++){

							if(intervalos[i]==anterior) anterior--;

							else if(intervalos[i]>anterior) {
								anterior=-1;
								break;
							}
						}

						if(anterior>=0) break;

						maior++;

					}

					cout <<"Case " << m+1 << ": " <<resp << endl;




		}

	return 0;
}