#include "bits/stdc++.h"
#define DEBUG cout << "AQUI" << endl;
using namespace std;

int main()
{
	int livros;
		while(cin>>livros){
			vector<int>vec;
			int money;
			
			for(int i=0;i<livros;i++){
				int element;
					cin >> element;
						vec.push_back(element);
			}

		cin >> money;

			sort(vec.begin(),vec.end());
			int x,y;
			int i=vec.size()-1;
			int j=0;

			while(j<i){
				
				if(vec[i]+vec[j]>money) i--;
				else if (vec[i]+vec[j]<money)j++;
				else if(vec[j]+vec[i]==money){
					x=vec[i];
					y=vec[j];
					j++;
					i--;
				}

			}
			cout << "Peter should buy books whose prices are " << y << " and " << x <<".\n\n";
			
        }

	return 0;
}