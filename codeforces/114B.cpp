
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
#define printvi(x) rep(i,x.size()) pis(x) 
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

int main()
{	
	int n,m;
	gi(n);
	gi(m);
	
	map<string,int> mp;
	vector<int> v;
	vector<string>input;
	string s;
	string a,b;
	
	rep(i,n)
	{
		cin>>s;
		mp[s]=i;
		input.pb(s);
	}
	rep(i,m)
	{
		cin>>a>>b;
		int j = 0;
		j = j|(1<<mp[a]);
		j = j|(1<<mp[b]);
		v.pb(j);
	}
	int j =0;
	int lim = 1<<n;
	int mxans= -1;
	int mxcnt =0;
	rep(j,lim)
	{
		int x = j;
	//	cout<<x<<endl;
		int flag =1;
		rep(i,m)
		{
			if((v[i]&x)==v[i])
			{
				flag =0;
				break;		
			}
		}
		if(flag)
		{
			int cnt  = __builtin_popcount(x);
			if(cnt>mxcnt)
			{
				mxans= x;
				mxcnt = cnt;
			}
		}
		
	}
	cout<<mxcnt<<endl;
	vector<string> vans;
	int jj =0;
	while(mxans)
	{
		if(mxans&1)
		{
			vans.pb(input[jj]);
		}
		mxans>>=1;
		jj++;
	}
	sort(vans.begin(),vans.end());
	rep(i,vans.size())
	{
		cout<<vans[i]<<endl;
	}
}
