
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
#define BL 24
using namespace std;
int gmask =0;

int dp[(1<<BL)+5];
map<int,int> mp;
int calc(int x)
{	
	return ((1<<BL) -1)^x;
}		
int get_hash(string x)
{
	
	int hashed=0;
	rep(i,x.size())
	{
		hashed|=1<<x[i]-'a';
	}
	return hashed;
}
int main()
{	
	
	int n;
	gi(n);
	//cout<<"here"<<endl;
	string s[n];
	int hash_val[n];
	
	rep(i,n)
	{	cin>>s[i];
		rep(j,s[i].size())
			mp[s[i][j]-'a']++;
		hash_val[i]=get_hash(s[i]);
		dp[hash_val[i]]++;
	}

	rep(i,BL)
	{
		if(mp[i])
			gmask|=1<<i;
	}
	for(int i=0;i<BL;i++)
	{
		for(int j =0;j<(1<<BL);j++)
		{
			if(j&(1<<i))
				dp[j]+=dp[j^(1<<i)];
		}	
	}
	ll ans =0ll;
	//cout<<gmask<<endl;	
	rep(i,1<<BL)
	{
		int y = ((1<<BL) -1)^i;
		ans^=(n-dp[y])*(n-dp[y])	;
	}
	cout<<ans<<endl;
	
	
}

