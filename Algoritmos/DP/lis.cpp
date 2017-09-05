int lis(vector<int> *Ar, int N){
   for(int i = N - 1; i >= 0; i--) {
        LIS[i] = 1;
        for(int j = i + 1; j < N; j++) {
            if(Ar[i] < Ar[j]) LIS[i] = max(LIS[j] + 1, LIS[i]);
        }
    }
}