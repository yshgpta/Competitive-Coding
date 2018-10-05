#include <bits/stdc++.h>
using namespace std;
int main(){
  int num;
  cin>>num;
  vector<int> arr;
  int a,min=INT_MAX,val;
  while(num--){
    cin>>a;
    arr.push_back(a);
  }
  sort(arr.begin(),arr.end());
  vector<int> diff;
  for(int i=0;i<arr.size()-1;i++){
    for(int j=i+1;j<arr.size();j++){
      val = arr[j]-arr[i];
      if(val<min)
      min=val;
    }
  }
  vector <int> res;
  for(int i=2;i<=min;i++){
    int cnt=1;
    int k = arr[0]%i;
    for(int j=1;j<arr.size();j++){
      if(arr[j]%i==k)
      cnt++;
    }
    if(cnt==arr.size())
    res.push_back(i);
  }
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }
}
