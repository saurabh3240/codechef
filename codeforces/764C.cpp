
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include<unordered_map>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
 
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
#define INF 1000000000
#define ull unsigned long long
using namespace std;
ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='\n'); //buffer clear
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;a = b; b = r;
	}
	return a;
}

vector<int> edges[200005];
int color[200005];
int exist[200005];
int visited[200005];


int  dfsA(int x)
{
	if(visited[x])
		return -1;
	visited[x]=1;
	
	int colret =  color[x];
	exist[x]=1;
	
	rep(i,edges[x].size())
	{
		int y = dfsA(edges[x][i]);
		if(y==-1)
		{
				
		}
		else if(y==0)
		{
			exist[x]=0;
		}
		else
		{
			if(colret==y)
			{
				exist[x]=1;
			}
			else
			{
				exist[x]=0;
				break;
			}
		}
	}
	if(exist[x]!=0)
		return color[x];
	else
		return 0;
	
}
map<int,map<int,int> > dp;

void dfsUTIL(int x)
{
	visited[x]=1;
	exist[x] = 1;
	rep(i,edges[x].size())
	{
		
		int y = dfsA(edges[x][i]);
	}
	
}
int dfs(int x,int y)
{
	if(dp[x][y])
	{
		return dp[x][y];
	}
	else
	{
		//leave node;
		dp[x][y]=1;
		rep(i,edges[y].size())
		{
			int t = edges[y][i];
			if(t!=x)
			{
				if(dfs(y,t)==-1)
				{
					dp[x][y]=-1;
					break;			
				}
				else 
				{
					if(color[y]!=color[t])	
					{
					
						dp[x][y]=-1;
						break;	
					}
				}	
			}
		}
		return dp[x][y];
	}
}
int main()
{
	int n;
	gi(n);
	rep(i,n-1)
	{
		int u,v;
		cin>>u>>v;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	rep(i,n)
	{
		cin>>color[i+1];
	}
	
	rep(i,n)
	{
		rep(j,edges[i+1].size())
		{
			dfs(i+1,edges[i+1][j]);
		}
	}
	int flag = 0;
	int ans =0;
	rep(i,n)
	{	
		int f =1;
		int x = i+1;	
		rep(j,edges[x].size())
		{
			int y  = edges[x][j];
			
			if(dp[x][y]!=1)
			{
				f = 0;
				break;
			}
			
		}
		if(f)
		{
			flag =1;
			ans = x;
		}
				
	}
	if(flag)
	{
		cout<<"YES"<<endl<<ans<<endl;
	}
	else
		cout<<"NO"<<endl;
	
}

