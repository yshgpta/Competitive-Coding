#include<bits/stdc++.h>
using namespace std;
int divsum(int a){
  int sum=0;
  for(int i=1;i<=a/2;i++){
    if(a%i==0)
    sum += i;
  }
  return sum;
}
int main(){
  int num;
  cin>>num;
  while(num--){
    int a;
    cin>>a;
    cout<<divsum(a)<<endl;
  }
}
