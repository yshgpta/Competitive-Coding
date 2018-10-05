#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> arr;
  int a;
  int num = n;
  while(n--){
    cin>>a;
    arr.push_back(a);
  }
  int cnt=0,i=0;
  while(x>0){
    x -= arr[i++];
    cnt++;
  }
  cout<<cnt;
}
