#include<iostream>
#include<string>
using namespace std;
	
int main()
{
	string s,s1;
	int t;
	while(getline(cin, s) && !cin.eof())
	{
//		cin>>s;
//		s1=s;
//		s1.append("h");
		int i=0;
		int is=0;
		int uscore=0;
		while(i<s.length())
		{
			if(!isalpha(s[i]))
				uscore=1;
			else if(isupper(s[i+1]))
				is=1;
			if(s[i]=='_')		
			{
				if(isupper(s[i+1]))
					is=1;
				
			}	
			i++;
		}
		if(uscore==1&&is==1)
			cout<<"Error!";
		if(uscore==1&&is==0)
		{
			int i=0,j=0;
			while(i<s.length())
			{
				if(s[i]!='_')
				{
					cout<<s[i];
					i++;

				
				}
				else if(s[i]=='_')
				{
					i++;
					if(i<s.length())
					{
						cout<<(char)toupper(s[i]);
					}
					i++;
				}
			
			}
		}
		else if(uscore==0&&is==1)
		{
			int i=0,j=0;
			while(i<s.length())
			{
				if(!isupper(s[i]))
				{
					cout<<s[i];
				//	s1[j]=s[i];
				}
				else
				{
					cout<<"_"<<char(tolower(s[i]));
				//	s1[j]=' ';
				//	j++;
				//	s1[j]=s[i];
				}
				if(i<s.length())	
				{	
					i++;
				}
			}
		}
		else if(uscore==0&&is==0)
		{
			cout<<s;
		}
		cout<<endl;
		s.clear();
	}
	return 0;
}
