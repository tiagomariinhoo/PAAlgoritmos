#include "bits/stdc++.h"
#define DEBUG cout << "AQUI" << endl;
using namespace std;

int main()
{
	int cases;
		cin >> cases;
			for(int m=0;m<cases;m++){
				int n;
					cin >> n;
					vector <int> vec;

						for(int i=0;i<n;i++){
							int element;
								cin >> element;
								vec.push_back(element);
						}

						int razao = (vec[vec.size()-1]-vec[0])/((vec.size()));

						for(int i=1;i<vec.size();i++){
							if(vec[i]-vec[i-1]!=razao){
								cout << vec[i]-razao << endl;
								break;
}
						}

			}

	return 0;
}