#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dfs(vector<int>* e,int s,int t,long long *dp){
  if(s==t)
  return 1;
  if(dp[s]!=-1)
  return dp[s];
  long long count=0;
  for(int i=0;i<e[s].size();i++){
    int x=e[s][i];
    count += dfs(e,x,t,dp);
    count %= MOD;
  }
  dp[s]=count;
  return dp[s];
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int c,b,s,t;
    cin>>c>>b>>s>>t;
    vector<int> e[c+1];
    long long dp[c+1];
    for(int i=1;i<c+1;i++)
    dp[i]=-1;
    for(int i=0;i<b;i++){
      int a,b;
      cin>>a>>b;
      e[a].push_back(b);
    }
    cout<<dfs(e,s,t,dp)<<endl;
  }
  return 0;
}
