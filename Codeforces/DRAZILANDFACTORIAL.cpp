#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long num;
  cin>>num;
  vector<int> hash(11,0);
  int max=-1;
  for(int i=0;i<n;i++){
    int val = num%10;
    if(val>max)
    max=val;
    for(int j=val;j>=2;j--)
    hash[j]++;
    num/=10;
  }
  // for(int i=2;i<10;i++)
  // cout<<hash[i]<<" ";
  while(hash[max]!=0){
    if(max==7 || max==5 || max==3 || max==2){
      cout<<max;
      for(int j=max;j>=2;j--)
      hash[j]--;
      int j=2;
      if(hash[j]==0)
      max = j;
      while(hash[j]!=0 && j<=9){
        max = j;
        j++;
      }
    }
    else{
      if(max==9){
        hash[3]+=2;
      }
      if(max==8){
        hash[2]+=3;
      }
      if(max==6){
        hash[2]++;
        hash[3]++;
      }
      if(max==4){
        hash[2]+=2;
      }
      hash[max]--;
      int j=2;
      while(hash[j]!=0 && j<=9){
        max = j;
        j++;
      }
    }
  }
  return 0;
}
