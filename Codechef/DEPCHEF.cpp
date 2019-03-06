#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n],d[n];
    vector<pair<int,int> > arr;
    vector<int> res;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>d[i];
    arr.push_back(make_pair(d[n-1],a[n-1]));
    for(int i=0;i<n;i++)
    arr.push_back(make_pair(d[i],a[i]));
    arr.push_back(make_pair(d[0],a[0]));
    for(int i=1;i<=n;i++){
      if(arr[i].first>(arr[i-1].second+arr[i+1].second))
      res.push_back(arr[i].first);
    }
    if(res.size()==0)
    cout<<"-1"<<endl;
    else{
      sort(res.begin(),res.end(),greater<int>());
      cout<<res[0]<<endl;
    }
  }
  return 0;
}
