string toBinary(unsigned long long int n){
	string r;
	while(n!=0) {r = (n%2==0 ? "0" : "1") + r ; n/=2;}
	return r;
}

unsigned long long int toDecimal(string n){
	return std::stoi(n, nullptr, 2);
}