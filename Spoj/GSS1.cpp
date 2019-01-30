#include<bits/stdc++.h>
#define MAX 200004
#define INF 100000007
using namespace std;
struct Node{
  int prefixSum;
  int suffixSum;
  int totalSum;
  int maxSum;
};

Node seg_tree[MAX];
int arr[MAX/4];

Node mergeNode(Node lChild,Node rChild){
  Node parentNode;
  parentNode.prefixSum = max(lChild.prefixSum,lChild.totalSum+rChild.prefixSum);
  parentNode.suffixSum = max(rChild.suffixSum,rChild.totalSum+lChild.suffixSum);
  parentNode.totalSum = lChild.totalSum + rChild.totalSum;
  parentNode.maxSum = max(parentNode.prefixSum,max(parentNode.suffixSum,max(lChild.maxSum,max(rChild.maxSum,lChild.suffixSum+rChild.prefixSum))));
  return parentNode;
}

void build(int left,int right,int node){
  if(left>right)
  return;

  if(left==right){
    seg_tree[node].prefixSum = seg_tree[node].suffixSum = seg_tree[node].totalSum = seg_tree[node].maxSum = arr[left];
    return;
  }

  int mid = left+(right-left)/2;
  build(left,mid,2*node+1);
  build(mid+1,right,2*node+2);
  seg_tree[node] = mergeNode(seg_tree[2*node+1],seg_tree[2*node+2]);
}

Node query(int left,int right,int node,int x,int y){
  if(x>right || y<left ||left>right){
    Node nullNode;
    nullNode.prefixSum = nullNode.suffixSum = nullNode.totalSum = nullNode.maxSum = -INF;
    return nullNode;
  }
  if(left>=x && right<=y)
  return seg_tree[node];

  int mid = left+(right-left)/2;
  Node Left = query(left,mid,2*node+1,x,y);
  Node Right = query(mid+1,right,2*node+2,x,y);
  if(x>mid)
  return Right;
  if(y<=mid)
  return Left;
  seg_tree[node] = mergeNode(Left,Right);
  return seg_tree[node];
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>arr[i];
  build(1,n,0);
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<query(1,n,0,a,b).maxSum<<endl;
  }
  return 0;
}
