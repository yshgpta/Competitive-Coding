#include<bits/stdc++.h>
using namespace std;
long long sum[100005];
void calcSum(){
  sum[0]=0;
  for(int i=1;i<=100000;i++){
    sum[i]=sum[i-1]+i;
  }
}
int main(){
  calcSum();
  int t;
  cin>>t;
  while(t--){
    long n;
    cin>>n;
    string str;
    cin>>str;
    long count=0;
    for(long i=0;i<n;i++){
      if(str[i]=='1')
      count++;
    }
    cout<<sum[count]<<endl;
  }
  return 0;
}
