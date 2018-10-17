#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,199};
		vector<int> semiprimes;
		vector<int>::iterator it,it1;
		for(it=primes.begin();it!=primes.end();it++)
		{
			it1=it+1;
			for(;it1!=primes.end();it1++)
			{
				semiprimes.push_back(*it * *it1);
			}
		}
    sort(semiprimes.begin(),semiprimes.end());
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		vector<int>::iterator it2=semiprimes.begin();
		while(it2!=semiprimes.end() && *it2<=n)
		{
			if(binary_search(semiprimes.begin(),semiprimes.end(),n-*it2))
			{
				flag=1;
				break;
			}
      it2++;
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
return 0;
}
