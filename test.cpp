#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
using namespace std;
#define SIZE 20001
int  parent[SIZE] = {0};
int  size[SIZE] = { 0 };
typedef struct {
	int a;
	int b;
	bool mark;
}EDG;
EDG edg[SIZE] = { 0 };

int ROOT(int x)
{
	while (x != parent[x])
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}
void UNION(int rx, int ry)
{
	if (size[rx] > size[ry])
	{
		parent[ry] = rx;
		size[rx] = size[rx] + size[ry];
	}
	else
	{
		parent[rx] = ry;
		size[ry] = size[ry] + size[rx];
	}
}
int main()
{
///	freopen("NITTROAD_input.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int Nodes, edgeCount, a, b;
		scanf("%d", &Nodes);;
		edgeCount = Nodes-1;
		for (int i = 1; i <= Nodes; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
		for (int i = 1; i <= edgeCount; i++)
		{
			// cin >> edg[i].a >> edg[i].b;
			scanf("%d %d", &edg[i].a, &edg[i].b);	
			edg[i].mark = false;
		}
		int Q = 0;
		scanf("%d", &Q);
		getchar();
		char ch;
		stack<int> R;
		
		while (Q--)
		{
			scanf("%c", &ch);
			if (ch == 'R')
			{
				int k;
				scanf("%d", &k);
				R.push(k); // push in stack
				edg[k].mark = true;
			}
			else if (ch == 'Q')
			{
				R.push(0); //push 0 to mark Query
			}
			getchar();
		}
		unsigned long long  ConnPair = 0;
		// Preapare set of all nodes except the one which are MARKED
		for (int i = 1; i <= edgeCount; i++)
		{
			if (edg[i].mark == false)
			{
				int ra = ROOT(edg[i].a);
				int rb = ROOT(edg[i].b);
				if (ra != rb)
				{
					ConnPair = ConnPair + (size[ra] * size[rb]); // Keep counting the connected Pairs
					UNION(ra, rb);
				}
			}
		}

		unsigned long long  DicConnPair = (Nodes * (Nodes - 1) / 2) - ConnPair;
		stack<unsigned long long> result;
		/// extract Remove operation from STACK and save the ANswer in another stack 
		while (!R.empty())
		{
			int popped = R.top();
			R.pop();
			if (popped > 0)
			{
				int ra = ROOT(edg[popped].a);
				int rb = ROOT(edg[popped].b);
				if (ra != rb)
				{
					DicConnPair = DicConnPair - (size[ra] * size[rb]); // Keep decrementing the pairs based on UNION 
					UNION(ra, rb);
				}
			}
			else
			{
				result.push(DicConnPair);
			}

		}
		//ans
		while (!result.empty()) {

			printf("%llu\n", result.top());
			result.pop();
		}
		if (T > 0)
			printf("\n");
		
	}
	return 0;
}
