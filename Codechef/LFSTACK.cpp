#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000000,0);
vector<int> seq;
int size,n;
vector< vector<int> > arr(21);
int solve(int pos){
  if(pos==size){
    for(int i=0;i<n;i++)
    if(dp[i]>0)
    return 0;
    return 1;
  }
  int flag=0;
  for(int i=0;i<n;i++){
    if(dp[i]>0 && arr[i][dp[i]-1]==seq[pos]){
      dp[i]--;
      int subres=solve(pos+1);
      if(subres){
        flag=1;
        break;
      }
    }
  }
  if(flag)
  return 1;
  return 0;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    if(n==1){
      int sz;
      cin>>sz;
      int b[sz];
      for(int i=0;i<sz;i++){
        cin>>b[i];
      }
      int seq[sz];
      for(int i=0;i<sz;i++){
        cin>>seq[i];
      }
      int flag=1;
      for(int i=sz-1;i>=0;i--){
        if(seq[i]!=b[sz-1-i]){
          flag=0;
          break;
        }
      }
      if(flag)
      cout<<"Yes";
      else
      cout<<"No";
    }
    else{
      int sz;
      int seq_sum=0,a;
      for(int i=0;i<n;i++){
        cin>>sz;
        seq_sum+=sz;
        dp[i]=sz;
        for(int j=0;j<sz;j++){
          cin>>a;
          arr[i].push_back(a);
        }
      }
      size=seq_sum;
      for(int i=0;i<seq_sum;i++){
        cin>>a;
        seq.push_back(a);
      }
      if(solve(0))
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
      dp.clear();
      seq.clear();
      arr.clear();
    }
  }
}
