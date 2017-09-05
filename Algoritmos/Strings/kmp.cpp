void table(string p){
	v[0] = v[1] = 0;
	int cur = 0;
	for(int j = 2; j < sz(p); j++){
		while(cur != 0 && p[cur] != p[j-1]) cur=v[cur];
		if(p[cur] == p[j-1]) cur++;
		v[j] = cur;
	}
}
bool kmp(string p, string text){
	table(p);
	int cur = 0;
	for(int j = 0; j <sz(text); j++){
		while(cur > 0 && p[cur] != text[j]) cur = v[cur];

		if(p[cur] == text[j])
			if(++cur == sz(p)) return true;

	}
	return false;
}