//Source GeeksforGeeks

#include<bits/stdc++.h>
using namespace std;

int getMid(int s, int e) {  return s + (e -s)/2;  }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructST(arr, n);
    printf("Sum of values in given range = %dn",
            getSum(st, n, 1, 3));
    updateValue(arr, st, n, 1, 10);
    printf("Updated sum of values in given range = %dn",
             getSum(st, n, 1, 3));
    return 0;
}

//Construct Tree
void constructTree(int arr[],int segmentTree[], int low,int high,int pos){
    if(low == high){
        segmentTree[pos] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    constructTree(arr,segmentTree,low,mid,2*pos+1);
    constructTree(arr,segmentTree,mid+1,high,2*pos+2);
    segmentTree[pos] = min(segmentTree[2*pos+1],segmentTree[2*pos+2]);
}

int rangeQuerySearch(int segmentTree[],int qlow,int qhigh,int low,int high,int pos){
    if(qlow<=low && qhigh>=high)//Total overlap
    return segmentTree[pos];
    if(qlow>high || qhigh<low)
    return INT_MAX;
    int mid = (low + high)/2;
    return min(rangeQuerySearch(segmentTree,qlow,qhigh,low,mid,2*pos+1),rangeQuerySearch(segmentTree,qlow,qhigh,mid+1,high,2*pos+2));
}


//Minimum Query tree
void updateSegmentTreeRangeLAzy(int segmentTree[],int lazy[],int start,int end,int low,int high,int pos,int delta){
    if(low>high)
    return;

    if(lazy[pos]!=0){
        segmentTree[pos] += lazy[pos];
        if(low!=high){//Not a leaf node
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos]=0;
    }
    //No overlap
    if(start>high || end<low)
    return;

    //Complete overlap
    if(start<=low && end>=high){
        segmentTree[pos] += delta;
        if(low!=high){
            lazy[2*pos+1] += delta;
            lazy[2*pos+2] += delta;
        }
        return;
    }
    //otherwise partial overlap
    int mid = (low+high)/2;
    updateSegmentTreeRangeLAzy(segmentTree,lazy,start,end,low,mid,2*pos+1,delta);
    updateSegmentTreeRangeLAzy(segmentTree,lazy,start,end,mid+1,high,2*pos+2,delta);
    segmentTree[pos] = min(segmentTree[2*pos+1],segmentTree[2*pos+2]);
}