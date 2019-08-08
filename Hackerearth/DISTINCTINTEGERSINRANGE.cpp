#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],b[100005];
bitset<5005>tree1[300010],tree2[300010];
void build(ll node,ll start,ll end)
{
    if(start>end)
        return;
    if(start==end)
        {
            tree1[node].set(a[start]);
            tree2[node].set(b[start]);
            return;
        }
    ll mid=start+(end-start)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree1[node]=tree1[2*node]|tree1[2*node+1];
    tree2[node]=tree2[2*node]|tree2[2*node+1];
}
bitset<5005>query1(ll node, ll start, ll end, ll l, ll r)
{
    if(start>r||end<l)
        return 0;
    if(start>=l&&end<=r)
        return tree1[node];
    ll mid=start+(end-start)/2;
    return(query1(2*node,start,mid,l,r)|query1(2*node+1,mid+1,end,l,r));
}
bitset<5005>query2(ll node, ll start, ll end, ll l, ll r)
{
    if(start>r||end<l)
        return 0;
    if(start>=l&&end<=r)
        return tree2[node];
    ll mid=start+(end-start)/2;
    return(query2(2*node,start,mid,l,r)|query2(2*node+1,mid+1,end,l,r));
}
int main()
{
	ll n,i,q;
	cin>>n;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	for(i=1;i<=n;i++)
	    cin>>b[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
	    ll a,b,c,d;
	    cin>>a>>b>>c>>d;
	    cout<<(query1(1,1,n,a,b)|query2(1,1,n,c,d)).count()<<endl;
	}
	return 0;
}
