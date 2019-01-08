#include<bits/stdc++.h>
#define MAX 400004
using namespace std;

vector<pair<long,long> > seg_tree(MAX);
//seg_tree[node].first = minimum value;
//seg_tree[node].second = sum;
long arr[MAX/4];

void build(int left,int right,int node){
  if(left>right)
  return;

  if(left==right){
    seg_tree[node].first = arr[left];
    return;
  }

  int mid = left + (right-left)/2;
  build(left,mid,2*node+1);
  build(mid+1,right,2*node+2);
  seg_tree[node].first = min(seg_tree[2*node+1].first,seg_tree[2*node+2].first);
}

void update(int left,int right,int node,int val,int acc){
  if(val<seg_tree[node].first-acc+1){
    seg_tree[node].first -= acc;
    seg_tree[node].second += acc;
    return;
  }
  if(left==right){
    seg_tree[node].first -= acc-1;
    seg_tree[node].second += acc-1;
    return;
  }
  if(left>right)
  return;

  int mid = left + (right-left)/2;
  acc += seg_tree[node].second;
  seg_tree[node].second = 0;
  update(left,mid,2*node+1,val,acc);
  update(mid+1,right,2*node+2,val,acc);
  seg_tree[node].first = min(seg_tree[2*node+1].first,seg_tree[2*node+2].first);
}

void solve(int left,int right,int node,int acc){
  if(left==right){
    arr[left]=seg_tree[node].first-acc;
    return;
  }
  if(left>right)
  return;

  int mid = left + (right-left)/2;
  acc += seg_tree[node].second;
  seg_tree[node].second = 0;
  solve(left,mid,2*node+1,acc);
  solve(mid+1,right,2*node+2,acc);
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  build(0,n-1,0);
  int q;
  cin>>q;
  while(q--){
    int a;
    cin>>a;
    update(0,n-1,0,a,1);
  }
  solve(0,n-1,0,0);
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";\
  return 0;
}
