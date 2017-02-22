#include <bits/stdc++.h>
#define DEBUG cout << "AQUI" << endl;
using namespace std;

int main()
{
	int cases;
		cin >> cases;
		for(int i=0;i<cases;i++){
			int n;
			vector<int>vec;
				cin >> n;
					for(int j=0;j<n;j++){
						int element;
						cin >> element;
						vec.push_back(element);
					}
				

			int pont=vec.size()/2;
			while(1){
				if(vec[pont]==1){
					while(vec[pont]==1 && pont<vec.size()){
						pont++;
					}


					cout << vec.size()-pont << endl;
					break;
				} else {
					while(vec[pont]==0 && pont>=0){
						pont--;
					}
					pont++;

					cout << vec.size()-pont << endl;
					break;
				}
			}

		}


	return 0;
}