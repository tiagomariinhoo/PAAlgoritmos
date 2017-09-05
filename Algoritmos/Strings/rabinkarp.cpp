#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int base = 257;
vector<int>ans;
unsigned hash(const string& s){
    long long ret = 0;
    for (int i = 0; i < s.size(); i++)ret=(ret*base+ s[i])%mod;
    return ret;
}
int rabin_karp(const string& needle, const string& haystack){
    long long hash1 = hash(needle);
    long long hash2 = 0;
    long long power = 1;
    for (int i = 0; i < needle.size(); i++)power=(power*base)%mod;
    for (int i = 0; i < haystack.size(); i++){
        hash2 = hash2*base + haystack[i];
        hash2%=mod;
        if (i >= needle.size()){
            hash2 -= power*haystack[i-needle.size()]%mod;
            while(hash2 < 0)hash2+=mod;
        }
        if (i >= needle.size()-1 && hash1 == hash2)ans.push_back(i - (needle.size()-1));
    }
    if(ans.size())return 1;
    return 0;
}
int main(){
    string s = "auhas";
    string s2 = "asdauhasaeauhasuh";
    string s3 = "kkkkkkkkk";
    if(rabin_karp(s, s2)){
        printf("found\n");
        for(int i = 0; i < ans.size(); i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    ans.clear();
    if(!rabin_karp(s, s3)){
        printf("not found\n");
    }
}
