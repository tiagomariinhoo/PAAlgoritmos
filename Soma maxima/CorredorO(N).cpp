#include "bits/stdc++.h"
#define DEBUG cout << "AQUI" << endl;
using namespace std;



int main()
{
	int n;
		cin >> n;
		vector<int> vec;
		
			for(int i=0;i<n;i++){
				int element;
					cin >> element;	
						vec.push_back(element);
			}

		int i=0;
			while(vec[i]<0) i++;
		int maior=0,soma=0;
			for(;i<vec.size();i++){
				maior = max(0,maior+vec[i]);
				soma = max(soma,maior);
			}		
		cout << soma << endl;


	return 0;
}