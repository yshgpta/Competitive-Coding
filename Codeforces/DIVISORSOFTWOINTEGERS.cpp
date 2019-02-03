#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  vector<int> hash(10005,0);
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    hash[arr[i]]++;
  }
  sort(arr.begin(),arr.end());
  int val1= arr[n-1];
  for(int i=1;i<=arr[n-1];i++){
    if(val1%i==0&& hash[i]>0)
    hash[i]--;
  }
  int max=1;
  for(int i=1;i<=arr[n-1];i++){
    if(max<i && hash[i]>0)
    max=i;
  }
  cout<<val1<<" "<<max;
  return 0;
}
