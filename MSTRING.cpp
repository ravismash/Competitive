#include<iostream>
#include<climits>
#include<algorithm>
#include<cstdio>
# define INF 377777
using namespace std;
int main()
{

int N, M;
/*int next[1003][1003], dp[1003][1003];
    cin >> s >> v;
    N = s.size();
    M = v.size();
    for(int i=0;i<N;++i){
        int prev = -1;
        for(int j=0;j<M;++j){
            if(s[i] == v[j]) prev = j;
            next[i+1][j+1] = prev;
        }
    }
    for(int i=1;i<=N;++i){
        dp[i][0] = 1;
    }
    for(int i=0;i<=M;++i){
        dp[0][i] = INF;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(next[i][j] == -1) dp[i][j] = 1;
            else {
                dp[i][j] = min(1+dp[i-1][next[i][j]], dp[i-1][j]);
            }
        }
    }
    printf("%d\n", dp[N][M]);
*/
	string s,s1;
	int next[1002][1002],dp[1002][1002];
	cin>>s>>s1;
	for(int i=0;i<s.length();i++)
	{
		int prev=-1;
		for(int j=0;j<s1.length();j++)
		{
			if(s[i]==s1[j])
			{
				prev=j;
			}
			next[i+1][j+1]=prev;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=s.length();i++)
		dp[i][0]=1;
	for(int j=1;j<=s1.length();j++)
		dp[0][j]=INF;
	for(int i=1;i<=s.length();i++)
	{
		for(int j=1;j<=s1.length();j++)
		{
			if(next[i][j]!=-1)
			{
				dp[i][j]=min(1+dp[i-1][next[i][j]],dp[i-1][j]);
			}
			if(next[i][j]==-1)
			{	
				dp[i][j]=1;
			}
	
			
		}
	}
	cout<<dp[s.length()][s1.length()]<<endl;
	return 0;
}
