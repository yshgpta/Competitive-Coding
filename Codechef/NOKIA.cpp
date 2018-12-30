#include<bits/stdc++.h>
using namespace std;
int minlen[31]={0};
int maxlen[31]={0};
void initialize(){
  minlen[0]=0;
  minlen[1]=2;
  maxlen[1]=2;
  for(int i=2;i<31;i++){
    maxlen[i]=(i*(i+3))/2;
    minlen[i]=i+1+minlen[i/2]+minlen[i-1-i/2];
  }
}
int main(){
  initialize();
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    if(m>=minlen[n]){
      if(m<=maxlen[n])
      cout<<"0"<<endl;
      else
      cout<<m-maxlen[n]<<endl;
    }else
    cout<<"-1"<<endl;
  }
  return 0;
}
