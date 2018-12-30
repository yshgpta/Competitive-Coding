#include<bits/stdc++.h>
using namespace std;


vector<long long> left_sum_max(vector<long long> &arr,int n){
  vector<long long> res(n,0);
  long long currentMax=arr[0];
  res[0]=arr[0];
  for(int i=1;i<n;i++){
    currentMax = max(currentMax,arr[i]+currentMax);
    res[i]=max(currentMax,res[i-1]);
  }
  return res;
}
vector<long long> left_sum_min(vector<long long> &arr,int n){
  vector<long long> res(n,0);
  long long currentMin=arr[0];
  res[0]=arr[0];
  for(int i=1;i<n;i++){
    currentMin = min(currentMin,arr[i]+currentMin);
    res[i]=min(currentMin,res[i-1]);
  }
  return res;
}
vector<long long> right_sum_min(vector<long long> &arr,int n){
  vector<long long> res(n,0);
  long long currentMin=arr[n-1];
  res[n-1]=arr[n-1];
  for(int i=n-2;i>=0;i--){
    currentMin = min(currentMin,arr[i]+currentMin);
    res[i]=min(currentMin,res[i+1]);
  }
  return res;
}
vector<long long> right_sum_max(vector<long long> &arr,int n){
  vector<long long> res(n,0);
  long long currentMin=arr[n-1];
  res[n-1]=arr[n-1];
  for(int i=n-2;i>=0;i--){
    currentMin = max(currentMin,arr[i]+currentMin);
    res[i]=max(currentMin,res[i+1]);
  }
  return res;
}


long long compute(vector<long long>& arr,int n){
  long long maxDiff = arr[0]-arr[1];
  vector<long long> leftSumMax = left_sum_max(arr,n);
  vector<long long> leftSumMin = left_sum_min(arr,n);
  vector<long long> rightSumMax = right_sum_max(arr,n);
  vector<long long> rightSumMin = right_sum_min(arr,n);
  long long diff;
  for(int i=0;i<n;i++){
    diff = leftSumMax[i]-rightSumMin[i];
    if(diff>maxDiff)
    maxDiff=diff;
    diff = rightSumMax[i]-leftSumMin[i];
    if(diff>maxDiff)
    maxDiff=diff;
  }
  return diff;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<compute(arr,n)<<endl;
  }
  return 0;
}
