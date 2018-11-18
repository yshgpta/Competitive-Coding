#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n1,n2,n3,n4;
    cin>>n1;
    vector<int> tr(n1);
    for(int i=0;i<n1;i++)
    cin>>tr[i];
    cin>>n2;
    vector<int> dr(n2);
    for(int i=0;i<n2;i++)
    cin>>dr[i];
    cin>>n3;
    vector<int> ts(n3);
    for(int i=0;i<n3;i++)
    cin>>ts[i];
    cin>>n4;
    vector<int> ds(n4);
    for(int i=0;i<n4;i++)
    cin>>ds[i];
    int flag=1;
    for(int i=0;i<n3;i++)
    if(find(tr.begin(),tr.end(),ts[i])==tr.end()){
      flag=0;
      break;
    }
    if(flag)
    for(int i=0;i<n4;i++)
    if(find(dr.begin(),dr.end(),ds[i])==dr.end()){
      flag=0;
      break;
    }
    if(flag)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
  }
}
