#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n){
    int flag=1;
    stack <int> s;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    int j=1,i=1;
    s.push(arr[i]);
    int prev_tos=1005;
    while(!s.empty() && i<=n){
      int tos = s.top();
      if(prev_tos<tos){
        flag=0;
        break;
      }
      prev_tos=1005;
      if(tos==j){
        s.pop();
        j++;
      }
      else{
        prev_tos = s.top();
        s.push(arr[++i]);
      }
      if(s.empty() && i<=n)
      s.push(arr[++i]);
    }
    if(flag)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    cin>>n;
  }
  return 0;
}
