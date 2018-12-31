#include<bits/stdc++.h>
using namespace std;
int result[10002]={0};
void initialize(){
  int counter=1,j=2;
  for(int i=4;i<10001;i+=2){
    result[i]=result[i+1]=counter;
    counter+=j;
    j++;
  }
}
int main(){
  initialize();
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<result[n]<<endl;
  }
  return 0;
}
