#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<long,long> > arr1,arr2;
  long a;
  for(int i=0;i<n;i++){
    cin>>a;
    arr1.push_back(make_pair(a,i));
  }
  for(int i=0;i<m;i++){
    cin>>a;
    arr2.push_back(make_pair(a,i));
  }
  sort(arr1.begin(),arr1.end());
  sort(arr2.begin(),arr2.end());
  for(int i=0;i<m;i++){
    cout<<arr1[0].second<<" "<<arr2[i].second<<endl;
  }
  for(int i=1;i<n;i++){
    cout<<arr1[i].second<<" "<<arr2[m-1].second<<endl;
  }
  return 0;
}
