// Checa se é potencia de 2
bool pot(lli x){
	return x && (!(x&(x-1)));
}

// Checa se a é substring de b
bool check(string a, string b){
	if(b.find(a) != std::string::npos) return true;
	return false;
}
