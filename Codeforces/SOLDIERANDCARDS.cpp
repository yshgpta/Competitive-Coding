#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int k1,k2,a;
  queue<int> q1;
  queue<int> q2;
  cin>>k1;
  for(int i=0;i<k1;i++){
    cin>>a;
    q1.push(a);
  }
  cin>>k2;
  for(int i=0;i<k2;i++){
    cin>>a;
    q2.push(a);
  }
  int count=0;
  while(count<100000 && !q1.empty() && !q2.empty()){
    int val1=q1.front();
    int val2=q2.front();
    if(val1>val2){
      q1.pop();
      q2.pop();
      q1.push(val2);
      q1.push(val1);
      count++;
    }else{
      q1.pop();
      q2.pop();
      q2.push(val1);
      q2.push(val2);
      count++;
    }
  }
  if(q2.empty())
  cout<<count<<" "<<"1";
  else if(q1.empty())
  cout<<count<<" "<<"2";
  else
  cout<<"-1";
}
