#include<iostream>
using namespace std;
int main()
{
	string s;
	int cnt=0,cnt1=0;
	int n_1,n_0;
	while(getline(cin,s)&&!cin.eof())
	{
		n_1=0;
		n_0=0;
		cnt=0;	
		cnt1=0;
		string s1,s2;
		s1=s;
		s2=s;
		for(int i=0;i<s.length();i++)
		{
			if(isupper(s[i]))
			{
				s[i]='1';
				n_1++;
			}
			else
			{
				s[i]='0';
				n_0++;
			}
		}

		int i=0,j=0,k=0;
		s1[0]='1';
		s2[0]='0';
		for(int i=1;i<s.length();i++)
		{
			if(s1[i-1]=='0')
			{
				s1[i]='1';
				s2[i]='0';
			}
			else
			{
				s1[i]='0';
				s2[i]='1';
			}
		
		}
		for(int i=0;i<s.length();i++)
		{
			if(s1[i]!=s[i])
				cnt++;
			if(s2[i]!=s[i])
				cnt1++;
		}
		int x=min(cnt,cnt1);
		cout<<x<<endl;
		s1.clear();
		s2.clear();
	}
	return 0;
}
