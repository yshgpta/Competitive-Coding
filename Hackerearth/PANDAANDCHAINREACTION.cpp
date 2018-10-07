#include <bits/stdc++.h>
using namespace std;
long arr[1000003];
int main(){
  int t;
  cin>>t;
  arr[0]=arr[1]=1;
  for(int i=2;i<=1000002;i++){
    arr[i]=(arr[i-1]*i)%1000003;
  }
  while(t--){
    long long n,x;
    cin>>n>>x;
    if(n>1000003)
    cout<<"0"<<endl;
    else{
      long result = ((arr[n]%1000003)*(x%1000003))%1000003;
      cout<<result<<endl;
    }
  }
}
