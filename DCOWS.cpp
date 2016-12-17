#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long min(long long x,long long y)
{
	if(x<y)
		return x;
	return y;
} 
long long dp[5001][5001];
int main()
{
	int n;
	int m;
	cin>>n>>m;
	long b[5001]={0},c[5001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>b[i];	
		dp[i][0]=999999999;		
 
	}
	for(int j=0;j<m;j++)
	{
		cin>>c[j];
		dp[0][j]=0;
	}
	if(m<n)
		cout<<1000000000;
	sort(b,b+n);
	sort(c,c+m);
 	
	dp[0][0]=abs(b[0]-c[0]);
	if(n<=m)
      	{ for(int i=0;i<n;i++)
		{
		for(int j=i;j<m;j++)
		{
			if(i==j)
			{
				if(i==0)	dp[i][j]=abs(b[0]-c[0]);
				else
					dp[i][j]=dp[i-1][j-1]+abs(b[i]-c[j]);
			}
			else if(i==0)
			{
				dp[i][j]=min(dp[i][j-1],abs(b[i]-c[j]));
			}
			else
			{
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(b[i]-c[j]));
			}
		}
	}
	cout<<dp[n-1][m-1]<<endl;	
	}
	return 0;
}

