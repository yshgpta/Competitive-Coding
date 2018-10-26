#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d;
  cin>>n>>d;
  long len[n];
  for(int i=0;i<n;i++){
    cin>>len[i];
  }
  sort(len,len+n);
  int i=0,pair_count=0;
  while(i<n-1){
    if(len[i]<len[i+1]-d){
      i++;
    }
    else{
      pair_count++;
      i+=2;
    }
  }
  cout<<pair_count<<endl;
  return 0;
}
