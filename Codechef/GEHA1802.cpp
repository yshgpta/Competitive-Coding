#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long n,m;
    cin>>n>>m;
    long long h[n+1]={0};
    long long b;
    for(int i=0;i<m;i++){
      cin>>b;
      h[b]++;
    }
    stack<int> stk;
    long long i=0,top,area,max_area=-1;
    while(i<n+1){
      if(stk.empty()||h[stk.top()]<=h[i])
      stk.push(i++);
      else{
        top=stk.top();
        stk.pop();
        if(stk.empty()){
          area=h[top]*i;
        }
        else
        area=h[top]*(i-stk.top()-1);
        if(area>max_area)
        max_area=area;
      }
    }
    while(!stk.empty()){
      top=stk.top();
      stk.pop();
      if(stk.empty()){
        area=h[top]*i;
      }
      else
      area=h[top]*(i-stk.top()-1);
      if(area>max_area)
      max_area=area;
    }
    cout<<max_area<<endl;
  }
  return 0;
}
