#include<iostream>
using namespace std;
int main()
{
	float arr[275];
	float sum,t;
	for(int i=0;i<275;i++)
	{
		arr[i]=1.0/(2+i);
	}
	cin>>t;
	while(t)
	{	sum=0;
		int i=0;
		for(i=0;i<275;i++)
		{
			sum=sum+arr[i];
			if(sum>t)
				break;
		}
		cout<<(i+1)<<" card(s)"<<endl;
		cin>>t;
	}
	return 0;
}
