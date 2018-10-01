#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long gcd(long long int a, long long int b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}

int main(){
  int n;
  cin>>n;
  long long int a[n];
  for(long long int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  long long int min=a[0];
  long long int max=a[n-1];
  if(max==min)
  {
      cout<<max<<endl;
  }
  else
  {
  long long ans=1,k;
  for(int i=0;i<n;i++){
      ans = ans *a[i]/gcd(ans,a[i]);
  }
  cout<<ans<<endl;
}
}
