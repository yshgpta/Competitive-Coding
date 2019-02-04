#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int,int> > primes(100001);
  vector<bool> isprime(18409202,true);
  int pos=1;
  int prev = 0;
  for(long long i=3;pos<=100000;i+=2){
    if(isprime[i]){
      for(long long j=i*i;j<18409202;j+=i){
        isprime[j]=false;
      }
      if(i==prev+2){
        primes[pos].first = prev;
        primes[pos].second = i;
        pos++;
      }
      prev = i;
    }
  }
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(scanf("%d",&n)){
    printf("%d %d\n",primes[n].first,primes[n].second);
  }
  return 0;
}
