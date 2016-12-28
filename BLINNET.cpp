#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>pr;
typedef pair<int,pr>edg;
# define MAX 10001
vector<edg>eg;
int parent[MAX];
int find(int x)
{
	if(x!=parent[x])
		x=find(parent[x]);
	return parent[x];
}
int main()
{
	char city[20];
	int t,c,v,w,e;
	cin>>t;
	while(t--)
	{
		eg.clear();
		cin>>c;
		for(int i=1;i<=c;i++)
		{
			parent[i]=i;
			scanf("%s%d",city,&e);
			while(e--)
			{
				scanf("%d%d",&v,&w);
				if(v>i)
					eg.push_back(edg(w,pr(i,v)));
			}
		}
	
		sort(eg.begin(),eg.end());
		int sz=eg.size();
		int cost=0,u=0;
		for(int i=0;i<sz;i++)
		{
			u=find(eg[i].second.first);
			v=find(eg[i].second.second);
			w=eg[i].first;
			if(u!=v)
			{
				cost=cost+w;
				parent[u]=parent[v];
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}
