#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n,k;
  cin>>n>>k;
  long int arr[n];
  for(long int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  long int count=0,i,j;
  for(i=0,j=1;i<n;){
      if(abs(arr[i]-arr[j])>=k){
        count+=(n-j);
        i++;
      }
      else
      j++;
  }
  cout<<count<<endl;
  return 0;
}
