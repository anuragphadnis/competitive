#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF (long long)1e18
#define MINF (long long)-(1e18)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
using namespace std;
void Arrdisp(int A[],int N)
{
	for(int i=0;i<N;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
void swap(ll &a,ll &b)
{
	a^=b;
	b^=a;
	a^=b;
}
void build(int node,int st,int end,int A[],int tree[])
{
	if(st==end)
	{
		tree[node]=A[st];
	}
	else
	{
		int mid=(st+end)/2;
		build(2*node,st,mid,A,tree);
		build(2*node+1,mid+1,end,A,tree);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}
int query(int node,int st,int end,int l,int r,int tree[])
{
	if(r<st||end<l)
		return INT_MAX;
	if(l<=st&&end<=r)
		return tree[node];
	int mid=(st+end)/2;
	int p1=query(2*node,st,mid,l,r,tree);
	int p2=query(2*node+1,mid+1,end,l,r,tree);
	return min(p1,p2);
}
void update(int node,int st,int end,int idx,int val,int tree[])
{
	if(st==end)
	{
		tree[node]=val;
		return;
	}
	else
	{
		int mid=(st+end)/2;
		if(idx>=st&&idx<=mid)
			update(2*node,st,mid,idx,val,tree);
		else
			update(2*node+1,mid+1,end,idx,val,tree);
	}
	tree[node]=min(tree[2*node],tree[2*node+1]);
}
int main()
{
	int M,N;
	cin>>N>>M;
	int A[N+1],tree[2*N];
	for(int i=0;i<=2*N-1;i++)
		tree[i]=0;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	build(1,1,N,A,tree);
	for(int i=0;i<M;i++)
	{
		char c;
		int l,r;
		cin>>c>>l>>r;
		if(c=='q')
		{
			cout<<query(1,1,N,l,r,tree)<<endl;
		}
		if(c=='u')
		{
			update(1,1,N,l,r,tree);
		}
	}
}

