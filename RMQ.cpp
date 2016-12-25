#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#include<string.h>
#include<math.h> 

#define N 20
#define MAX (1000001) // Why? :D
#define inf 0x7fffffff

int arr[N];
int tree[MAX];
int lazy[MAX];
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = min(tree[node*2], tree[node*2+1]); // Init root value
}
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return INT_MAX; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = min(q1, q2); // Return final result
	
	return res;
}
int main()
{
	int n,t;
	memset(tree,INT_MAX,sizeof tree);
	cin>>n;
	for(int i=0;i<=n-1;i++)
		cin>>arr[i];
	build_tree(1,0,n-1);
	cin>>t;
	while(t--)
	{
		int i,j;
		cin>>i>>j;
		if(i>j)
			swap(i,j);
		int x=query_tree(1,0,n-1,i,j);
		cout<<x<<endl;
	}
	return 0;
}
