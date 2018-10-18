#include<bits/stdc++.h>
using namespace std;
vector< pair<long ,pair<long,long> > > arr;
long long dp[10005];
long n;
bool cmp(pair<long,pair<long,long>> a,pair<long,pair<long,long>> b){
  return a.first<b.first;
}
long long solve(int pos){
  if(pos>=n)
  return 0;
  if(dp[pos]!=-1)
  return dp[pos];
  long new_pos=lower_bound(arr.begin(),arr.end(),make_pair(arr[pos].second.first,make_pair(0,0)),cmp)-arr.begin();
  return dp[pos]=max(solve(pos+1),arr[pos].second.second+solve(new_pos));
}

int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
      long a,b,c;
      cin>>a>>b>>c;
      long val = a+b;
      arr.push_back(make_pair(a,make_pair(val,c)));
    }
    sort(arr.begin(),arr.end(),cmp);
    memset(dp,-1,sizeof(dp));
    cout<<solve(0)<<endl;
    arr.clear();
  }
  return 0;
}
