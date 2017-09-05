// FFT - The Iterative Version
// 
// Running Time:
//    O(n*log n)
// 
// How To Use:
//   fft(a,1)
//   fft(b,1)
//   mul(a,b)
//   fft(a,-1)
//  
// INPUT:
//  - fft method:
//      * The vector representing the polynomial
//      * 1 to normal transform
//      * -1 to inverse transform
//  - mul method:
//      * The two polynomials to be multiplyed
//
// OUTPUT:
//  - fft method: Transforms the vector sent.
//  - mul method: The result is kept in the first vector.
//
// NOTES:
//  - You can either use the struct defined of define cmplx as complex<double>
// 
// SOLVED:
//  * Codeforces Round #296 (Div. 1) D. Fuzzy Search
//  

struct cmplx {
  double real, im;
  cmplx() { real = im = 0.0; }
  cmplx(double real, double im):real(real),im(im){}
  cmplx operator+(const cmplx &o)const { return cmplx(o.real+real, im+o.im); }
  cmplx operator/(double v) const { return cmplx(real/v, im/v); }
  cmplx operator*(const cmplx &o)const { return cmplx(real*o.real-im*o.im, real*o.im+im*o.real); }
  cmplx operator-(const cmplx &o) const { return cmplx(real-o.real, im-o.im); }
};


void fft(vector<cmplx> &A, int s){
  int n = A.size(), p = 0;
  while(n>1){
    p++;
    n >>= 1;
  }
  n = (1<<p);
  vector<cmplx> a=A;
  for(int i = 0; i < n; ++i){
    int rev = 0;
    for(int j = 0; j < p; ++j){
      rev <<= 1;
      rev |= ( (i >> j) & 1 );
    }
    A[i] = a[rev];
  }

  cmplx w, wn;

  for(int i = 1; i <= p; ++i){
    int M = 1 << i;
    int K = M >> 1;
    wn = cmplx(cos(s*2.0*pi/(double)M), sin(s*2.0*pi/(double)M) );
    for(int j = 0; j < n; j += M){
      w = cmplx(1.0, 0.0);
      for(int l = j; l < K + j; ++l){
        cmplx t = w;
        t = t*A[l + K];
        cmplx u = A[l];
        A[l] =A[l]+ t;
        u = u-t;
        A[l + K] = u;
        w = wn*w;
      }
    }
  }

  if(s==-1){
    for(int i = 0;i<n;++i)
      A[i] = A[i]/(double)n;
  }
}

void mul(vector<cmplx> &a, vector<cmplx> &b){
  for(int i=0;i<a.size();i++)a[i]=a[i]*b[i];
}