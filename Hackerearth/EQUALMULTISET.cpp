#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
  long long n;
  long long diff,count=0;
  cin>>n;
  vector<long long> arr(n);
  vector<long long> brr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  for(int i=0;i<n;i++)
  cin>>brr[i];
  sort(arr.begin(),arr.end());
  sort(brr.begin(),brr.end());
  for(int i=0;i<n;i++){
    diff = abs(arr[i]-brr[i]);
    count+=diff;
  }
  cout<<count%MOD;
  return 0;
}
