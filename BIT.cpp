#include<iostream>
#include<stdio.h>
using namespace std;
int BIT[1000], a[1000], n;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf("%d", &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf("%d", &a[i]);
           update(i, a[i]);
     }
	int y=query(10);
     cout<<"sum of first 10 elements is" << y<<endl;
	int x=query(7)-query(2-1);	
     cout<<x<<endl;
	return 0;
}
