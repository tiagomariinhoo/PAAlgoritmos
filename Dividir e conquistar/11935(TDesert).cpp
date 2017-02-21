#include "bits/stdc++.h"
#define DEBUG cout << "AQUI" << endl;
using namespace std;

int main()
{
		double total = 0,fuel =0;
		double leak=0;
		string linha;
	while(1){
		string anterior;
			double n;
			double n_anterior = n;
			anterior += linha;
			cin >> n;
			getchar();
			cin >> linha;

			//cout << "N : " << n << endl;
			//cout << "Linha : " << linha << endl;
				total += (n-n_anterior)*leak;
				total += ((n-n_anterior)*fuel)/100;

				if(linha[0] == 'F') {

					string aux;
						cin >> aux;
						
						cin >> fuel;
						getchar();
			//			cout << "Aux : " << aux << endl;
			//			cout << "Fuel : " << fuel << endl;
						if(n==0 && fuel==0) break;

				} else if (linha[0]=='M'){
					leak=0;
				} else if (linha=="Goal"){
					printf ("%.3f\n",total);

					total=0;
					leak=0;
					fuel=0;
				} else if (linha[0]=='G'){				
					total=0;
						string aux;
							cin >> aux;
							getchar();

				} else if (linha[0]=='L'){
					leak++;
				}
	}




	return 0;
}