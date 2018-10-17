#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		long long A[n],B[n];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>B[i];
		}
		if(n==1)
		{
			cout<<"TAK"<<endl;
			continue;
		}
		if(n==2)
		{
			long long x,y;
			x=B[0]-A[0];
			y=B[1]-A[1];
			if(2*x==y)
				cout<<"TAK"<<endl;
			else
				cout<<"NIE"<<endl;
			continue;
		}
		for(int i=0;i<n-2;i++)
		{
			long long x=B[i]-A[i];
			if(x<0)
			{
				flag=1;
				break;
			}
      A[i]+=x;
			A[i+1]+=(2*x);
			A[i+2]+=(3*x);
		}
		if(A[n-2]!=B[n-2] || A[n-1]!=B[n-1])
		{
			flag=1;
		}
		if(flag==1)
		{
			cout<<"NIE"<<endl;
		}
		else
			cout<<"TAK"<<endl;
	}
return 0;
}
