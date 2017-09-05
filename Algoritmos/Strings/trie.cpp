class Trie{
public:
	int words;
	int prefixes;
	map<char, Trie>edge;

	Trie(){};

	void init(){
		words = 0;
		prefixes = 0;
		edge.clear();
	}

	void addWord(string s){
		if(s.empty()){
			words++;
		}else{
			prefixes++;
			char k = s[0];
			if(!edge.count(k)){
				Trie t;
				edge[k] = t;
				edge[k].init();
			}
			s.erase(s.begin());
			edge[k].addWord(s);
		}
	}

	int countWords(string s){
		if(s.empty()){
			return words;
		}else{
			char k = s[0];
			if(!edge.count(k)) return 0;
			else {
				s.erase(s.begin());
				return edge[k].countWords(s);
			}
		}
	}

	int countPrefix(string s){
		if(s.empty()){
			return prefixes;
		}else{
			char k = s[0];
			if(!edge.count(k)) return 0;
			else {
				s.erase(s.begin());
				return edge[k].countPrefix(s);
			}
		}
	}
	
};