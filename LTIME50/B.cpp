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
int n,k;
map<int,map<int,int> > mp;
int arr[25];


bool isvalid(int x)
{
	int i =1;
	int ind =1;
	vector<int>v;
	int count=0;
	while(i<=x)
	{
		if(i&x)	
		{
			v.pb(ind);
			count++;
		}
		i<<=1;
		ind++;
	}
	int edge=0;
	rep(i,v.size())
	{
		forup(j,i,v.size())
		{
			int x = v[i];
			int y = v[j];
			if(mp[x][y])
			{
				edge++;	
			}
		}
	}
	if(edge==count-1)
	{
		set<int> s;
		rep(i,v.size())
		{
			s.insert(arr[v[i]]);
		}
		if(s.size()<=k)
		{
	//		cout<<x<<endl;
			return 1;
			
		}
		else
			return 0;
	}
	else
		return 0;
	
}
void solve(int c)
{
	gi(n);
	gi(k);
	//cout<<n<<k<<endl;

	rep(i,n)	
		gi(arr[i+1]);
	mp.clear();
	//	cout<<"sss"<<endl;

	for(int i=0;i<n-1;i++)
	{	int x,y;
		gi(x);
		gi(y);
		mp[x][y]=1;
		mp[y][x]=1;
	}
//	cout<<"sss"<<endl;
	int limit = 1<<n;
	int x =1;
	int ans=0;
	while(x<limit)
	{ 
		//if_subtreevalid_Tree
		ans += isvalid(x);
		x++;
	}
	cout<<"Case "<<c<<": "<<ans<<endl;
	
	
}
int main()
{   
    int t;
    gi(t);
   rep(i,t)
    {
    	solve(i+1);
	}
    
}
