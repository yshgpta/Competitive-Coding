#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int max=1,cnt=1;
  for(int i=1;i<n;i++){
    if(arr[i-1]<=arr[i])
    cnt++;
    else
    cnt=1;
    if(max<cnt)
    max=cnt;
  }
  cout<<max<<endl;
  return 0;
}
