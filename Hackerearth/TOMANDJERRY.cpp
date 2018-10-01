#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int val = arr[i][j];
      if(i+1!=n && j+1!=m){
        if(val==arr[i+1][j])
        cnt++;
        if(val==arr[i][j+1])
        cnt++;
      }else if(i+1!=n && j+1==m){
        if(val==arr[i+1][j])
        cnt++;
      }else if(i+1==n && j+1!=m){
        if(val==arr[i][j+1])
        cnt++;
      }else
      break;
      }
    }
  cout<<cnt<<endl;
}
