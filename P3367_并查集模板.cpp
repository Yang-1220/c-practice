#include <bits/stdc++.h>
#define MAXN 200005
int fa[MAXN];
void init(int n)
{
	for (int i=1;i<=n;i++)
	{
		fa[i] = i;
	}
}
int find(int x)
{
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy; 
}

int main ()
{
	int N,M,Z,i,j;
	scanf("%d %d",&N,&M);
	init(N);
	int x,y;
	while (M--)
	{
		scanf("%d %d %d",&Z,&x,&y);
		if (Z==1)
			unite(x,y);
		else
		{
			if (find(x) == find(y))
				printf("Y\n");
			else
				printf("N\n");
		}
				
	}
	
	return 0;
}