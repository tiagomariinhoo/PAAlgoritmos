void comprime(vector<ii> &aux){
  vi aux2;
  for(int i=0;i<sz(aux);i++) aux2.pb(aux[i].F), aux2.pb(aux[i].S);
  sort(aux2.begin(), aux2.end());
  
  for(int i=0;i<sz(aux);i++){
    aux[i].F = lower_bound(aux2.begin(), aux2.end(), aux[i].F) - aux2.begin() + 1;
    aux[i].S = lower_bound(aux2.begin(), aux2.end(), aux[i].S) - aux2.begin() + 1;
    maxi = max({maxi, aux[i].F, aux[i].S});
  }
}

void compress(vector<int> &aux) {
  vector<int> aux2;
  for(int i=0;i<sz(aux);i++) aux2.push_back(aux[i]);
  sort(aux2.begin(), aux2.end());

  for(int i=0;i<sz(aux);i++){
    aux[i] = lower_bound(aux2.begin(), aux2.end(), aux[i]) - aux2.begin();
  }
}