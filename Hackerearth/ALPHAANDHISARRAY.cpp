#include<bits/stdc++.h>
#define MAX 400008
using namespace std;

vector<long> seg_tree(MAX);
long arr[MAX/4];
vector<long> res(MAX/4,0);

void build(long left,long right,long node){
  if(left>right)
  return;
  if(left==right){
    seg_tree[node] = arr[left];
    return;
  }
  long mid = left + (right-left)/2;
  build(left,mid,2*node+1);
  build(mid+1,right,2*node+2);
  seg_tree[node] = seg_tree[2*node+1]+seg_tree[2*node+2];
}

void update(long left,long right,long node,long val,long index){
  if(index<left||index>right||seg_tree[node]==0)
  return;

  if(index==right){
    if(seg_tree[node]){
      if(seg_tree[node]>=val){
        cout<<left<<" "<<right<<" "<<seg_tree[node]<<endl;
        res[index] += val;
        seg_tree[node]-= val;
      }
      else{
        res[index] += seg_tree[node];
        seg_tree[node]=0;
      }
      return;
    }
    else
    return;
  }

  long mid = left + (right-left)/2;;
  update(left,mid,2*node+1,val,index);
  update(mid+1,right,2*node+2,val,index);
  seg_tree[node] = seg_tree[2*node+1]+seg_tree[2*node+2];
}


int main(){
  long n;
  cin>>n;
  for(long i=1;i<=n;i++)
  cin>>arr[i];
  build(1,n,0);
  long dec[n+1];
  for(long i=1;i<=n;i++)
  cin>>dec[i];
  for(long i=1;i<=n;i++){
    update(1,n,0,dec[i],i);
  }
  for(long i=1;i<=n;i++)
  cout<<res[i]<<" ";
  return 0;
}
