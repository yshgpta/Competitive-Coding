#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n){
    stack<int> stk;
    long long arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    long long i=0,top,area,max_area=-1;
    while(i<n){
      if(stk.empty()||arr[stk.top()]<=arr[i])
      stk.push(i++);
      else{
        top=stk.top();
        stk.pop();
        if(stk.empty()){
          area=arr[top]*i;
        }
        else
        area=arr[top]*(i-stk.top()-1);
        if(area>max_area)
        max_area=area;
      }
    }
    while(!stk.empty()){
      top=stk.top();
      stk.pop();
      if(stk.empty()){
        area=arr[top]*i;
      }
      else
      area=arr[top]*(i-stk.top()-1);
      if(area>max_area)
      max_area=area;
    }
    cout<<max_area<<endl;
    cin>>n;
  }
  return 0;
}
