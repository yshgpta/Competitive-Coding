#include<bits/stdc++.h>
#define MAX 2000020
using namespace std;

vector<long> seg_tree(MAX);

void build(int left,int right,int node){
  if(left>right)
  return;
  if(left==right){
    seg_tree[node] = 0;
    return;
  }
  int mid = left + (right-left)/2;
  build(left,mid,2*node+1);
  build(mid+1,right,2*node+2);
  seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}


void query1(int left,int right,int node,int index){
  if(index<left || index>right)
  return;

  if(left==right){
    if(left==index){
    seg_tree[node]++;
  }
    return;
  }
  if(left>right)
  return;

  int mid = left + (right-left)/2;
  query1(left,mid,2*node+1,index);
  query1(mid+1,right,2*node+2,index);
  seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

void query2(int left,int right,int node,int index){
  if(index<left || index>right)
  return;

  if(left==right){
    if(left==index){
      if(seg_tree[node])
        seg_tree[node]--;
  }
    return;
  }
  if(left>right)
  return;

  int mid = left + (right-left)/2;
  query2(left,mid,2*node+1,index);
  query2(mid+1,right,2*node+2,index);
  seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

long query3(int left,int right,int node,int x,int y){
  if(x<=left && y>=right){
    return seg_tree[node];
  }

  if(x>right || y<left)
  return 0;

  int mid = left + (right-left)/2;
  return query3(left,mid,2*node+1,x,y)+query3(mid+1,right,2*node+2,x,y);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q;
  cin>>n>>q;
  build(1,n,0);
  while(q--){
    int op,a;
    cin>>op>>a;
    if(op==1)
    query1(1,n,0,a);
    if(op==2)
    query2(1,n,0,a);
    if(op==3){
      int b;
      cin>>b;
      cout<<query3(1,n,0,a,b)<<endl;
    }
  }
  return 0;
}
