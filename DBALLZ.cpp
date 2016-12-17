#include<iostream>
using namespace std;
int main()
{
	int t=0,e=0,n=0;
	int eng[10001];
	int time[10001];
	int w[1000001];
	cin>>t;
	while(t--)
	{
		cin>>e>>n;
		for(int i=0;i<n;i++)
			cin>>eng[i];
		for(int j=0;j<n;j++)
			cin>>time[j];
		w[0]=0;
		int best=0;
		for(int x=1;x<=e;x++)
			w[x]=0;
		for(int x=1;x<=e;x++)
		{
			for(int i=0;i<n;i++)
			{
				if(x>=eng[i])
				{
					best=max(w[x-eng[i]]+time[i],best);
				}
			}
			w[x]=best;
		}
		cout<<w[e]<<endl;
	}
	return 0;
}

