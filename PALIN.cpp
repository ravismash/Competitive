#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void getnextp(int num[],int n)
{

	int j=(n%2)?n/2+1:n/2;
	int mid=n/2;
	int i=mid-1;
	bool leftsmall=false;
	while(i>=0&&num[i]==num[j])
	{	
		i--;
		j++;

	}	
	if(i<0||num[i]<num[j])
		leftsmall=true;
	while(i>=0)
	{
			num[j]=num[i];
			--i;
			j++;
	}
	if(leftsmall==true)
	{
		int carry=1;
		i=mid-1;
		if(n%2==1)
		{
			num[mid]+=carry;
			carry=num[mid]/10;
			num[mid]=num[mid]%10;
			j=mid+1;
		}
		else
			j=mid;
		
		while(i>=0)
		{
			//cout<<"mid"<<num[i]<<"c"<<carry<<endl;
			num[i]=num[i]+carry;
			carry=num[i]/10;
			num[i]=num[i]%10;
			num[j++]=num[i--];
			//cout<<"mid"<<num[i]<<"c"<<carry<<endl;
		}
	}
}
int are9(int num[],int n)
{

	for(int i=0;i<n;i++)
		if(num[i]!=9)
			return 0;
		return 1;
}
void  gextnextp1(int i[],int n)
{

	if(are9(i,n)==1)
	{
		cout<<1;
		for(int k=1;k<n;k++)
			cout<<0;
		cout<<1<<endl;
	}
	else
	{
		getnextp(i,n);
		for(int k=0;k<n;k++)
			cout<<i[k];
		cout<<endl;
	}


}
int main()
{
	int i[1000000];
	int t,n=0;
	cin>>t;
	string s;

	while(t--)
	{
		n=0;
		cin>>s;
		for(int k=0;k<s.length();k++)
		{
			i[n]=s[k]-'0';
			n++;
		}
		gextnextp1(i,n);
	}
	
	return 0;
}

