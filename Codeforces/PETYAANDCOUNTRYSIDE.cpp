#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> count(n,1);
  vector<int> height(n);
  for(int i=0;i<n;i++)
  cin>>height[i];
  int x=0,after,before;
  after=1;
  while(after<n && height[x]>=height[after]){
    count[0]++;
    x=after;
    after++;
  }
  for(int i=1;i<n-1;i++){
    x=i,
    before = i-1;
    after = i+1;
    while(height[x]>=height[before] && before>=0){
      count[i]++;
      x=before;
      before--;
    }
    x=i;
    while(height[x]>=height[after] && after<n){
      count[i]++;
      x=after;
      after++;
    }
  }
  x=n-1;
  before = n-2;
  while(before>=0 && height[x]>=height[before]){
    count[n-1]++;
    x=before;
    before--;
  }
  sort(count.begin(),count.end());
  cout<<count[n-1];
  return 0;
}
