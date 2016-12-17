#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	long long dp[5001];
	while(true)
	{
		cin>>s;
		if(s[0]=='0')
			break;
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=s.length();i++)
		{
			dp[i]=0;
			if(s[i-1]!='0')
				dp[i]=dp[i-1];
			if(s[i-2]>48&&(s[i-2]-48)*10+s[i-1]-48<=26)
				dp[i]=dp[i]+dp[i-2];
		}
		cout<<dp[s.length()]<<endl;
	}
	return 0;
}

