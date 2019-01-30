#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long arr[n][n];
    long brr[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>brr[i][j];
    int flag=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(arr[i][j]!=brr[i][j]){
        long temp = brr[i][j];
        brr[i][j] = brr[j][i];
        brr[j][i] = temp;
      }
      if(arr[i][j]!=brr[i][j]){
        flag=0;
        break;
      }
    }
    if(flag==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
  }
  return 0;
}
