
 
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

int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
   }


unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}

int comp2(string a,string b)
{
	while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
	return a>b;
	
}
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;
		a = b;
		b = r;
	}
	return a;
}
double MR(double x)
{
	return x;
	x *=1000;
	x = round(x);
	x/=1000.0;
	return x;
}
 
int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int n;
		gi(n);
		double s[n],e[n],loss[n];
		map<double,int> mp;
		map<double,int> ::iterator it;
		double x,x1,y1,y;
		rep(i,n)
		{
			cin>>x1>>x>>y1>>y>>loss[i];;
			x = min(x1,y1);
			y = max(x1,y1);
			s[i]=x;
			e[i]=y;
			mp[s[i]]=1;
			mp[e[i]]=1;
		}
		cout<<mp.size()+1<<endl;
		it = mp.begin();
		
		double st =it->fs;
		it++; 
		printf("-inf %.3f 1.000\n",MR(st));
		for(	;it!=mp.end();it++)
		{	
			double end = it->fs;
			double intesity = 1.0;
			//cout<<end<<endl;
			rep(j,n)
			{
				
				if(s[j]<end &&end<=e[j] )
				{
				
						intesity*=loss[j];
				}	
			}
			printf("%.3f %.3f %.3f\n",MR(st),MR(end),MR(intesity));
			st  = end;
		}
		printf("%.3f +inf 1.000\n",MR(st));
		if(t)
			printf("\n");
	}
}


