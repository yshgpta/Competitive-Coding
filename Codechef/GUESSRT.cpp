#include<bits/stdc++.h>

using namespace std;

long long gcdExtended(int a, long long b, long long *x, long long *y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	long long x1, y1;
	long long gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}
long long modInverse(int a, long long m) {
	long long x, y;
	long long g = gcdExtended(a, m, &x, &y);
	long long res = (x%m + m) % m;
  return res;
}

long long power(long long x, int y)
{
  long long MOD = 1000000007;
    long long res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

int main(){
  int t;
  cin>>t;
  long long MOD = 1000000007;
  while(t--){
    int n,k,m;
    cin>>n>>k>>m;
    long long p,val;
    p = modInverse(n,MOD);
    val = p;
    long long b = ((n-1)*modInverse(n,MOD))%MOD;
    int iter=m/2;
    if(m%2==0)
    iter = m/2-1;
    long long a = b;
    a -= power(b,iter+1);
    p+=a;
    if(m%2==0){
      long long c = power(b,m/2);
      long long d = (c*modInverse(n+k,MOD))%MOD;
      p+=d;
      p%=MOD;
    }
    cout<<p<<endl;
  }
}
