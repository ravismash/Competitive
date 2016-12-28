#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<bitset>
typedef long long ll;
ll _sieve_size;
using namespace std;
bitset<10000010>bs;
vector<int>primes;
void arr(int num,int digit[])
{
	int k=3;
	while(num!=0)
	{
		digit[k]=num%10;
		num=num/10;
		k--;
	}
}
int conv(int digit[])
{
	int num=0;
	for(int i=0;i<=3;i++)
	{
		num=num*10+digit[i];
	}
	return num;
}
void sieve(ll upperbound)
{
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=0;
	bs[1]=0;
	for(ll i=2;i<=_sieve_size;i++)
	{
		if(bs[i])
		{
			for(ll j=i*i;j<=_sieve_size;j=j+i)
			{
				bs[j]=0;
			}
			primes.push_back((int)i);
		}
	}
}
int main()
{
	
	sieve(1000001);
/*	for(int i=1001;i<=9999;i++)
		if(bs[i])
			cout<<i<<endl;
*/
	int t;
	cin>>t;
	while(t--)
	{
		int a, b,digit[4],parent[10009],dist[10009];
		scanf("%d%d\n",&a,&b);
		queue<int>q;
		memset(parent,-1,sizeof(parent));
		memset(dist,-1,sizeof(dist));
		q.push(a);
		dist[a]=0;
		parent[a]=0;
		while(!q.empty())
		{
			int num=q.front();
			for(int k=3;k>=0;k--)
			{
				arr(num,digit);
				for(int i=0;i<=9;i++)
				{
					digit[k]=i;
					int temp=conv(digit);
/*					if(temp==b)
						cout<<temp<<" "<<num<<" "<<dist[temp]<<" "<<dist[num]<<" "<<bs[temp]<<endl;
*/
					if(dist[temp]==-1&&bs[temp]==1&&temp>=1000)
					{
						dist[temp]=dist[num]+1;
						parent[temp]=num;
						q.push(temp);
					/*	if(temp==b)
							cout<<temp<<" "<<num<<endl;*/
					}
				}
			}
			q.pop();
		}
		dist[b]==-1 ? cout<<"Impossible"<<endl : cout<<dist[b]<<endl;
	}
	return 0;
}
